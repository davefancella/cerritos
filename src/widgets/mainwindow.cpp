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

#include "stdio.h"

#include "mainwindow.h"

cMainWindow::cMainWindow() {
    this->window = SDL_CreateWindow( "SDL Tutorial", 
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
            800, 600, SDL_WINDOW_SHOWN );

    if( this->window == NULL ) {
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
    } else {
        //Get window surface
        this->screenSurface = SDL_GetWindowSurface( this->window );

        //Fill the surface black
        SDL_FillRect( this->screenSurface, NULL, 
                      SDL_MapRGB( this->screenSurface->format, 
                                  0x00, 0x00, 0x00 ) );
        
    }
}

void cMainWindow::Update() {
        //Update the surface
        SDL_UpdateWindowSurface( this->window );    
}

