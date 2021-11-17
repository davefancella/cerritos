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

#include "backend.h"

#include "cerritos.h"
#include "mainwindow.h"
#include "surface.h"

void cMainWindow::onMouseOver(cMouseMotionEvent* evt) {

}

void cMainWindow::setTitle(unicodestring title) {
    this->Title = title;
    
    SDL_SetWindowTitle(this->window, title.data() );
}

void cMainWindow::setPosition(int posx, int posy) {
    this->posx = posx;
    this->posy = posy;
    
    this->Move();
}

void cMainWindow::setSize(int width, int height) {
    this->width = width;
    this->height = height;
    
    this->Move();
}

void cMainWindow::Move() {
#ifdef USING_SDL
    SDL_SetWindowPosition(this->window, this->posx, this->posy);
    SDL_SetWindowSize(this->window, this->width, this->height);
#endif
}

cMainWindow::cMainWindow(CER_WindowFlags winFlags) 
            : Title("Cerritos Window"), width(800), height(600), 
                posx(CER_WindowPos_Centered), posy(CER_WindowPos_Centered),
                windowFlags(winFlags) {
    this->window = CreateWindow( this->Title, 
            this->posx, this->posy,
            this->width, this->height, this->windowFlags );
    
    if( this->window == NULL ) {
        std::cout << "Window could not be created! Backend: " <<
            GetError() << std::endl;
    } else {
        //Get window surface
        this->screenSurface = new cSurface(this->window);
    }
}

cMainWindow::cMainWindow(unicodestring title, CER_WindowFlags winFlags) 
            : Title(title), width(800), height(600), 
                posx(CER_WindowPos_Centered), posy(CER_WindowPos_Centered),
                windowFlags(winFlags) {
    this->window = CreateWindow( this->Title, 
            this->posx, this->posy,
            this->width, this->height, SDL_WINDOW_SHOWN );

    if( this->window == NULL ) {
        std::cout << "Window could not be created! Backend: " <<
            GetError() << std::endl;
    } else {
        //Get window surface
        this->screenSurface = new cSurface(this->window);
    }
}

cMainWindow::cMainWindow(unicodestring title, int width, int height, CER_WindowFlags winFlags) 
            : Title(title), width(width), height(height), 
                posx(CER_WindowPos_Centered), posy(CER_WindowPos_Centered),
                windowFlags(winFlags) {
    this->window = CreateWindow( this->Title, 
            this->posx, this->posy,
            this->width, this->height, SDL_WINDOW_SHOWN );

    if( this->window == NULL ) {
        std::cout << "Window could not be created! Backend: " <<
            GetError() << std::endl;
    } else {
        //Get window surface
        this->screenSurface = new cSurface(this->window);
    }
}

cMainWindow::cMainWindow(unicodestring title, int width, int height, int posx, int posy, CER_WindowFlags winFlags) 
            : Title(title), width(width), height(height), 
                posx(posx), posy(posy),
                windowFlags(winFlags) {
    this->window = CreateWindow( this->Title, 
            this->posx, this->posy,
            this->width, this->height, SDL_WINDOW_SHOWN );

    if( this->window == NULL ) {
        std::cout << "Window could not be created! Backend: " <<
            GetError() << std::endl;
    } else {
        //Get window surface
        this->screenSurface = new cSurface(this->window);
    }
}

cMainWindow::~cMainWindow() {
    DestroyWindow(this->window);
}

void cMainWindow::Update() {
    //Fill the surface black
    this->screenSurface->Fill(0, 0, 0);
    this->Render();
}

void cMainWindow::Render() {
#ifdef USING_SDL
    //Update the surface
    if(SDL_UpdateWindowSurface( this->window ) != 0) {
        std::cout << "cMainWindow: " << GetError() << std::endl;
    }
#endif
}


