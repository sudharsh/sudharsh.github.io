---
author: sudharsh
comments: true
date: 2013-05-26 19:32:16+00:00
layout: post
slug: cloudcraft-easy-minecraft-server-management
title: 'Cloudcraft: Easy minecraft server management'
wordpress_id: 532
categories:
- Python
tags:
- aws
- cloudcraft
- creepers
- ec2
- minecraft
- Python
---

{% img center http://sudharsh.files.wordpress.com/2013/05/2013-05-25_00-39-01.png %}



I started working on [Cloudcraft](https://github.com/sudharsh/cloudcraft) as a toy project over the weekend. It aims to be an end-to-end toolbelt for managing [minecraft](http://minecraft.net) servers on EC2. As of now it's very Alpha quality but it can spawn instances and setup minecraft servers automatically with just a couple of commands. For example in the screenshot below, cloudcraft started the minecraft server on a spawned EC2 instance and reported the address needed for a multiplayer game.



{% img center http://sudharsh.files.wordpress.com/2013/05/2-zsh-2013-05-27-00-23-17.jpg %}



Autoscaling instances, plugin management, automatic updates are some of the things that are in the pipeline.

The project is on [github](https://github.com/sudharsh/cloudcraft) and as usual, suggestions, bug reports, bug fixes are welcome.
