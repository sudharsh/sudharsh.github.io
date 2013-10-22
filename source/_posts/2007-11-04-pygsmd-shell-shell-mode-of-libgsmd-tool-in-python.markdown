---
author: sudharsh
comments: true
date: 2007-11-04 17:59:45+00:00
layout: post
slug: pygsmd-shell-shell-mode-of-libgsmd-tool-in-python
title: 'pygsmd-shell: Shell mode of libgsmd-tool in python'
wordpress_id: 84
categories:
- embedded
- FOSS and Linux
- linux
- Logs
- neo1973
- openmoko
- Python
tags:
- gsmd
- libgsmd
- linux
- neo1973
- openmoko
- pygsmd
- Python
- screenshots
---

Got some sms and phonebook code in the svn, but not all. So once I had some bindings finished. I decided to write a sort of example script that uses our pygsmd module. libgsmd-tool have always been a friend of mine in knowing whats up with gsmd. Therefore to pay a tribute to my good "friend", I came up with a python script that mimics 'libgsmd-tool -m shell'. Of course since pygsmd itself is yet to be completed, the script is incomplete although functional. Its been a long time since I had written a real python script, so if its not pythonic, please comment..The script is already in the svn,  so if you are interested take a look and most importantly test it out and extend it..=D

Heres a more sane version(88) from the svn

[http://projects.openmoko.org/plugins/scmsvn/viewcvs.php/*checkout*/python-gsmd/examples/pygsmd_shell.py?content-type=text%2Fplain&rev=88&root=python-openmoko](http://projects.openmoko.org/plugins/scmsvn/viewcvs.php/*checkout*/python-gsmd/examples/pygsmd_shell.py?content-type=text%2Fplain&rev=88&root=python-openmoko)

And the screenshot of pygsmd-shell in action. Notice the AT commands in Phonesim to the right. And the screenshot of the script running in the neo.

[![pygsmd-shell](http://sudharsh.files.wordpress.com/2007/11/pygsmdshell.thumbnail.png)](http://sudharsh.files.wordpress.com/2007/11/pygsmdshell.png)[!screenshot](http://sudharsh.files.wordpress.com/2007/11/screenshot-1.png)[![pygsmd-shell-neo](http://sudharsh.files.wordpress.com/2007/11/screenshot-1.thumbnail.png)](http://sudharsh.files.wordpress.com/2007/11/screenshot-1.png)

For pygsmd svn repository, [click here](http://projects.openmoko.org/plugins/scmsvn/viewcvs.php/?root=python-openmoko)
