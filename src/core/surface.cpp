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
#include "window.h"
#include "rect.h"

#ifdef USING_SDL
#include "sdl_backend.h"
#endif

cSurface::cSurface(cWindow* window) 
            : mWindow(window) {
#ifdef USING_SDL
    this->mTexture = SDL_CreateTexture(window->getSDLRenderer(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 1024, 768);
#endif
}


cSurface::~cSurface() {
#ifdef USING_SDL
    if(this->mTexture != NULL)
        SDL_DestroyTexture(this->mTexture);
#endif
}

void cSurface::Blit_To(cRect* dest) {
#ifdef USING_SDL
    SDL_Rect aRect = { dest->position.x, dest->position.y, 
                       dest->size.width, dest->size.height };
    SDL_RenderCopy(this->mWindow->getSDLRenderer(), 
                   this->mTexture, 
                   NULL, 
                   &aRect);
#endif
}

void cSurface::Fill(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) { 
    this->FillRect(NULL, red, green, blue, alpha); 
}

void cSurface::FillRect(const cRect* rect, uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) {
#ifdef USING_SDL
    // cache the current render target so we can restore it later
    SDL_Texture* renderCache = SDL_GetRenderTarget(this->mWindow->getSDLRenderer() );
    // change the render target so we can fill the rect
    if(SDL_SetRenderTarget(this->mWindow->getSDLRenderer(), this->mTexture) == 0) {
        SDL_Rect aRect = { rect->position.x, rect->position.y, 
                           rect->size.width, rect->size.height };
        SDL_SetRenderDrawColor(this->mWindow->getSDLRenderer(), red, green, blue, alpha);
        SDL_RenderFillRect(this->mWindow->getSDLRenderer(), &aRect);

        // restore the cached render target
        SDL_SetRenderTarget(this->mWindow->getSDLRenderer(), renderCache);
    }
#endif
}



