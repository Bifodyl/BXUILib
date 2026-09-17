#define BXUILIB_H_
#ifdef BXUILIB_H_
#include <X11/Xlib.h>		//X11 Main Library
#include <X11/Xutil.h>		//X11 Utilities Library


Window bxuiCreateWindow(int, int, const char*);
void bxuiUpdate();
bool bxuiButton(int,int,int,int,const char*);
bool bxuiToggleButton(int,int);
void bxuiLabel(int,int,const char*,Window);
void bxuiTextBox(int,int,int,char*,char*,Window);
void bxuiTextField(int,int,int,int,char*,char*,Window);

#endif
