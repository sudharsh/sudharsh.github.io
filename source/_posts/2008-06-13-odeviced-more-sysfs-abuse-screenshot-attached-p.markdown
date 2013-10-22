---
author: sudharsh
comments: true
date: 2008-06-13 16:36
layout: post
slug: odeviced-more-sysfs-abuse-screenshot-attached-p
title: 'odeviced: More sysfs abuse (Screenshot attached! :P)'
wordpress_id: 119
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
- dbus
- freerunner
- freesmartphone
- freesmartphone.org
- fso
- gsoc
- neo1973
- odeviced
- openmoko
---

A few days gone by, and endless wrestling with git wherein I was not able to push code. Turned out, I was using the wrong URL to push ..doh!

But anyway, the [code](http://git.freesmartphone.org/?p=openmoko-gsoc2008.git;a=summary) is beginning to stabilise a bit (Read no unexpected segfaults, only expected ones..). The last few days were spent in changing the method names in accordance with OTAPI naming conventions after my mentor went through my code.

There is also another important change. The sysfs nodes for backlight and power plugins were hardcoded in their configuration files. So, I came up with some helpers that creates DBus paths automatically based on the device class which they belong to. Here's a picture of today's code in action,

[{% img center http://sudharsh.files.wordpress.com/2008/06/screenshot1.png?w=512 %}](http://sudharsh.files.wordpress.com/2008/06/screenshot1.png)

Notice the [d-feet DBus](https://hosted.fedoraproject.org/projects/d-feet/) debugger towards the lower left? It shows all the automatically created DBus object paths based on the device class which the plugin stands for. And the terminal to the right shows some debug messages. Note how odeviced spits out the current battery status viz. "Charging, Discharging". The corresponding "battery-status-changed" DBus signal is emitted as well (along with "low-battery-warning" signal which *ahem* is emitted when battery is low).

For more follow this [thread](http://lists.openmoko.org/pipermail/openmoko-devel/2008-June/003002.html)..
