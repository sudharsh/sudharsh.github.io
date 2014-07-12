---
layout: post
title: Jenkins Build Status on Arduino
date: 2013-12-07 22:58
comments: true
categories: 
- Programming
- Python
- Arduino
tags:
- ci
- electronics
- arduino
- python
- programming
- jenkins
---

I gifted myself an Arduino Starter Kit from [Simplelabs](http://www.simplelabs.co.in) to kill some time during the weekends. 
Needless to say, I felt really proud of myself once I got the [LED blink example](http://arduino.cc/en/tutorial/blink) working without breaking anything.

My next project was a simple [Jenkins](http://jenkins-ci.org/) build monitor, very popular amongst the Arduino beginners out there who write code.

Here is my version of this hack. In addition to the usual 'traffic light', I also plonked on a 16x2 LCD to the circuit which displays the build number along with the status. Scroll down to the end of this post to see this in action.

## Schema

<img src="{{ root_url }}/images/Jenkins.png" />

I used [Fritzing](http://fritzing.org/) to draw this schema and I know it's a little bit ugly. 

Anyway, successful builds turn on the Green LED; Unstable builds, yellow; Failed builds, red and my favorite of all, builds in progress makes the LEDs turn into [KITT](http://en.wikipedia.org/wiki/KITT) from Knight Rider :P. 

## Code

The code is pretty simple. There is a Python script that uses the Jenkins REST API to get the latest build and its status for a given a job. 
This is translated into a crude command for the Arduino board to pick up using the Serial interface.

#### Python side of things

{% include_code jenkins_status.py  %}

#### The 'Sketch'

{% include_code lang:cpp jenkins.ino  %}

## In Action

Here it is in action. As you can see, the LCD displays the Job, the last build number and its state.
The wiring is a huge mess, but hey, it works! :)

<img src="{{ root_url }}/images/20131207_184155.jpg" />

## Components used

- Arduino UNO R3
- 5 220-ohm resistors
- 3 LEDs; Green, Red and Yellow
- A bunch of wires
- HD44780 [16x2 LCD](http://www.adafruit.com/products/181)

Next step, maybe build a bigger housing for the entire system. 

