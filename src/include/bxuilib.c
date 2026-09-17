///////////////////////////////////////////////////////
//	Bif's simple X UI Library (BXUILib)	source file  //
//			    Developed by Bif in 2026             //
///////////////////////////////////////////////////////

#include <stdlib.h>			//C Standard Library
#include <stdio.h>			//C I/O Library
#include <stdint.h>			//C Expanded Integers Library
#include <stdbool.h>		//C Boolean Library
#include <X11/Xlib.h>		//X11 Main Library
#include <X11/Xutil.h>		//X11 Utilities Library

#include "globals.h"
#include "bxuilib.h"	//Link this source file to its header

Display* disp;  //Pass XDisplay into this
Window rootWin; //Pass XRootWindow into this
Window mainWin; //When creating window, pass into this

int winWidth = 640;						//Window Width
int winHeight = 480;					//Window Height
int winBorder = 0;						//Border Thickness
int winDepth = CopyFromParent;			//Copied from parent, ignore
int winClass = CopyFromParent;			//Copied from parent, ignore
Visual* winVisual = CopyFromParent;		//Copied from parent, ignore
int attribMask = CWBackPixel;			///To be honest, I don't know what this does, but X11 needs it.
XSetWindowAttributes winAttribs = {};

Window bxuiCreateWindow(int w,int h,const char* title)
{
	disp = XOpenDisplay(0);  //Get XDisplay and pass into disp
	rootWin = XDefaultRootWindow(disp);  //Get root window from display
	winAttribs.background_pixel = 0xFFFFFFFF;
	//Register and create new window:
	mainWin = XCreateWindow(disp,rootWin,0,0,winWidth,winHeight,winBorder,winDepth,winClass,winVisual,attribMask,&winAttribs);
	XMapWindow(disp,mainWin); 		//Map the window
	XStoreName(disp,mainWin,title); //Set title to string passed to this function.
	XFlush(disp); 		//Flush display/Clear display.
	return mainWin; 	//Return Window ID.
}