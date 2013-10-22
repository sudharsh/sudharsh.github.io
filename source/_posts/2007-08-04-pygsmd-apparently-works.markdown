---
author: sudharsh
comments: true
date: 2007-08-04 12:08:37+00:00
layout: post
slug: pygsmd-apparently-works
title: 'pygsmd: Apparently, works!'
wordpress_id: 68
categories:
- openmoko
- Python
---

pygsmd wrapping up libgsmd seems to work, Don't get the "Couldn't connect to gsmd warning" now. Instead, getting "Busy line" as is evident from the screenshot. Best of all, I could ssh into the neo (of course which runs on qemu). So hacking has been a bit easy  since  I can use my keyboard properly without using the slow onscreen keyboard on the neo. Waiting for the neo to arrive to see if it works on the device. Only the voicecall part of libgsmd has been written, that too its quite clunky. Check out the emacs window showing that an attempt has been made to connect to the gsm daemon and note the terminal in the foreground with the output of uname after ssh'ing

{% img center http://sudharsh.files.wordpress.com/2007/08/screenshot.png %}

.
