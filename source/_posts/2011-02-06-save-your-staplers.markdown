---
author: sudharsh
comments: true
date: 2011-02-06 15:45:18+00:00
layout: post
slug: save-your-staplers
title: Save your staplers!
wordpress_id: 403
categories:
- linux
- programming
- Python
- Tips
tags:
- fun
- initech
- lumberg
- officespace
- pygame
- Python
- webcam
---

Picture this. You are at work on a Friday evening. You are all pumped up! Who wouldn't be. Two full days of zero work ahead! You shutdown your computer, rise up, turn around to leave and BAM! This happens,


{% img center http://sudharsh.files.wordpress.com/2011/02/office-space.jpg %}




The key to '[Lumberg Evasion](http://en.wikipedia.org/wiki/Bill_Lumbergh)' is not only to stay 'hidden' but also to be aware of your boss' whereabouts. Information is wealth and can potentially save your weekend.




I wanted to check out Pygame and hacked out a little python script which does this. The idea is that you position your webcam (el-cheapo-no-brand webcams sell for peanuts) near your cubicle/desk and get notified if there is some movement in a predefined area. Also works great if you have a laptop and want to know if someone is peeking over your shoulder (yeah, yeah... I know about mirrors).




The script can detect movements within the red rectangle. Here is how it does this






	
  * When we start the script, the average color within the red rectangle is determined. This will act as the reference color.

	
  * Deviations in this average color is monitored in consecutive frames. If its more than a certain threshold, there is some movement.

	
  * When this happens, play a sound and pop up a little notification






{% img center http://sudharsh.files.wordpress.com/2011/02/screenshot-22.png %}











{% img center http://sudharsh.files.wordpress.com/2011/02/screenshot-21.png %}











{% img center http://sudharsh.files.wordpress.com/2011/02/screenshot-211.png %}


Of course, it goes without saying that its just a simple hack. Works well if the background color is of an uniform color.


[1]: [The Source Code](http://gitorious.org/dumb-scripts/phbalert/blobs/master/phbalert.py): Needs [pygame](http://www.pygame.org/news.html) and pynotify (for desktop notifications) to be installed. Very crude. Use at your own risk. The script is released under [WTFPL](http://en.wikipedia.org/wiki/WTFPL). Its rather simple but should be enough to be a starting point for more evil deeds :D.


P.S: No, I don't work for an 'Initech'.


P.P.S: If you are one of those 'Bill Lumberg' types, Fuck you!
