---
author: sudharsh
comments: true
date: 2007-01-12 15:42:06+00:00
layout: post
published: false
slug: i-am-backto-gentoo
title: I am back!!...to gentoo
wordpress_id: 43
categories:
- FOSS and Linux
- Rants
---

Gentoo is cursed..Heres how..You use it once, feel that its not worth your time, start using debian or ubuntu only to return back to gentoo..Ubuntu and debian were tooo perfect and generic on my computer, and that too i used Debian sid. Well alright, I might sound like a fanboy, but honestly gentoo is something you should give a shot..Gentoo and Debian have lots in common.
Portage, probably on par with with Debian Package Management used in Debian, Ubuntu.etc appealed to me since the whole package management part is written in Python and bash. If you find Python interesting Portage is something to look out for.

I installed gentoo from the live cd but didnt choose to install any of the components except a working shell without X. Then did an emerge --sync and lo...download time. I guess the classic "2 day compilation" stories dont apply in modern computers. I started installing in midnight and the next day I had a working system with KDE. Note that I didnt install kde-meta virtual package which pulls in everything kde..Only things I wanted, I installed..No stupid services making my box to crawl, just plain minimalistic stuff I know I wanted. Thats the magic about gentoo and debian. YOU are under control of your system.

USE flags are a great concept too. Although there were no noticable speed increases in smaller apps, bigger guys like Firefox did seem snappier, although I am not sure if its just an illusion. One thing is certain, maintaining a gentoo box is loads easier than Debian even if it takes time to install from source. Another thing to note that latest packages get into the gentoo repositories quite soon after the upstream versions are released, something not common in debian world (atleast the stable release).

Gentoo is versionless too..with common command "emerge -uND world" you have a fresh new system full of latest softwares. CD releases are just snapshots of the package tree at that instant. For example I dont have to reinstall again when the next version 2007.0 comes out at the end of this month.

And the number one reason to try out gentoo....Its the community. The Forums and the irc channel at #gentoo are full of friendly people who are happy to help.

In the end, Debian and Gentoo appeals to me because they IMO, are pure community distros with similar ideologies and policies towards OSS..I have never quite gotten myself to like other distros with a commercial backing, with ubuntu being an exception. So if you have time, do install gentoo, Its fulfilling. They have a rocking documentation, friendly community and dare I say, a package management system that puts the RPM based ones to shame.
