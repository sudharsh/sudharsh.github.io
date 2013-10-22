---
author: sudharsh
comments: true
date: 2009-07-25 17:22:42+00:00
layout: post
slug: nai-sekar-your-not-so-friendly-translation-bot
title: Nai Sekar, your not-so-friendly translation bot..
wordpress_id: 265
categories:
- Events
- FOSS and Linux
- programming
- Python
- Rants
- Tips
---

[![Sekar](http://sudharsh.files.wordpress.com/2009/07/s1427363078_6936.jpg)](http://sudharsh.files.wordpress.com/2009/07/s1427363078_6936.jpg)Recently I had to make use of Google's translation engine to translate phrases at work. Given the lazy big bum I am, I found using the Google's web UI a bit tiresome to use. I thought "heck, why not write a little jabber bot to make things a bit easier..". (Agreed, writing a bot is nowhere near to the best solution.)

Writing a Jabber bot is incredibly easy with python. You will need the [JabberBot](http://thpinfo.com/2007/python-jabberbot/) package, which offers a really really simple and straightforward way to write bots. The little script below proves how easy it is.

The bot translates phrases/sentences using the [python-pygtrans](http://code.google.com/p/py-gtranslate/) package. I had to name the script *something* and Nai Sekar seemed to be a good idea. Apologies if you just went 'WTF?!'.  (I am quite lame when it comes to naming code/function/classes)

``` python    
    #
    # Released Under WTFPL
    # http://sam.zoy.org/wtfpl/
    #
    from jabberbot import JabberBot
    import gtrans
    import random
    
    # Gmail uses Jabber, but their TOS doesn't allow automated scripts. So be warned
    username = 'yourJabberID@example.com'
    password = 'password'
    
    # Just some famous dialogues from Vadivelu comedy tracks. Might not make sense if you
    # don't know who or what vadivelu is.
    error_dialogues = [
        "Nee yaaru kitta paysikittu irrukaynu theriyuma? Sekar ngara oru TERROR kitta",
        "Saykar settutaan",
        "Tirisa illana Divya",
        "Huh.. yennaku body strong basement weeeku",
        "Naanum rowdy.. naanum rowdy.. naanum rowdy",
        "Shabba... ippovae kannu kattudae",
        "Heloooo.. Ennoda biruther maark irukaara",
        "Don't worry.. Be gaaapy",
        "But andha dealing enaku pudichi irundhuchi",
        "lighta...",
        "Vaynda... Vallikidu.... Azuthuduvane.. Azhuthuduvane",
        "Sing in the raine... I am swoying in the raine..",
        "Helloo.. Prabha wine shop ownerungala? Kadaiya.. yeppo saar tharapeenga?",
        " romba nallavanu enna pathu sollitanmaaaaa..."
    ]
    
    class NaiSaykarBot(JabberBot):
    
        def bot_trans(self, msg, args):
           """Translate the phrase/sentence from the source language to the required language
              ex: trans en pl Apples grow in trees
              would translate the above phrase from english to polish
           """
           split = args.split()
           if len(split) == 0:
                return
           src_language = split[0].strip()
           required_language = split[1].strip()
           phrase = ' '.join(split[2:])
           try:
                translated = gtrans.translate(src_language, required_language, phrase)
                return translated
           except gtrans.InvalidLanguage, e:
                print "Invalid args : %s" %(args)
                # Return a random error message
                return random.choic e(error_dialogues)
    
        # Overridden from JabberBot
        def unknown_command( self, mess, cmd, args):
            print "Unknown Command %s" %(args)
            return random.choice(error_dialogues)
    
    if __name__ == '__main__':
         bot = NaiSaykarBot(username, password)
         bot.serve_forever()
```