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

#include "cerritos.h"
#include "mainwindow.h"

cMainWindow::cMainWindow(CER_WindowFlags winFlags) 
            : Title("Cerritos Window"), width(800), height(600), 
                posx(SDL_WINDOWPOS_CENTERED), posy(SDL_WINDOWPOS_CENTERED),
                windowFlags(winFlags) {
    this->window = SDL_CreateWindow( this->Title.data(), 
            this->posx, this->posy,
            this->width, this->height, CER_Shown );

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

cMainWindow::cMainWindow(unicodestring title, CER_WindowFlags winFlags) 
            : Title(title), width(800), height(600), 
                posx(SDL_WINDOWPOS_CENTERED), posy(SDL_WINDOWPOS_CENTERED),
                windowFlags(winFlags) {
    this->window = SDL_CreateWindow( this->Title.data(), 
            this->posx, this->posy,
            this->width, this->height, SDL_WINDOW_SHOWN );

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

cMainWindow::cMainWindow(unicodestring title, int width, int height, CER_WindowFlags winFlags) 
            : Title(title), width(width), height(height), 
                posx(SDL_WINDOWPOS_CENTERED), posy(SDL_WINDOWPOS_CENTERED),
                windowFlags(winFlags) {
    this->window = SDL_CreateWindow( this->Title.data(), 
            this->posx, this->posy,
            this->width, this->height, SDL_WINDOW_SHOWN );

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

cMainWindow::cMainWindow(unicodestring title, int width, int height, int posx, int posy, CER_WindowFlags winFlags) 
            : Title(title), width(width), height(height), 
                posx(posx), posy(posy),
                windowFlags(winFlags) {
    this->window = SDL_CreateWindow( this->Title.data(), 
            this->posx, this->posy,
            this->width, this->height, SDL_WINDOW_SHOWN );

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

cMainWindow::~cMainWindow() {
    SDL_DestroyWindow(this->window);
}

void cMainWindow::Update() {
    //Fill the surface black
    SDL_FillRect( this->screenSurface, NULL, 
                    SDL_MapRGB( this->screenSurface->format, 
                                0, 0, 0 ) );
    
    //Update the surface
    if(SDL_UpdateWindowSurface( this->window ) != 0) {
        printf(SDL_GetError() );
    }
}

