---
author: sudharsh
comments: true
date: 2007-10-14 06:35
layout: post
slug: python-gsmd-progress-so-far
title: python-gsmd, progress so far..
wordpress_id: 77
categories:
- embedded
- FOSS and Linux
- neo1973
- openmoko
- Python
tags:
- embedded
- gsmd
- libgsmd
- neo
- neo1973
- openmoko
- Python
- python-gsmd
- python-openmoko
---

Tada...

So the python-gsmd bindings for the gsm daemon in Openmoko works!! Checkout the screenshot. I had ssh'ed into the phone after setting up USB networking so that I might get a shell to work on.

Note the uname on the lower right terminal showing the ARM architecture of the neo.

The terminal on the lower left shows the logs from the libgsmd-tool shell.

And in the terminal on the top, we have a python session leading to a call to my good ol' mom.

{% img center http://sudharsh.files.wordpress.com/2007/10/screenshot.png %}

Now that the code sorta works, I have moved it to the projects.openmoko.org. [Click here](http://projects.openmoko.org/plugins/scmsvn/viewcvs.php/?root=python-openmoko) to browse the source. Note that theres another project by zecke which wraps up mickeyl's libmokogsmd. Ours wraps up gsmd directly and creates a sort of raw interface to the daemon.

Too bad semester will be starting soon,  so work will be a bit slow. So please please please ping us if you want to help.

P.S: The screenshot is from the gentoo livecd...=D
