---
layout: post
title: Getting IP of an interface in Clojure
date: 2013-12-05 00:56
comments: true
categories:
- Clojure
- Programming
tags:
- clojure
- snippets
- programming
- java
---

Here's a rather crude way in clojure to get the IP of the current host given a network interface

``` clojure
(defn ip-for-interface [interface]
  (first (->> (java.net.NetworkInterface/getByName interface)
              .getInetAddresses
              enumeration-seq
              (filter #(instance? java.net.Inet4Address %1))
              (map #(.getHostAddress %1)))))
```

Of course, fails horribly with an `NullPointerException` if the interface is not present :)
