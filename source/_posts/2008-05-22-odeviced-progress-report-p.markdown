---
author: sudharsh
comments: true
date: 2008-05-22 11:18:53+00:00
layout: post
slug: odeviced-progress-report-p
title: 'odeviced: progress report :P'
wordpress_id: 108
categories:
- embedded
- FOSS and Linux
- freesmartphone.org
- gsoc
- linux
- neo1973
- odeviced
- openmoko
tags:
- freesmartphone
- freesmartphone.org
- fso
- gsoc
- linux
- neo1973
- odeviced
- openmoko
---

So, presenting a preliminary skeleton service for odeviced that loads shared object libraries (or in other words plugins). Nothing to be proud of, but hey, something is better than nothing.

Here's a screenshot of a very very preliminary odeviced in action..

[![odeviced](http://sudharsh.unixpod.com/Screenshot.png)](http://sudharsh.unixpod.com/Screenshot.png)

Basically its just a dbus service that can load modules from a predefined location. Here's how it works currently,



	
  * Setup all the boring stuff like registering the object path and getting the connection to the DBus system bus. The interface used will be "org.freesmartphone.Device".

	
  * The service reads the configuration file at /etc/odeviced.conf whose contents are as follows,`  
# General configurations
[odeviced]
device_name=FreeRunner`
`[powercontrol]
enable=1`

	
  * So from the above configuration, the device name is set to FreeRunner and odeviced tries to load the powercontrol plugin since "enable" is set to 1. Of course, the dbus service exposes the load method to load plugins manually after the service has started if the need arises.

	
  * The default directory for plugins is at '/usr/share/odeviced/plugins'. Maybe additional directories for other plugins can be set in odeviced.conf. By now odeviced tries to load the plugin libpowercontrol.so under '/usr/share/odeviced/plugins'.

	
  * After successful loading of the plugin, odeviced executes the init function in the plugin which is of the form <plugin_name>_init. In our case it is powercontrol_init. The dbus paths for the plugins are to be set here. So we would have object paths such as "/org/freesmartphone/Device/plugins/powercontrol'. This is yet to be done.

	
  * As evident in the above screenshot the powercontrol_init contains a single printf statement which merely spits out "In powercontrol". And yes, the powercontrol plugin is written in good ol' C.


Notice the gnome-terminal at the right. It is running a simple python helper script for testing odeviced. It simply reads from stdin and calls the `load' method offered by the dbus service with the input as the argument. As you can see, powercontrol has been loaded successfully but "l" and "this_aint_a_plugin" gives a critical warning that these plugins couldn't be found.

_What needs to be done_



	
  * Make the code "beautiful". :D. I am constantly on the lookout for vala'ish ways of doing things. Still need to work on my OOP skills :/.

	
  * Come up with a decent plugin for powercontrol.

	
  * Put in some example apps or port the existing OM ones to use odeviced.


