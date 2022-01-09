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

#include <cstdint>

#ifndef SURFACE__H
#define SURFACE__H

#include "backend.h"
#include "point.h"

// SDL Forward declarations
#ifdef USING_SDL
struct SDL_Texture;
#endif

struct cPixelFormat;

namespace cerritos {

class Window;
class Rect;

/** A surface to which to render.  It's used by widgets, sprites, fonts,
 *  and pretty much anything that needs to draw to the screen.
 * 
 *  When you create a new surface, you have to pass it the one and only
 *  one pointer to the window to which the surface will ultimately draw
 *  itself.  Otherwise, it simply stores a texture internally.
 */
class Surface {
public:
    Surface(Window* window);
    ~Surface();

    cSizeInt size() { return m_Size; };
    void setSize(cSizeInt newSize) { m_Size = newSize; };
    
    /**
     * Renders this surface to the window given during construction.
     * 
     * @param dest The destination.  Only the position coordinates are used.
     * @param angle The angle, in degrees, starting from straight north.
     *              The surface will be rotated.
     * @param center The origin of the surface.
     * @param flip Whether or not to flip, horizontally or vertically.
     */
    void Blit_To(PointInt* dest, const double angle=0.0, PointInt *center=NULL, CER_RenderFlags flip=CER_None);
    
    /// Use this to fill the entire surface with one color
    void Fill(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha=255);
    
    /// Use this to fill the surface or an area of the surface with
    /// a color.
    void FillRect(Rect* rect, uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha=255);
    
    ///Creates a new surface from a stored Bitmap image.
    ///@param filename A string storing the path to the Bitmap
    static Surface* loadFromFile(String filename);
    
    Window* getWindow() {
        return m_Window;
    }
    
#ifdef USING_SDL
    void setTexture(SDL_Texture* newTexture);
    
    SDL_Texture* getTexture();
#endif

private:
    /// Disable default constructor
    Surface();

    cSizeInt m_Size;
    
    Window* m_Window;
#ifdef USING_SDL
    SDL_Texture* m_Texture;
#endif
};

}

#endif // SURFACE__H


