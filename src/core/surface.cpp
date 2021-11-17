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

#include "surface.h"
#include "rect.h"

#ifdef USING_SDL
#include "sdl_backend.h"
#endif

cSurface::~cSurface() {
#ifdef USING_SDL
    SDL_FreeSurface(this->mSurface);
#endif
}

void cSurface::Blit_To(cSurface* dest, cRect* rect) {
#ifdef USING_SDL
    SDL_Rect aRect = { rect->x, rect->y, rect->w, rect->h };
    SDL_BlitSurface(this->mSurface, NULL, dest->getSDLSurface(), &aRect);
#endif
}

void cSurface::Blit_From(cSurface* source, cRect* rect) {
#ifdef USING_SDL
    SDL_Rect aRect = { rect->x, rect->y, rect->w, rect->h };
    SDL_BlitSurface(source->getSDLSurface(), NULL, this->mSurface, &aRect);
#endif
}

void cSurface::Fill(uint8_t red, uint8_t green, uint8_t blue) { 
    this->FillRect(NULL, red, green, blue); 
}

void cSurface::FillRect(const cRect* rect, uint8_t red, uint8_t green, uint8_t blue) {
#ifdef USING_SDL
    if(rect != NULL) {
        SDL_Rect aRect = { rect->x, rect->y, rect->w, rect->h };
        SDL_FillRect( this->mSurface, &aRect, 
                        SDL_MapRGB( this->mSurface->format, 
                                    red, green, blue ) );
    } else {
        SDL_FillRect( this->mSurface, NULL, 
                        SDL_MapRGB( this->mSurface->format, 
                                    red, green, blue ) );
    }
#endif
}

#ifdef USING_SDL
// Constructor to be used for the mainwindow
cSurface::cSurface(SDL_Window* window) {
    this->mSurface = SDL_GetWindowSurface(
        window);
}

SDL_Surface* cSurface::getSDLSurface() {
    return this->mSurface;
}
#endif


