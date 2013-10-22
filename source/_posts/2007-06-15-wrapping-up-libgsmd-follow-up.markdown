---
author: sudharsh
comments: true
date: 2007-06-15 07:51:19+00:00
layout: post
slug: wrapping-up-libgsmd-follow-up
title: Wrapping up libgsmd (Follow up)
wordpress_id: 61
categories:
- FOSS and Linux
- openmoko
- Python
---

w00t, pymoko runs in the qemu. The shared object extension got installed after building the openmoko toolchain from scratch. It did take me a whole day, but at the end it was frigging worth it. Thanks to stefan for pointing me to the solution. Now its party time.

Heres the screenshot where I import the pymoko module, show the available functions by doing a 'dir(pymoko)', and try to call my number (which obviously wont work) with voice_out_init().

The function call is unsuccessful because the gsm daemon doesnt appear to be running.

[![works](http://sudharsh.files.wordpress.com/2007/06/screenshot-1.thumbnail.png)](http://sudharsh.files.wordpress.com/2007/06/screenshot-1.png)
