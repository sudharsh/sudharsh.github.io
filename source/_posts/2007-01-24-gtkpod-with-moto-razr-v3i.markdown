---
author: sudharsh
comments: true
date: 2007-01-24 13:52:20+00:00
layout: post
slug: gtkpod-with-moto-razr-v3i
title: gtkpod with moto razr v3i
wordpress_id: 44
categories:
- FOSS and Linux
- Rants
- Tips
---

So, one of my friends turned up today with his new moto v3i asking for help..Pretty simple, put music in his mobile and make it accessible through itunes software bundled with v3i.

With a sense of confidence I connected it to my box, and voila it was detected as a Mass Storage Device. He gave me the CDs that came with his mobile. I gave him a smirk in return and said "This is Linux..Linux doesnt need any steenking windows driver cd".

I copied some songs over his mobile in the itunes folder. But no songs in itunes. After scratching my head for a while, I decided to give gtkpod a shot..So fired uo my trusty shell and did a "emerge gtkpod".

In gtkpod in "Edit iPod Properties", i selected the device as xmobile, connected the mobile and this time syncing the music worked...

He is now probably wondering whether to give gentoo a go..
