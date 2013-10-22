---
author: sudharsh
comments: true
date: 2008-05-29 17:58:56+00:00
layout: post
slug: first-frigging-milestone
title: First frigging milestone..
wordpress_id: 111
categories:
- bleh
- embedded
- FOSS and Linux
- freesmartphone.org
- gsoc
- linux
- neo1973
- odeviced
- openmoko
- Rants
tags:
- embedded
- freerunner
- freesmartphone
- freesmartphone.org
- fso
- gsoc
- linux
- mobile
- odeviced
- openmoko
---

Why Milestone? Nope, I didn't come up with fancy code or a "beautiful" one for that matter (Came up with a way to unload plugins). Milestone, because today was the first day I was squeezing up my half empty head to work around a teency weency problem. In short, I am happy I was actually **thinking** today about squishing a segmentation fault which was bringing the whole house down due to dbus and the kinky wifi plugin.

Now a word of warning. The wifi plugin is a circus freak of sorts. Being the lazy bum I am, I found it a drag to manually get into the trouble of coming up with xml introspection data for the "org.freesmartphone.Device.plugins.wifi" interface.

Instead I just came up with a grand plan of letting _valac_ generate wifi.c and wifi.h, which I could modify later. Piece of cake? Sure...

After the wifi plugin is loaded it works pretty well. The keyword being "After"...By the way, check the [progress report](http://projects.linuxtogo.org/pipermail/smartphones-standards/2008-May/000078.html) which I sent to the [smartphone-standards](http://projects.linuxtogo.org/pipermail/smartphones-standards/) list. That should give you an idea of how odeviced works and looks like. In fact, it works pretty satisfactorily discounting the segmentation faults :D, which is **easily **reproducible in the following ways,



	
  * Don't load the wifi plugin on startup, set enable=0 in odeviced.conf. Instead load it manually after odeviced starts up and begins to idle.

	
  * If the wifi plugin is already loaded, unload it and then try to load it again.


Part of this problem might be my arrogance of not to use GTypeModules for dynamically typing the plugins. I need to discuss with my mentor, mickeyl about this once he gets back to business after [LinuxTag](http://www.linuxtag.org/2008/en/).

The barely bare bones powercontrol plugin loads and unloads without any problems, but it doesn't do anything as remotely useful as the wifi plugin!! Just contains an init function that has a printf in it (bleh!, thank goodness it didn't bail out).

Oh and the all important [tarball](http://sudharsh.unixpod.com/odeviced-20080529.tar.bz2) is here. Highly effective than laughing gas!

...Another gdb session beckons
