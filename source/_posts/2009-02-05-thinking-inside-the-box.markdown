---
author: sudharsh
comments: true
date: 2009-02-05 17:20:09+00:00
layout: post
slug: thinking-inside-the-box
title: Thinking inside the "box"
wordpress_id: 205
categories:
- programming
- Rants
---

About 10 minutes ago, my brain switched from neutral to first gear and started pondering about ways to teach someone how to program (Not that I am particularly good at programming in the first place :D).

For example, how would you explain the concept of variables, references, names. etc, which seemingly form the corner stone of programming language syntax. Sometimes this can make you struggle a bit when you are switching languages.

Consider the following,

```
>>> a = 10
>>> b = a
>>> id(a)
37688272
>>> id(b)
37688272
```

One teency weency thing I learnt the hardway was the fact that when the interpreter evaluates 'a = 10', it creates a "box", slaps the label 'a' on it and puts the integer 10 in it. Consequently, something like swapping of two numbers becomes as easy as,

``` python
a, b = b, a
```

This is actually emphasised on most, if not all Python tutorials I have come across. This didn't sound all that important when I learnt Python for the first time.

Then I found C to be doing things differently (Am I even right?),
Take this for example,

``` c 
    #include <stdio.h>
    
    int main(int argc, char **argv) {
    	int x = 5;
    
    	/* This however creates a new "box"
               containing the value 5 and a name y */
    	int y = x;
    
           	printf("Value of x = %d, Address of x is %x\n" \
    	       "Value of x = %d, Address of y is %x\n", x, &x, y, &y);
    	return 0;
    }
```


Gives the following output, where x and y are named on different boxes and yet have the same values.
```
Value of x = 5, Address of x is 98e6cecc
Value of x = 5, Address of y is 98e6cec8
```

Hmm, This is where I hit it. Suddenly realisation dawned. Sun shone again. Birds twittered. The darkness was gone. I suddenly found myself telling _**"Its called the pointers.. stupid!"**_

Now, to mirror the the Python "box" analogy (not exactly) well, a in a language like C, we have to our disposal the good old pointers.

``` c    
    #include <stdio.h>
    
    int main(int argc, char **argv) {
    	int x = 5;
    
            /* Pointer to the "box" that is name 'x'. */
    	int *y = NULL;
    	y = &x;
           	printf("Value of x = %d, Address of x is %x\n" \
    	       "Value of y = %d, Address of y is %x\n", x, &x, *y, y);
    	return 0;
    }
```


This would give me,
`Value of x = 5, Address of x is c07ec844
Value of y = 5, Address of y is c07ec844
`

where '*' and '&' are the de-reference (value-of) and reference (value-at) operators.

So folks, Is it right to think along the lines of "a box at c07ec844 is labelled 'x' with the integer value 5" when I see something as mundane as "int x = 5" . It did help me to understand pointers better, but are there any better analogies when speaking about variables, references etc. than say, picturing a row of shelves with lots of boxes, each of which can have multiple sticky notes with names at a given point of time.
