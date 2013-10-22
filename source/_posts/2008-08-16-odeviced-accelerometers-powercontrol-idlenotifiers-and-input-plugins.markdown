---
author: sudharsh
comments: true
date: 2008-08-16 17:02:22+00:00
layout: post
slug: odeviced-accelerometers-powercontrol-idlenotifiers-and-input-plugins
title: 'odeviced: Accelerometers, PowerControl, IdleNotifiers and Input plugins'
wordpress_id: 145
categories:
- embedded
- FOSS and Linux
- freesmartphone.org
- gsoc
- linux
- neo1973
- openmoko
tags:
- freerunner
- freesmartphone
- freesmartphone.org
- fso
- gsoc
- neo1973
- odeviced
- openmoko
- vala
---

[![](http://sudharsh.files.wordpress.com/2008/08/screenshot-1.png)](http://sudharsh.files.wordpress.com/2008/08/screenshot-1.png)Phew. GSoC 2008 program is going to end in a couple of days and boy, did I have fun. Most of the code for the second phase was actually pushed last week. Anyway, here are the updates.



	
  * Accelerometer plugin for Freerunner. Now you can use odeviced to retrieve accelerometer values for the position of the device along the x,y,z axes.

	
  * Completed Powercontrol plugin. Kept putting this off, but got myself to complete it today.

	
  * IdleNotifiers enabling apps to keep track of the state of the device viz. IDLE, BUSY...etc

	
  * Input plugin for signalling input events on DBus. Like button presses, etc. Should make this asynchrounous once vala offers support for async DBus on the server side ('read' systemcall can block)

	
  * Initial Audio plugin, am keeping this as a TODO outside GSoC.


The daemon is far from complete and GSoC was meant to be just the beginning to get the basics right. Integration of odeviced as a subsytem of a frameworkd implementation (theres already a python implementation) in C is something I am looking forward to contribute in the next few months. It would be uber cool, if someone lends a helping hand for now to make odeviced work on other devices on which openmoko (and FSO) can run.

I am not sure if people will find this interesting, but still

	
  * The plugins average around 14kB in size, with powercontrol being the biggest of all. (25KB)

	
  * The main odeviced binary is around 26KB, which IMO, is quite teency weency.


(But given the fact that the code links against GLib and DBus, I have no idea if these numbers mean anything at all. I would be grateful if anyone thinks this is something to cheer about)

P.S: I am looking for a temporary place to host the ipks for the lazy ones, will post the link once I get that. Meanwhile, get the code [here](http://git.freesmartphone.org/?p=openmoko-gsoc2008.git;a=summary).
