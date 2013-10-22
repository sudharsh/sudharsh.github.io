---
author: sudharsh
comments: true
date: 2009-10-17 06:18:07+00:00
layout: post
slug: konsole-monitoring-with-twitter-and-python
title: Konsole monitoring with twitter and python
wordpress_id: 278
categories:
- FOSS and Linux
- linux
- programming
- Python
- Tips
tags:
- airtel
- kde
- konsole
- notification
- Python
- scripts
- Tips
- twitter
---

This happens to me all the time, especially when running programs that takes hours to complete.



	
  1. Start the code

	
  2. Go out for some tea or movie.

	
  3. When you come back, you find that the program had decided to piss you off by crashing 2 seconds after you went away from the keyboard.


The amount of cuss words thrown at the code/program is directly proportional to the silliness of the cause of the crash or error. Even more, if its a typo. Now that twitter allows tweets to be sent to Bharti AirTel (Boohoo others) numbers, and add Python + python-twitter + konsole (Terminal emulator from KDE) to the mix, you can get a very rudimentary notification system which can DM you when konsole activity changes.

To do this, First Enable 'Monitor for Silence' in 'View' Menu

Then  'Settings' -> 'Configure Notifications'. In the dialog that pops us, configure the notifications such that it executes a python script. The dialog should look something like this,

[![dialog](http://sudharsh.files.wordpress.com/2009/10/multi_sentiment2.png?w=247)](http://sudharsh.files.wordpress.com/2009/10/multi_sentiment2.png)

The real deal is in the script. It uses the python-twitter module to send a DM from a dummy account to whatever account you want the notifications to go to.

``` python    
    #!/usr/bin/env python
    
    import twitter
    
    username = "dummy_account"
    password = "password"
    
    receiver = "sup3rkiddo"
    
    def sendDM():
        try:
            api = twitter.Api(username=username, password=password)
            stats = api.PostDirectMessage(receiver, "*Done compiling*")
        except:
            print "Error!"
    
    if __name__ == '__main__':
        sendDM()
```    


Thats it! Simple but useful ;p (Of course, change the message according your needs)
