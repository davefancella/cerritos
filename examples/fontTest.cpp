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

// Include the cerritos header file.  This brings in pretty much everything.
#include "cerritos.h"

using namespace cerritos;

class etMainWindow : public cMainWindow {
public:
    void onMouseMotion(MouseMotionEvent* evt) {
        char buffer[100];
        snprintf(buffer, 100, "Mouse Motion: x(%d) y(%d)", evt->posx, evt->posy);
        mouseText.clear();
        mouseText = buffer;
    }
    
    void setFont(Font* theFont) {
        mFont = theFont;
    }
    
    void Render(const Timestep timestep) {
        Rect aRect = { 0,0,200,200 };
        mFont->RenderText(this->getWindow(),
                          mouseText,
                          &aRect,
                          255, 255, 255);
    }
    
    Font* mFont;
    
    String mouseText = "Nothing yet.  Hi there!";
};

class ftApplication : public Application {
public:
    CONSTRUCTAPP(ftApplication);
    
    void init() {
        setMainWindow(new etMainWindow() );
        getMainWindow()->setTitle("Font Test");
        
        Font* theFont = Font::loadFromFile("/usr/share/fonts/truetype/freefont/FreeSans.ttf", 30);
        dynamic_cast<etMainWindow*>(getMainWindow() )->setFont(theFont);
    };
};

CERRITOSMAIN(ftApplication)


