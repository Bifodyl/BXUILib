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

#include "bxuilib.h"	//Link this source file to its header

Display* disp;  //Pass XDisplay into this
Window rootWin; //Pass XRootWindow into this
Window mainWin; //When creating window, pass into this

int winWidth;							//Window Width
int winHeight;							//Window Height
int winBorder = 0;						//Border Thickness
int winDepth = CopyFromParent;			//Copied from parent, ignore
int winClass = CopyFromParent;			//Copied from parent, ignore
Visual* winVisual = CopyFromParent;		//Copied from parent, ignore
int attribMask = CWBackPixel;			//Window Attribute Mask
XSetWindowAttributes winAttribs = {};

Window bxuiCreateWindow(int w,int h,const char* title)
{
	disp = XOpenDisplay(0); 					//Get XDisplay and pass into disp
	rootWin = XDefaultRootWindow(disp);  		//Get root window from display
	winAttribs.background_pixel = 0xFFFFFFFF;	//Set background color to white.
	winWidth = w;
	winHeight = h;
	//Register and create new window:
	mainWin = XCreateWindow(disp,rootWin,0,0,winWidth,winHeight,winBorder,winDepth,winClass,winVisual,attribMask,&winAttribs);
	XMapWindow(disp,mainWin); 		//Map the window
	XStoreName(disp,mainWin,title); //Set title to string passed to this function.
	XFlush(disp); 		//Flush display/Clear display.
	return mainWin; 	//Return Window ID.
}

//The following functions are empty placeholders,
//they will be implemented over time.

bool bxuiButton()
{
	//TODO: Make this create and maintain a button element
	return false;
}

bool bxuiToggleButton()
{
	return false;
}

void bxuiLabel()
{
	//TODO: Make this create and maintain a label element
}

void bxuiTextBox()
{

}

void bxuiTextArea()
{

}
