---
author: sudharsh
comments: true
date: 2007-12-26 21:01
layout: post
slug: smshackhow-not-to-design-guis
title: SMSHack...how not to design GUIs
wordpress_id: 90
categories:
- embedded
- FOSS and Linux
- linux
- Logs
- neo1973
- openmoko
- Python
tags:
- FOSS and Linux
- libgsmd
- linux
- neo
- neo1973
- openmoko
- pygsmd
- pymoko
- python-openmoko
- screenshot
---

I got to test some code in the neo and found that sms sending using pygsmd works quite well!!..Also I was looking for an opportunity to brush up my 2 hour stint with pyGTK which I had a long long time ago. What better reason than to create a dirty, scrawny, crufty, fugly GUI for sending SMS. Heres a screenshot of the GUI in action taken from the neo itself. It doesnt really follow any GUI guidelines (who would care at 2:30 AM)...When you click SendSMS, it calls pygsmd.sms.send() and sends your message..and when you click Quit button, the obvious thing happens.

{% img center http://sudharsh.files.wordpress.com/2007/12/screenshot-1.png %}

Oh there is also this another more better looking tool called [SMSTool](http://wiki.openmoko.org/wiki/SMSTool) by alessandro, you might want to check that out as well if you want, it achieves its purpose in a weird sort of interesting way. It communicates with libgsmd-tool in shell mode through python subprocesses.

If anyone is willing to modify the GUI and make it look more humane, be my guest..It ofcourse depends on pygtk and its dependencies

P.S: SVN in projects.openmoko.org seems to be down. So I was not able to commit these example scripts.

Goofup: I did it again..The SMSTool is written by [kriss](http://mput.de/blog/) and maintaned by alessandro
