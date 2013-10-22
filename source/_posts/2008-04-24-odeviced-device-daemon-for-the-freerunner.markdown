---
author: sudharsh
comments: true
date: 2008-04-24 13:26
layout: post
slug: odeviced-device-daemon-for-the-freerunner
title: 'odeviced: Device daemon for the FreeRunner'
wordpress_id: 104
categories:
- embedded
- FOSS and Linux
- gsoc
- linux
- neo1973
- odeviced
- openmoko
- Rants
tags:
- Add new tag
- FOSS
- freerunner
- google
- gsoc
- linux
- neo1973
- odeviced
- openmoko
---

Man, its quite difficult to sneak up and write a blog post when semesters are around the corner. So as mentioned in the last post, my project for this summer would be to write a device daemon for the Openmoko platform. We already have neod offering keypad and power management, but its not that elegant. Hence I proposed a DBUS replacement as a SoC project which got through.

So, heres a [pdf](http://sudharsh.unixpod.com/googsoc.pdf) of the proposed *ahem* architecture. (Boy, I love that word. Sounds enterprisey). it looks a bit sucky since I did it using a touchpad, but hey, something is better than nothing.

I was looking at pulseaudio code for a while and liked it pretty much. So naturally, odeviced will borrow ideas from pulseaudio a bit heavily. My idea of odeviced is as follows,



	
  * A dbus service with support for loadable plugins.

	
  * These plugins can be arbitrary, from managing power, gps to controlling the uber secret laser katana in the FreeRunner (oops. I let the secret out)

	
  * And of course, some user space applications may want to know whats going on under the hood. So expose some sort of api from the dbus service.


Initially for the SoC, I will be working for full odeviced support for the FreeRunner, and maybe later on write plugins for other devices as well. Especially for the ones from Motorola.

For the implementation, here are the things I need to learn over the next month

	
  * Vala, its a cool language built around GLib.

	
  * DBUS, My experience with dbus is now limited to the tutorial code

	
  * Prolly some HAL and udev and touch upon the kernel stuff if need arises



	
  * ...and *cough* to manage my time and write good code...


Heres the [abstract](http://code.google.com/soc/2008/openmoko/appinfo.html?csaid=C4E490026007DA79) of my proposal. Thanks to [tuxmaniac](http://tuxmaniac.com), [Casanova](http://prashblog.com), [techno_freak](http://technofreakatchennai.wordpress.com), [tuxplorer](http://www.raja-gopal.com/), [pygi](http://pygi.wordpress.com/) and many more for proofreading my proposal which at the beginning looked like a love letter written by a 5 year old.
