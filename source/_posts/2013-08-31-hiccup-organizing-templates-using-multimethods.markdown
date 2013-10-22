---
author: sudharsh
comments: true
date: 2013-08-31 14:44
layout: post
slug: hiccup-organizing-templates-using-multimethods
title: 'Hiccup: Organizing templates using multimethods'
wordpress_id: 540
categories:
- Clojure
- Logs
- Python
tags:
- clojure
- enlive
- flask
- hiccup
- jinja
- programming
- template
- web
---

There are two major templating libraries for Clojure,[ Enlive](https://github.com/cgrand/enlive) and [Hiccup](https://github.com/weavejester/hiccup). Since I am not that much of a designer, I chose Hiccup for my side project written in Clojure. I liked the DSL's unification of code and templating; right in my comfort zone. This post is a little log on how I ended up using [multimethods](http://clojure.org/multimethods) for organizing my Hiccup template functions.


## DRY in Jinja




In my previous [Flask](http://jinja.pocoo.org/docs/templates/) projects, [Jinja](http://jinja.pocoo.org/docs/templates/) was my templating engine of choice. The [DRY](http://en.wikipedia.org/wiki/Don't_repeat_yourself) flow in Jinja templates consists of setting up a `base.html` with a common layout markup. The 'children' would then ['inherit'](http://jinja.pocoo.org/docs/templates/#template-inheritance) and optionally override those blocks in their own templates.





## Composition in Hiccup




However, In the world of Clojure (and therefore Hiccup), functions (duh!) are used to modularize templates.  For example,

``` clojure
(ns foobar.views
  (:require [hiccup.core :as h]
            [hiccup.page :as hp]))

(defn head [title]
  [:head
   [:title title]
   (hp/include-css "/static/css/bootstrap.min.css"
                   "/static/css/bootstrap-theme.min.css")
   (hp/include-js "/static/js/jquery-1.10.2.min.js"
                  "/static/js/bootstrap.min.js"
                  "/static/js/bluth.js")])

(defn get-page [title context]
  (hp/html5
    ;; Since hiccup DSL is just code, we will just inject the
    ;; <head> right here
    (head title)
    ;; Rest of the template
    ;; I'd probably have a (body..) somewhere
    (body context)
    ;; Rest of the template
))
```






## Multi-methods


In the above example, there is a chance of repetitiveness of functions like `get-page` as the number of routes increases. In most cases, there is one (or few) container `div` that changes across the templates. To avoid this, I have found using [`multimethods`](http://clojure.org/multimethods) to be a great way of dispatching templates at runtime.

For instance,


``` clojure

(defmulti container :template :default :not-found)

(defmethod container :home [context]
 [:h2 "Welcome to the Bluth Company"]
 [:button#queue-button.btn.btn-info "Backup"])

(defmethod container :users [{:keys [query-params]}]
 [:h2 (str query-params)])

(defmethod container :not-found [context]
 [:h2 "Generic Content"])

```




Now that I have a group of 'container' divs, I can invoke them from `get-page` like so,


``` clojure

(defn get-page [{:keys [title]
             :or {title "Bluth Co. - Welcome"}
             :as context }]
  (hp/html5
   (head title)
   [:body
    [:div#wrap
     [:div.container
      ;; Invoke container here
      ;; and dispatch the right template function
      (container context)
      ]]]))

```




Meanwhile, my `routes` will end up looking something like this,


``` clojure
(defroutes app-routes
  (GET "/" [] (get-page { :template :home }))
  ;; Due to the destructuring in get-page,
  ;; I can pass in arbitrary context to be handled by
  ;; the container multimethods. In this case, we
  ;; are passing in the query-params
  (GET "/users" [& query-params] (get-page
                                       {:title "User list"
                                        :template :users
                                        :query-params query-params}))
  (route/not-found (get-page
                    {:title "Pluto - Not found!"
                     :template :not-found}))
```




As you can see, `get-page` is the point of entry for my templates and the container `div` is injected according to the dispatched function. In fact, by abusing using [compojure's](https://github.com/weavejester/compojure/wiki/Destructuring-Syntax) route destructuring, we can have true runtime dispatching of templates!


``` clojure
(defroutes app-routes
  (GET "/foo/:template [template]
     ;; We don't know which container will be invoked until runtime
     ;; Instead of adding more routes, I can just add more multimethods
     (get-page {:template template})))
```




`get-page` function isn't going to change much and I can mix and match templates as much as I want.

I must admit that I am super new to Clojure. Therefore I am not sure if this approach is idiomatic enough in the Clojure world. Would love to hear suggestions on how it is usually done.
