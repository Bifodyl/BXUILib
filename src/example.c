////////////////////////////////////////
//   Simple BXUILib Example program   //
////////////////////////////////////////

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "include/bxuilib.h"

int main()
{
    //TODO: Expand this
    //Create main window:
    Window win = bxuiCreateWindow(640,480,"Main Window");
    while (true)
    {
        bxuiUpdate(); //Does nothing right now
    }
    return 0;
}
