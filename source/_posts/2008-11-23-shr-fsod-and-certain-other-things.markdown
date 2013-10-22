---
author: sudharsh
comments: true
date: 2008-11-23 06:58:55+00:00
layout: post
slug: shr-fsod-and-certain-other-things
title: SHR, fsod and certain other things.
wordpress_id: 161
categories:
- FOSS and Linux
- freesmartphone.org
- linux
- neo1973
- openmoko
- Python
tags:
- chitlapakkam
- freerunner
- freesmartphone
- freesmartphone.org
- fso
- fsod
- neo1973
- openmoko
- openstreetmap
- osm
- tambaram
---

[SHR](http://wiki.openmoko.org/wiki/SHR) (Stable Hybrid Release) released images recently and boy, did they do an awesome job at it. By far, SHR and Debian are some of the images that uses the [FSO daemons](http://git.freesmartphone.org/) by default. So turns out to be a great testing ground for the FSO APIs. And after a long while, I also got some time to play with my Freerunner. Here is a screenshot of TangoGPS in action.

[![screenshot-11](http://sudharsh.files.wordpress.com/2008/11/screenshot-11.png?w=225)](http://sudharsh.files.wordpress.com/2008/11/screenshot-11.png)Hmm..Someone seems to have mapped Chitlapakkam and East Tambaram a bit for [OSM](http://openstreetmap.org/). Wondering who that is. :)

As for fsod, I could really use some help especially with autotools. I managed to set up a preliminary a python scripting interface so that fsod can load python scripts. But that's as far as I got. Apparently DBus needs a mainloop to be setup for exporting objects on the system bus. And since GObject introspection in python seems to be absent at the moment, I had to create bindings to my code. This process is documented and explained [here](http://www.ibm.com/developerworks/linux/library/l-wrap/). But still, I am at a loss as to how to pass the DBus connection object from the mainloop to the python scripts. If someone knows how to do this, please poke me.

The code could be found [here](http://git.freesmartphone.org/?p=openmoko-gsoc2008.git;a=summary). (src/subsystems/Python especially can use some love)

Update: I made a package out of today's tree. Find it [here](http://sudharsh.mukt.in/fsod_0.1-r0_armv4t.opk).
