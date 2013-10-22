---
author: sudharsh
comments: true
date: 2008-06-05 12:39:23+00:00
layout: post
slug: battery-plugin-and-more
title: Battery Plugin and more..
wordpress_id: 114
categories:
- embedded
- FOSS and Linux
- freesmartphone.org
- gsoc
- linux
- Logs
- neo1973
- odeviced
- openmoko
tags:
- freerunner
- freesmartphone.org
- fso
- gsoc
- neo1973
- odeviced
---

After a little chat with [mickeyl](http://www.vanille-media.de/site/index.php/blog/), I realised that exposing crucial functions like load() and unload() was not that of a good idea considering how [odeviced](http://git.freesmartphone.org/?p=openmoko-gsoc2008.git;a=summary) is supposed to closely interact with the underlying devices. Consequently there has been some changes over the last week,



	
  * No DBus interface for the service.

	
  * Plugins have now access to a set of helper functions. Only two at the moment (Think setting up DBus object paths)

	
  * Plugins once loaded become resident, that is they cannot be unloaded. If plugins are to be disabled during startup, just remove them from the "enable" field in the global configuration file.

	
  * Per plugin configuration. Each plugins now have their own configuration. Makes more sense, since this mean plugins can have greater freedom with their settings. I really like how the newly checked in [battery plugin](http://git.freesmartphone.org/?p=openmoko-gsoc2008.git;a=tree;f=odeviced/plugins/backlight;h=cf890037a9a39f4a801ea9e5984c40af8440fa03;hb=e21a88cf6a35d9ef43a3d0836be26bdae733d670) exploits this.

	
  * Freshly checked in battery plugin. Makes use of sysfs for its functions viz. get_current_brightness, set_brightness, get_maximum_brightness.


[SysFS](http://en.wikipedia.org/wiki/Sysfs) (/sys in 2.6.x.x) is sort of similar to the /proc filesystem and acts as an interface for user-space applications to control/access various devices. One of the neat things about sysfs is the fact that all files consist of only a **single** entry. This means I don't have to write a separate parser to extract data from them. So a simple fprintf or fscanf or even the seemingly mundane "echo" can be used to control the devices.

I am also planning to work on the python shell for odeviced for a while. This will be really convenient for testing the service. Something like this,

`> Wifi is_on wlan0
True
`

The code can be checked out from [here](http://git.freesmartphone.org/?p=openmoko-gsoc2008.git;a=summary). I can't wait till I get hold of a FreeRunner to test odeviced out. :)
