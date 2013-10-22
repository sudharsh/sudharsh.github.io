---
author: sudharsh
comments: true
date: 2009-04-09 13:17:33+00:00
layout: post
slug: yet-another-brainfuck-interpreter
title: Yet another Brainfuck interpreter
wordpress_id: 230
categories:
- FOSS and Linux
- programming
tags:
- brainfuck
- c
- compilers
- esoteric
- interepreter
- programming
- snippet
- wtfpl
---

[Brainfuck](http://en.wikipedia.org/wiki/Brainfuck) is one of those turing complete languages that has no apparent use in the real world. But hey, being very very simple with a limited grammar, writing an interpreter should be easy. So here it is, under [WTFPL](http://sam.zoy.org/wtfpl/). The code works (I hope so) with the examples from the Wikipedia [article](http://en.wikipedia.org/wiki/Brainfuck#Examples).

``` c    
    #include <stdio.h>
    #include <error.h>
    
    #include <config.h>
    
    static char cellspace[30000];
    static char *data_pointer;
    
    int process_command(char command, FILE *file_ptr)
    {
    	char c;
    	long pos;
    
    	switch(command) {
    	case '>':
    		++data_pointer;
    		break;
    	case '<':
    		--data_pointer;
    		break;
    	case '+':
    		++*data_pointer;
    		break;
    	case '-':
    		--*data_pointer;
    		break;
    	case '.':
    		putchar(*data_pointer);
    		break;
    	case ',':
    		*data_pointer = getchar();
    		break;
    	case '[':
    		pos = ftell (file_ptr);
    		while(*data_pointer != NULL) {
    			fseek (file_ptr, pos, SEEK_SET);
    			c = getc(file_ptr);
    			while( c!= ']' && c != EOF) {
    				process_command(c, file_ptr);
    				c = getc(file_ptr);
    			}
    
    		}
    
    	}
    
    }
    
    int interpret_source(const char *source) {
    
    	/*
    	 *  Allowed brainfuck commands are,
    	 *  > 	increment the data pointer (to point to the next cell to the right).
    	 *  < 	decrement the data pointer (to point to the next cell to the left).
    	 *  + 	increment (increase by one) the byte at the data pointer.
    	 *  - 	decrement (decrease by one) the byte at the data pointer.
    	 *  . 	output the value of the byte at the data pointer.
    	 *  , 	accept one byte of input, storing its value in the byte at the data pointer.
    	 *  [ 	if the byte at the data pointer is zero,
    	 *      then instead of moving the instruction pointer forward to the next command,
    	 *      jump it forward to the command after the matching ] command.
    	 *  ] 	if the byte at the data pointer is nonzero,
    	 *      then instead of moving the instruction pointer forward to the next command,
             *      jump it back to the command after the matching [ command.
    	 */
    
    	char command;
    	FILE *file_ptr = fopen(source, "r");
    
    	if (!file_ptr) {
    		fprintf(stderr, "Error: No such file %s\n", source);
    		return FALSE;
    	}
    
    	while((command = getc(file_ptr)) != EOF)
    		process_command(command, file_ptr);
    	fclose(file_ptr);
    	return TRUE;
    }
    
    int main(int argc, char **argv)
    {
    	/* Init data_pointer to the left most cell */
    	data_pointer = &cellspace[0];
    
    	/* Use getopts? */
    	if (argc > 1)
    		interpret_source(argv[1]);
    	return 0;
    }
```