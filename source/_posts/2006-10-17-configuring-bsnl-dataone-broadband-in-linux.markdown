---
author: sudharsh
comments: true
date: 2006-10-17 13:56:15+00:00
layout: post
slug: configuring-bsnl-dataone-broadband-in-linux
title: Configuring BSNL Dataone Broadband in Linux
wordpress_id: 16
categories:
- FOSS and Linux
- Tips
tags:
- bsnl
- howto
- internet
---

Whatever you do..insist on an ethernet based router...You save a lot of aspirin and usb ports..

Oh and router=modem in this article...

**DHCP way:**

The most simple way of course is to use DHCP to set up your network automatically, In most cases everything gets configured automagically. If not enabled you should start the DHCP server by logging into the admin interface. See the wikipedia article to know more about DHCP.
[http://en.wikipedia.org/wiki/Dhcp](http://en.wikipedia.org/wiki/Dhcp)

**pppoeconf:**

In ubuntu there should be a program called pppoeconf installed by default, just run
`sudo pppoeconf`
You will be taken through a set of screens wherein you will be able to enter the details regarding your dataone account, Mostly configuring the DNS isnt required. Just rememeber that it is <user>@dataone and not <user>@dataone.in

Then to connect use
`pon dsl-provider`
if you have followed the default steps.

`poff dsl-provider`
to disconnect and
`plog`
to view status

In gentoo this tool is known an rp-pppoe, only the name differs..although its wizard is command line rather than the ncurses based pppoeconf

**Configuring the router directly:**

Of course another alternative is to use the admin interface available in the router provided. First make sure your box is detecting the ethernet interface correctly

next..
`ifconfig eth0 up 192.168.1.2`
and...
`route add default gw 192.168.1.1`

Point your browser to 192.168.1.1 and you should be greeted with the admin interface of your router. I use a Huawei Sterlite WA1003A.

username and password are admin.

After logging in goto Modem Setup, PVC0

select pppoe, fill in the details, save the settings and restart the router...Your modem should automatically dial-in.

Most distros have gui to configure this stuff, But some of us are smarter than the others and use distros like gentoo..For those users..:P

open up /etc/conf.d/net

and add/modify
`iface_eth0="192.168.1.2 broadcast 192.168.1.255 netmask 255.255.255.0"
gateway="eth0/192.168.1.1"`

After saving the file do a
`/etc/init.d/net.eth0 restart`

**If nothing works:**
So if  these steps dont work..there a last chance. Most of the times resolv.conf is to be blamed, Double check if its ok, Even if you have valid nameservers try putting the following in /etc/resolv.conf.

``` ini
nameserver 4.2.2.1
nameserver 4.2.2.2
```

These are public nameservers.
If it still doesnt work..you may have goofed up somewhere..

**Note:**



	
  * Configuring the router directly is more convenient since the configuration sits in your router rather than your system. So if you in some point lose your data, all you need to do to configure the internet is to configure the interfaces of the modem. Also  when using pppoeconf,   when I chose to enable the connection during boot time I found that my system was taking more time to boot, but this time delay was not experienced when I configured the connection through the admin interface of the router. Of course if for some reason, if the modem is restarted you need not execute the 'pon' command to connect when you configure the router directly. It automatically connects.

	
  * Use any one of the methods..not both

	
  * Sometimes if you have two ethernet interfaces you may need to disable one of them


