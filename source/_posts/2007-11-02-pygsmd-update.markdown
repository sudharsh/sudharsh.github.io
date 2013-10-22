---
author: sudharsh
comments: true
date: 2007-11-02 10:02
layout: post
slug: pygsmd-update
title: 'pygsmd: update'
wordpress_id: 82
categories:
- embedded
- FOSS and Linux
- linux
- Logs
- neo1973
- openmoko
- Python
tags:
- Logs
- neo1973
- openmoko
- Python
- python-gsmd
- python-openmoko
- screenshot
- threads
---

Semesters are start in 10 days, so hardly had the time to hack on pygsmd. I had to implement [multithreading](http://www.yolinux.com/TUTORIALS/LinuxTutorialPosixThreads.html) for the first time in my life and that was real fun. But I had to cope up with a stupid race condition which fortunately has been fixed after gdb put things in perspective. [Phonesim](http://unadventure.wordpress.com/2007/10/28/qpe-430-plus-qemu/) has been really useful this time, Now I can thoroughly check my code if it works on my desktop before creating premature borky packages. Anyways messages are getting handled now, after borrowing some code from libgsmd-tool. As a result functions like pygsmd.network.get_oper() return correctly. So now I can turn my attention to sms now. As always please please check the code out, and if you find some glitches report bugs that may be present aplenty.

Heres a screenshot of the latest revision 76 in action, Note that loads have changed internally since the last one.

{% img center http://sudharsh.files.wordpress.com/2007/11/screenshot.png?w=512 %}

