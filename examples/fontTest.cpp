/*
 * Cerritos
 * Copyright 2021 by Dave Fancella, Anthony Fancella
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a 
 * copy of this software and associated documentation files (the "Software"), 
 * to deal in the Software without restriction, including without limitation 
 * the rights to use, copy, modify, merge, publish, distribute, sublicense, 
 * and/or sell copies of the Software, and to permit persons to whom the 
 * Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included 
 * in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS 
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 * 
 */

// This is an adaptation of the hello.cpp example that shows how to
// handle events using the Application object.

#include <iostream>
#include <stdio.h>
// Include the cerritos header file.  This brings in pretty much everything.
#include "cerritos.h"

#include "application.h"
#include "mainwindow.h"

#include "event.h"
#include "font.h"
#include "rect.h"

class etMainWindow : public cMainWindow {
public:
    void onMouseMotion(cMouseMotionEvent* evt) {
        this->mousex = evt->posx;
        this->mousey = evt->posy;
    }
    
    void setFont(cFont* theFont) {
        this->mFont = theFont;
    }
    
    void Render() {
        cRect aRect = { 0,0,200,200 };
        char buffer[100];
        snprintf(buffer, 100, "Mouse Motion: x(%d) y(%d)", mousex, mousey);
        mFont->RenderText(this->getWindow(),
                          buffer,
                          &aRect,
                          255, 255, 255);
    }
    
    cFont* mFont;
    
    int mousex=0;
    int mousey=0;
};

int main( int argc, char* args[] ) {
    // This is a handy way to initialize cerritos and get a default
    // application object.  Typically, more complex games need more than
    // a default application object.
    cApplication* theApp;
    etMainWindow* theWindow;
    cFont* theFont;

    cInit();
    
    theApp = new cApplication();
    theWindow = new etMainWindow();
    
    theApp->setMainWindow(theWindow);
    theWindow->setTitle("Font Test");
    
    theFont = cFont::loadFromFile("/usr/share/fonts/truetype/freefont/FreeSans.ttf", 30);
    theWindow->setFont(theFont);
    
    // This is your game loop.
    theApp->loop();
    
    // Close up cerritos before quitting.  This makes sure we don't leave
    // any devices open or whatever.  Most modern operating systems don't
    // have those problems anymore, but this helps avoid segfaults.
    cClose();
}

