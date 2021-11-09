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

#include "SDL.h"

#include "cerritos.h"

#include "object.h"
#include "string.h"

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

class cMainWindow : public cObject {
public:
    // The title of the window
    unicodestring Title;
    
    // Size of window
    int width;
    int height;
    
    // Window position
    int posx;
    int posy;
    
    // Window flags
    CER_WindowFlags windowFlags;
    
    // Constructors
    cMainWindow(CER_WindowFlags winFlags=CER_Shown);
    cMainWindow(unicodestring title, CER_WindowFlags winFlags=CER_Shown);
    cMainWindow(unicodestring title, int width, int height, CER_WindowFlags winFlags=CER_Shown);
    cMainWindow(unicodestring title, int width, int height, int posx, int posy, CER_WindowFlags winFlags=CER_Shown);
    virtual ~cMainWindow();
    
    void setTitle(unicodestring title);
    void setPosition(int posx, int posy);
    void setSize(int width, int height);
    
    /// Call to update the window
    virtual void Update();

private:
    //The window we'll be rendering to
    SDL_Window* window = NULL;
    
    //The surface contained by the window
    SDL_Surface* screenSurface = NULL;
    
};

#endif




