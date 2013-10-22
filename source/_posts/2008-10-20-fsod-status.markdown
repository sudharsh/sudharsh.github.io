---
author: sudharsh
comments: true
date: 2008-10-20 17:37
layout: post
slug: fsod-status
title: fsod status
wordpress_id: 157
categories:
- embedded
- FOSS and Linux
- freesmartphone.org
- linux
- Logs
- neo1973
- odeviced
- openmoko
tags:
- FOSS
- freerunner
- freesmartphone.org
- fso
- fsod
- linux
- neo1973
- odeviced
- openmoko
- Python
- vala
---

Its been a while since I blogged about odeviced. In my earlier posts I had mentioned the possibility of integrating odeviced and others (which do not exist at the moment) into a single daemon for avoiding too much fracture. I have pushed some code that does this, converting odeviced into a Device subsystem that is loaded by a master daemon called fsod. This, of course is very similar to the python implementation ([frameworkd](http://git.freesmartphone.org/?p=framework.git;a=summary)) which is pretty awesome at what it does and has become a sort of success story for using DBus as the fudgy layer separating toolkits and the underlying systems which in themselves are tightly coupled.

The current code base is written in [vala](http://live.gnome.org/Vala) (and C where it is required) which unfortunately lacks certain features of [DBus](http://dbus.freedesktop.org/) like async callbacks and some method signatures at the moment (I may be horribly wrong. I would be glad if someone points out in that case. The mailing list discussion on async support [here](http://mail.gnome.org/archives/vala-list/2008-October/msg00057.html)). But at the same time, writing GObject code in vala is infinitely easier and lots of fun too :D.

It would be also be pretty awesome if fsod could support loading python plugins, kind of like what gedit does. The GSM code especially could benefit from this since there is not much to gain in terms of performance here.

As for fsod, the sources are available [here](http://git.freesmartphone.org/?p=openmoko-gsoc2008.git;a=summary). In case anyone wants to get hold of a opk of the current code to install on the Freerunner, it is available [here](http://sudharsh.mukt.in/fsod-preview_armv4t.opk). Comments are welcome
