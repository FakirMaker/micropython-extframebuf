# micropython-extframebuf

Micropython renders images via built-in framebuf library.
It is very usefull and time saving also provides performance benefits, but it has some limittions like only ascii characters can be rendered by text function.
This library is just a slight modification of built-in framebuf library to show how extra characters can be added to charset and shrink font size from
8x8 to 7x8 for handsome looking.

If you want to add new character or change the default font, you should modify the extfont_8x8.h and modframebuf.c

How to compile it:

	Since it is written in native C, micropython cannot directly process it. It must be compiled. 
	If you are not familiar with native C for micropython check out this video.
	
	https://www.youtube.com/watch?v=1ZKWVj9UOQg

How to use compiled module:

	Micropython supports precompiled mpy files. 
	Just copy the extframebuf.mpy to your project directory and just import like a usual py module.
	Check the example.
