---
author: sudharsh
comments: true
date: 2008-04-06 19:29
layout: post
slug: the-fat-penguin-on-sony-vaio-cr
title: The fat penguin on Sony Vaio CR
wordpress_id: 102
categories:
- FOSS and Linux
- linux
- Logs
- Rants
- Tips
tags:
- gentoo
- gentoo64
- hardy
- laptop
- sony
- Tips
---

As I said in my earlier post, Vista didn't last long. I was planning to install Gentoo in my Vaio CR 36 but couldnt, as it had problems with the ethernet card ( not to mention the wireless). My option was to install Ubuntu Gutsy as it has very good support for laptops out of the box. But Gutsy couldn't get sound working and hence found a perfect excuse to upgrade to hardy beta.

24 after upgrading to hardy, came to know that beta_1 of gentoo 2008.0 is out. Downloaded the 64 bit mrinimal iso and got it up and running on my laptop. Things that doesn't work in both the distros (as of now. May change as I RTFM more)..



	
  * Fn keys for the brightness controls. I have a brightness applet in my panel, so no real big deal.

	
  * The Ricoh webcam. lsusb picks up the device and whats more strange; the [r5u870](http://wiki.mediati.org/R5u870) driver gets loaded and the device node '/dev/video0' is getting created properly. Neither cheese nor camorama could pick up the camera. The device id is "05ca:1839", which seems to be well supported. Maybe I am missing something obvious (yes, the firmware files are in place)

	
  * The fingerprint reader. Its the same as that of the ones from the Thinkpads but thinkfinger doesn't support vaios :S

	
  * Bluetooth, gets detected by hciconfig but other devices can't see my laptop. (See below)


If anyone had any luck with the above, please let me know.

What works..

	
  * DRI with the binary 'fglrx'



	
  * Sound works well



	
  * Wireless pwns with the iwl4965 module

	
  * Ethernet with the realtek modules

	
  * [Software suspend to disk (and RAM)](http://www.gentoo-wiki.com/HOWTO_TuxOnIce) using patches from the TuxOnIce project

	
  * Volume keys and media keys work like a charm.

	
  * Adobe doesn't offer support for flash on amd64. You can getaway with it by installing a 32 bit firefox binary alongside your 64 bit installation. 'emerge mozilla-firefox-bin netscape-flash' and you are all set.

	
  * Bluetooth works beautifully. I have had issues with I/O errors with the chipset. But a post to the gentoo forums solved the issue. This VAIO comes with a Broadcom 2046 chipset. Be sure to 'emerge bluez-firmware' just in case. Click [here](http://forums.gentoo.org/viewtopic-t-687593.html) for the thread. Be sure to follow the wonderful [gentoo bluetooth](http://www.gentoo.org/doc/en/bluetooth-guide.xml) guide. emerge gnome-phone-manager and gnome-bluetooth for extra fun


The kernel .config and the xorg.conf with hardware acceleration for my laptop is [here](http://sudharsh.unixpod.com/gentoofoo), in case if anyone is interested.

Gentoo-wiki has been a great resource. Information about other vaios [here](http://www.gentoo-wiki.com/Special:Search?search=sony+vaio&go=Go).
