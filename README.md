# micropython-extframebuf

Micropython renders images via built-in framebuf library.
It is very usefull and time saving also provides performance benefits, but it has some limitations like only ascii characters can be rendered by text function.
This library is just a slight modification of built-in framebuf library to show how extra characters can be added to charset and shrink font size from
8x8 to 7x8 for handsome looking.

Remember the pre-compiled extframebuf.mpy file is just an example and only contains additional Turkish characters and compiled for esp32 and cannot work if you are using different architecture.
If you want to add new character or change the default font or want to use different board, you must modify the extfont_8x8.h and modframebuf.c and compile it.

How to compile it:

	Since it is written in native C, micropython cannot directly process it. It must be compiled. 
	If you are not familiar with native C for micropython check out this video.
	
	https://www.youtube.com/watch?v=1ZKWVj9UOQg

How to use compiled module:

	Micropython supports precompiled mpy files. 
	Just copy the extframebuf.mpy to your project directory and import like a usual py module.
	Check the example.
