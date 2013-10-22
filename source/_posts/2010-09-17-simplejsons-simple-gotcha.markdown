---
author: sudharsh
comments: true
date: 2010-09-17 18:30:17+00:00
layout: post
slug: simplejsons-simple-gotcha
title: simplejson's simple gotcha
wordpress_id: 370
categories:
- programming
- Rants
- Tips
tags:
- caveat
- gotcha
- json
- Python
- simplejson
- Tips
---

I like simple things. Anything more complex more than 'simple' is tough to deal with. Therefore it comes as no surprise that I love JSON. Heck, the entire grammar fits in a business card.

{% img center http://farm3.static.flickr.com/2551/3763158824_e2f57810c4.jpg %}

If you take a closer look at the spec above, you will notice that the keys for a JSON 'dictionary' should be strings. I have a feeling that programmers like me whose language-of-mass-destruction is python are likely to overlook this minor gotcha.

This is where it gets interesting. Python's json module tries to do something smart when you try to encode a python dictionary into a JSON string. In this case, all the keys are python ints.

``` 
In [3]: json.dumps({ 1 : 'Foo', 3: 'Baz'})
Out[3]: '{"1": "Foo", "3": "Baz"}'
```

When I decode it back to a python object...

``` 
In [4]: json.loads(json.dumps({ 1 : 'Foo', 3: 'Baz'}))
Out[4]: {u'1': u'Foo', u'3': u'Baz'}
```

BAM! The json module silently converts all my integer keys to strings. I, for one, would have preferred an Exception to be raised instead.

Something like this, for example.
``` 
In [19]: class F: pass
...
In [20]: f = F()
In [21]: json.loads(json.dumps({ f : 'Foo', 3: 'Baz'}))
... snip errors ...
TypeError: key <__main__.F instance at 0x92b4b2c> is not a string
```

In this case, I get the desired behaviour where a 'TypeError' is raised. Stupid example, but you get the idea.

If I am missing something obvious here please do comment. This particular cheekiness of the json module caught me unawares recently. Or maybe I was wrong in expecting the decode operation to return something that is identical to the source.

Interestingly, the json support modules that ship with TurboGears error out if you try to return a dictionary having non-string keys from your controller methods. 
