---
author: sudharsh
comments: true
date: 2009-06-30 10:57
layout: post
slug: give-your-boss-the-illusion-of-managing-you-with-pidgin-and-dbus
title: Give your boss the illusion of managing you... with pidgin and dbus
wordpress_id: 248
categories:
- FOSS and Linux
- programming
- Python
- Rants
- Tips
tags:
- comicstrip
- dbus
- dilbert
- im
- moronity
- pidgin
- pointyhairedboss
- purple
- Python
- snippet
- wally
- wtfpl
---

{% img center http://dilbert.com/dyn/str_strip/000000000/00000000/0000000/000000/50000/9000/500/59569/59569.strip.gif %}

Oh yeah!. With the power of DBus and libpurple APIs it is possible to give your boss the illusion of managing you. Just run the following script (under [WTFPL](http://sam.zoy.org/wtfpl/)). Tested with jabber accounts in a live office environment :P.

    
``` python    
    #!/usr/bin/env python
    # By Sudharshan S, released under WTFPL
    
    import dbus
    import gobject
    import time
    
    class PointyHairedBoss:
    
       def __init__(self, boss_id, source, frequency=30):
            self.boss_id = boss_id
            self.source = source
            self.frequency = frequency
            bus = dbus.SessionBus()
            _pidgin_proxy = bus.get_object("im.pidgin.purple.PurpleService", \
                                                           "/im/pidgin/purple/PurpleObject")
            self.purple = dbus.Interface (_pidgin_proxy, "im.pidgin.purple.PurpleService")
            # FIXME:
            account_id = self.purple.PurpleAccountsGetAllActive()[0]
            self.boss_conversation = self.purple.PurpleConversationNew(1, account_id, self.boss_id)
            self.boss_im = self.purple.PurpleConvIm(self.boss_conversation)
            print self.boss_im
    
        def start_nonsense(self):
            question_list = open(self.source)
            for q in question_list:
                self.purple.PurpleConvImSend(self.boss_im, q)
                time.sleep(self.frequency)
    
    if __name__ == "__main__":
       # Change the jabber id and the path to your questions, with an optional frequency
       o = PointyHairedBoss("foo@gmail.com", "questions")
       o.start_nonsense()
```
