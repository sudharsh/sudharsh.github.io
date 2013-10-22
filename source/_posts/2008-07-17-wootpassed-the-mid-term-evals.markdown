---
author: sudharsh
comments: true
date: 2008-07-17 13:51:51+00:00
layout: post
slug: wootpassed-the-mid-term-evals
title: Woot..Passed the mid-term evals
wordpress_id: 133
categories:
- embedded
- FOSS and Linux
- freesmartphone.org
- gsoc
- linux
- neo1973
- odeviced
- openmoko
tags:
- frameworkd
- freerunner
- freesmartphone
- fso
- gsoc
- neo1973
- odeviced
- openmoko
---

After a week's waiting my mentor informed me that I had passed the mid-term evaluations. (he said that my performance for the first phase exceeded his expectations. :D ).

Its been a long time since I actually blogged about the progress. After I got the Freerunner in my hand (muhuhahahaa), it was more fun since there were subtle changes in the way the code ran on the device. Tracking down segfaults was uber awesome.

Plugins are now written *entirely* in vala. Earlier, this used to be an ugly abomination of hand-written and vala generated C code. Now, where good ol' C is necessary, .vapis' have been added that wrap around code written in C.

Additionally plugins for rtc, input and led were added. Input plugin is incomplete though. The code isn't perfect yet, so need to refine them and make them a bit tight in some places. rtc and led especially needs some tweaks.

I guess most of the second phase will be spent on syncing with frameworkd. Now, the python device daemons have been integrated into a single daemon with odeviced as one of the subsytems. (Earlier this was separate). The python daemon is uber-cool by itself, but imagine a C implementation of the entire frameworkd. Light on resources and excellent in performance, if done **right**.

Git repository [here](http://git.freesmartphone.org/?p=openmoko-gsoc2008.git;a=summary).
