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

#ifndef WINDOW__H
#define WINDOW__H

#include "string.h"
#include "backend.h"

struct SDL_Window;
struct SDL_Renderer;

namespace cerritos {

/** This class contains os-specific window information.
 */
class Window {
public:
    Window(String title, int posx, int posy, int width, int height, CER_WindowFlags winFlags=CER_Shown);

    // The title of the window
    String Title;
    
    // Size of window
    int width;
    int height;
    
    // Window position
    int posx;
    int posy;
    
    // Window flags
    CER_WindowFlags windowFlags;
    
    bool isValid() { return m_IsValid; };
    
#ifdef USING_SDL
    SDL_Window* getSDLWindow() { return m_Window; };
    SDL_Renderer* getSDLRenderer() { return m_Renderer; };
#endif
    
private:
    // Forbid use of default constructor
    Window();
    
    bool m_IsValid;
    
#ifdef USING_SDL
    SDL_Window* m_Window;
    SDL_Renderer* m_Renderer;
#endif
};

}

#endif // WINDOW__H


