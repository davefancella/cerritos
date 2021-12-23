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

#ifndef SURFACE__H
#define SURFACE__H

#include <cstdint>

// SDL Forward declarations
#ifdef USING_SDL
struct SDL_Texture;
#endif

class cRect;
struct cPixelFormat;

namespace cerritos {

class cWindow;

/** A surface to which to render.  It's used by widgets, sprites, fonts,
 *  and pretty much anything that needs to draw to the screen.
 */
class cSurface {
public:
    cSurface(cWindow* window);
    ~cSurface();

    /// Copies this surface to another surface.
    void Blit_To(cRect* dest);
    
    /// Use this to fill the entire surface with one color
    void Fill(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha=255);
    
    /// Use this to fill the surface or an area of the surface with
    /// a color.
    void FillRect(const cRect* rect, uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha=255);
    
private:
    /// Disable default constructor
    cSurface();

    cWindow* m_Window;
#ifdef USING_SDL
    SDL_Texture* m_Texture;
#endif
};

}

#endif // SURFACE__H


