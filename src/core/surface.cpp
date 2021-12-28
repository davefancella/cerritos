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
#include "imagemanager.h"
#include "window.h"
#include "rect.h"
#include "point.h"

#ifdef USING_SDL
#include "sdl_backend.h"
#endif

using namespace cerritos;

Surface::Surface(Window* window) 
            : m_Window(window) {
#ifdef USING_SDL
    m_Texture = SDL_CreateTexture(window->getSDLRenderer(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 1024, 768);
#endif
}


Surface::~Surface() {
#ifdef USING_SDL
    if(m_Texture != NULL)
        SDL_DestroyTexture(m_Texture);
#endif
}

void Surface::Blit_To(PointInt* dest, const double angle, const PointInt *center, CER_RenderFlags flip) {
#ifdef USING_SDL
    SDL_Rect aRect = { dest->x, dest->y, 
                       m_Size.width, m_Size.height };
    SDL_Point aPoint = {0,0};
    
    if(center != NULL) {
        aPoint.x = center->x;
        aPoint.y = center->y;
    }
                       
    SDL_RenderCopyEx(m_Window->getSDLRenderer(), 
                   m_Texture, 
                   NULL, 
                   &aRect,
                   angle,
                   &aPoint,
                   static_cast<SDL_RendererFlip>(flip) );
#endif
}

void Surface::Fill(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) { 
    this->FillRect(NULL, red, green, blue, alpha); 
}

void Surface::FillRect(const Rect* rect, uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) {
#ifdef USING_SDL
    // cache the current render target so we can restore it later
    SDL_Texture* renderCache = SDL_GetRenderTarget(m_Window->getSDLRenderer() );
    // change the render target so we can fill the rect
    if(SDL_SetRenderTarget(m_Window->getSDLRenderer(), m_Texture) == 0) {
        SDL_Rect aRect = { rect->position.x, rect->position.y, 
                           rect->size.width, rect->size.height };
        SDL_SetRenderDrawColor(m_Window->getSDLRenderer(), red, green, blue, alpha);
        SDL_RenderFillRect(m_Window->getSDLRenderer(), &aRect);

        // restore the cached render target
        SDL_SetRenderTarget(m_Window->getSDLRenderer(), renderCache);
    }
#endif
}

Surface* Surface::loadFromFile(String filename) {
    ImageManager img = ImageManager::get();

    return img.loadImageFromFile(filename);
}
    
    
