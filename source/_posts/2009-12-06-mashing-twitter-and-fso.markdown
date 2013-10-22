---
author: sudharsh
comments: true
date: 2009-12-06 14:27:14+00:00
layout: post
slug: mashing-twitter-and-fso
title: Mashing Twitter and FSO
wordpress_id: 292
categories:
- embedded
- FOSS and Linux
- freesmartphone.org
- linux
- openmoko
- programming
- Python
- Tips
tags:
- dbus
- freerunner
- freesmartphone
- freesmartphone.org
- fso
- gta02
- neo
- neo1973
- openmoko
- Python
- scripts
- snippet
- twitter
---

I really love Twitter and it didn't make any sense to me to shell out a rupee for every tweet sent through my Airtel Mobile. Moreover, I am on one of those monthly booster packs which allows you to send 22000 text messages for free. I simply had to exploit this by setting up my own little 'OC' twitter forwarder written in python. (I know of smstweet.in service but I am still charged 1.50 for every tweet I send)

Its insanely simple to write such a 'forwarder' in python using the services provided by the FSO ([freesmartphone.org](http://wiki.freesmartphone.org)) Framework,



	
  1. Send messages to your old/unused number whose SIM is in the [Freerunner](http://openmoko.com/freerunner.html) (or any other device supported by the [FSO](http://wiki.freesmartphone.org) framework)

	
  2. Handle the incoming messages and use [python-twitter](http://code.google.com/p/python-twitter/) API (or) raw urllib2 to post updates. Of course, the device should be connected to the internet, you can [tether](http://wiki.openmoko.org/wiki/Usb_networking) this device to an old unused computer. Simply put, the Freerunner should be able to access the internet.


I know this is dumb given cheap GPRS and all, but what the heck; Sundays _are_ reserved for dumb things and I wanted to show off how easy it is to develop and conjure up simple but powerful scripts using open hackable hardware like the Freerunner. So take off your pedantic hats ;)

Here is the actual python code,

``` python
#!/usr/bin/env python
# Written By Sudharshan S, http://sudharsh.wordpress.com

import dbus
import time
import logging
import twitter

import gobject
from gobject import MainLoop

from dbus.mainloop.glib import DBusGMainLoop
DBusGMainLoop (set_as_default = True)

# Use OAUTH?
USERNAME = "username"
PASSWORD = "password"

log = logging.getLogger("TweetForwarder")

class TweetForwarder:

   """Process Incoming messages and update twitter status
      if the message startswith 'tweet'
   """

   def __init__(self, username, password):
       log.warning("Starting up....")
       self.twitter_api = twitter.Api(username=username, password=password)

       # Get proxies and add signal handlers
       bus = dbus.SystemBus()
       _usage = bus.get_object("org.freesmartphone.ousaged",
                               "/org/freesmartphone/Usage")
       _proxy = bus.get_object("org.freesmartphone.ogsmd", \
                               "/org/freesmartphone/GSM/Device")
       self.usage_iface = dbus.Interface(_usage, "org.freesmartphone.Usage")
       self.usage_iface.RequestResource('GSM')
       self.sms_iface = dbus.Interface (_proxy, "org.freesmartphone.GSM.SMS")
       self.sms_iface.connect_to_signal ("IncomingMessage", self.onIncomingMessage)

   def onIncomingMessage(self, sender, message, kwargs):
       log.warning("Received SMS from %s:%s" % (sender, message))
       # We don't ALL messages to this number to be tweeted
       if message.strip().startswith("tweet "):
           log.warning("Trying to update status : %s" % message[6:].strip())
           self.twitter_api.PostUpdate(message[6:])
           log.warning("Updated Status")

   def run(self):
       loop = MainLoop()
       loop.run()

if __name__ == "__main__":
    logging.basicConfig()
    server = TweetForwarder(USERNAME, PASSWORD)
    server.run()
```

Make sure you have python-netclient and python-json installed on your Freerunner. These can be installed using the 'opkg install' command.

The script and the accompanying dependency can be downloaded from [here](http://gitorious.org/dumb-scripts/dumb-scripts/archive-tarball/master). Just change the USERNAME and PASSWORD accordingly after scp'ing the tarball to your device.

Some useful links,

[1]: [The FSO API reference](http://git.freesmartphone.org/?p=specs.git;a=tree;f=html;h=bb7b2226c03c13b7c930e119c0df4bd0c91c06bb;hb=2a40169edbec7a2fcb804aa45e496df01aeba782)

[2]: [DBus Tutorial](http://dbus.freedesktop.org/doc/dbus-tutorial.html)
