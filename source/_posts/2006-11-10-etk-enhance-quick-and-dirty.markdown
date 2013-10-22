---
author: sudharsh
comments: true
date: 2006-11-10 10:52:34+00:00
layout: post
slug: etk-enhance-quick-and-dirty
title: ETK + Enhance, quick and dirty
wordpress_id: 35
categories:
- FOSS and Linux
- Tips
---

ETK is a gui toolkit similar to gtk and is a part of Enlightenment Foundation Libraries or EFL. The syntax is very similar to GTK with only minor differences. Infact you could even use Glade to design GUI with ETK. For this you need a small but nifty tools called 'enhance' also part of E. Glade btw is a tool which removes the need of manipulating each and every widget manually. It does all these in an efficient manner  leaving the developer to concentrate only on callbacks.

I am very new to ETK+Enhance and dont know which is better. EWL or ETK. If someone could shed light on this,  I would be grateful. Myself, being a novice found the lack of documentation for enhance a bit unnerving. But still I managed to get hold of the concepts. So here is a short tutorial about using 'enhance' to parse your .glade files and use them in your etk source codes.  Comments are welcome.

I assume some knowledge in ETK or atleast GTK...Lets dig in..

Now create a glade file with the name of project1.glade. Create a simple window with a single button in it. Now in the property window of the button in the Signal tab, add the following information Signal->Clicked, Handler->
, in our case "button_callback"

The following code is the famous hello world program using ETK and glade for creating the GUI..

`#include "Etk.h"
#include "Enhance.h"
Enhance *en;
void button_callback(Etk_Object *obj, void *data)
{
printf("Whee THis works\n");
}
int main(int argc, char *argv[])
{
enhance_init();
etk_init(&argc, &argv);
en=enhance_new();
enhance_file_load(en, "window1", "project1.glade");
etk_main();
enhance_free(en);
enhance_shutdown();
etk_shutdown();
return 0;
}`

``
Ok now a step by step description of whats up
`
#include "Etk.h"
#include "Enhance.h"
Enhance *en;`
We are just including header files that is required for our program..duh! Anyway the third line, we are creating a pointer for the Enhance datatype. 'en' will be used while loading  our .glade file

`void button_callback(Etk_Object *obj, void *data)
{
printf("Whee THis works\n");
}`
The above function is the callback function. When we click the "button" of our program the line within the printf would output to the console. If you dont understand what I am tallking about visit the gtk website and download the tutorial to get an idea of what callbacks and widgets are.
`
enhance_init();
etk_init(&argc, &argv);`
We are initialising enhance and etk..
`
en=enhance_new();`
Remember the pointer 'en' of datatype Enhance. en now becomes a new instance of enhance..

`enhance_file_load(en, "window1", "project1.glade");`
The above line will load the widget "window1" from the "project1.glade" file and "en" will point th them. You should load each widget, for example, you may have more than one window in your .glade file.
The remaining lines are self-explainatory..:D

Save the file as hello.c, in the directory containing project1.glade..and compile the program
`gcc -g hello.c  -o hello `enhance-config --libs --cflags` `pkg-config --libs --cflags``

If all went well, you will be left with the executable called "hello"..
run it
`./hello`
You will get a small window with the button with E17 theming  containing the label you had specified while creating the gui with glade. Click on the button and you will see the text "Whee THis works" output on the console everytime it is clicked.
**Reference:**
[E Developers Portal](http://edevelop.org)
[Glade and GTK+](http://people.debian.org/~rleigh/gtk/ogcalc/)
If you find something wrong, which is mostly likely, please comment about them. I am learning ETK/enhance myself.
