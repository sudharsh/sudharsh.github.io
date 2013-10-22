---
author: sudharsh
comments: true
date: 2007-06-13 17:06:36+00:00
layout: post
slug: wrapping-up-libgsmd
title: Wrapping up libgsmd
wordpress_id: 59
categories:
- FOSS and Linux
- Life
- openmoko
- Python
---

So, Got myselves busy with [Openmoko](http://www.openmoko.org). Time will tell, if I would be able to get hold of the first device (neo1973) based on the platform. Anyway me and empty_mind had decided to bring our favourite programming, python to the platform. Of course [OpenEmbedded](http://www.openembedded.org), on which OpenMoko is based already provides python, but this time we are into customising the big snake for the Openmoko platform by writing language bindings, optimising runtimes. etc..No doubt fun times ahead.

I have even come up with an extension module that wraps up the Voice Out function of libgsmd. It works on my box but the damn thing isnt getting installed in the final image although it build just fine, so I couldnt really test it out if it works in the device (no..not the real device just the qemu stuff).

Have filed a bug report on this, hopefully it should be fixed.

*Sigh*, heres the screenshot of the error in qemu.

{% img center http://sudharsh.files.wordpress.com/2007/06/openmoko.png?w=512 %}

**Links:**

Dadu's (empty_mind's) blog:[ http://www.vivekkhurana.com/pymoko/](http://http://www.vivekkhurana.com/pymoko/)
The neo1973 phone :  [http://rene.rebe.name/photos/?p=/Computex/2007/img_2208.jpg](http://rene.rebe.name/photos/?p=/Computex/2007/img_2208.jpg)

Oh gawd, I Promise I will be good..Just send me one of those gadgets to hack and drool on..
