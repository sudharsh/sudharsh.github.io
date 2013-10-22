---
author: sudharsh
comments: true
date: 2006-11-26 17:53:31+00:00
layout: post
slug: glade-3-and-libglade
title: Glade 3 and libglade
wordpress_id: 39
categories:
- FOSS and Linux
- Tips
---

I use glade to design UI for my project. So one day when I came to know that Glade3 has been released (rather late, actually) I decided to give it a shot. Glade 3 has its UI cranked so that you can efficiently create UI for your project..:|.. Anyway I dont know if it is just me but Glade 3 is slower than its predecessor and also crashed once in a while, especially when I was working with the design of the menu structure. On a happier note though, the crappy source code generation "feature" has been completely removed.. Yup...Glade2 had this feature wherein you could generate all the callback code..(That gave me nightmares..)

So with Glade, it is recommended to use libglade (and out of my own experience) to load the glade file during program execution. This has some advantages from the code generation.. First you carry less source code and somehow I felt it made my program clean. Secondly you dont have to recompile the entire project when you make changes to the UI. This is because the code generation in glade creates a separate source file called interface.c where all the UI code gets in by default as though you have hand coded them. But with libglade that doesnt exist since glade xml gets loaded during runtime kinda like in PyGTk if you know it.

Oh..and if you get the warning like
`libglade-WARNING: couldn't find the signal handler "some_signal_handler"`
This is because libglade couldnt find the symbols properly. Just add the "--export-dynamic" flag while compiling and you are done.

**References:**
[Glade UI Builder](http://glade.gnome.org/)
[libglade](http://www.jamesh.id.au/software/libglade/)
