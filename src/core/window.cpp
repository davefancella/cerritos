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

#include <iostream>

#include "SDL.h"

#include "backend.h"
#include "window.h"

using namespace cerritos;

Window::Window(String title, int posx, int posy, int width, int height, CER_WindowFlags winFlags)
            : Title(title), width(width), height(height), 
                posx(posx), posy(posy),
                windowFlags(winFlags) {
#ifdef USING_SDL
    m_Window = SDL_CreateWindow( this->Title.data(), 
            this->posx, this->posy,
            this->width, this->height, this->windowFlags);
    
    // Check for an error first
    if( m_Window == NULL ) {
        m_IsValid = false;
        std::cout << "Window could not be created! Backend: " <<
            GetError() << std::endl;
    } else {
        // This is when the window is created successfully
        m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);
        SDL_SetRenderDrawColor(m_Renderer, 0,0,0,255);
    }
#endif
}


