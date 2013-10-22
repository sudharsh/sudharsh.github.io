---
author: sudharsh
comments: true
date: 2008-05-18 15:32:04+00:00
layout: post
slug: fun-with-vala-and-dbus
title: Fun with Vala and DBus
wordpress_id: 107
categories:
- embedded
- FOSS and Linux
- gsoc
- linux
- Logs
- neo1973
- odeviced
- openmoko
tags:
- dbus
- gsoc
- odeviced
- openmoko
- soc
- vala
---

After the lousy semester exams, I decided put in some time to learn [vala](http://live.gnome.org/Vala) and [dbus](http://freedesktop.org/wiki/Software/dbus) to cheer me up. For the unitiated,



	
  * `_Vala is a new programming language that aims to bring modern programming language features to GNOME developers without imposing any additional runtime requirements and without using a different ABI compared to applications and libraries written in C._'

	
  * DBus is a low latency IPC system with less overhead with emphasis on desktop applications


I must say the folks at #vala in GimpNet has been patient with me, especially considering the silly questions I had been asking for the last couple of days. I should get commit access to the git repositories of freesmartphone.org in a short while as well :D.

I learned a couple of things on the way. Especially the KeyFile API from the [GLib](http://library.gnome.org/devel/glib/) library really rocked. Note that odeviced would have configuration file sitting in '/etc' containing various settings like plugins to be loaded, their own internal switches and so on. I would have almost "reinvented the wheel" trying to reimplement stuff thats already provided by GLib if I hadn't browsed through the API reference of GLib. Implementing something like the above for odeviced in vala looks something like this,

`
....
private GLib.KeyFile file = new GLib.KeyFile();
private string[] plugins;
private string dev_name = new string();
......
/* vala will warn you if you dont put this under a try, catch block */
file.load_from_file("/etc/odeviced.conf", GLib.KeyFileFlags.NONE);
if (file.has_group("odeviced"))
this.dev_name = file.get_string("odeviced", "device_name");
plugins = file.get_groups();
_load(plugins);
....
`

Of course, the corresponding configuration file will look something like this,
`
[odeviced]
device_name=FreeRunner

[powercontrol]
enable=1
`

In the above example, things within '[' and ']' are group names and each of these groups consist of a key-value pair.

As for the dbus part, each plugin would set up dbus objects on their own. GModule library will be used to load the _.so_ libraries. So we'd have object paths like /org/freesmartphone/Device/powercontroller. And of course, odeviced will be on the System Bus.

On a related note, the "surprise" gift is on its way :D.
