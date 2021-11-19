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
#include "window.h"
#include "mainwindow.h"
#include "surface.h"

void cMainWindow::onMouseOver(cMouseMotionEvent* evt) {

}

void cMainWindow::setTitle(unicodestring title) {
    this->Title = title;
    
    //SDL_SetWindowTitle(this->window, title.data() );
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
    //SDL_SetWindowPosition(this->window, this->posx, this->posy);
    //SDL_SetWindowSize(this->window, this->width, this->height);
#endif
}

cMainWindow::cMainWindow(CER_WindowFlags winFlags) 
            : Title("Cerritos Window"), width(800), height(600), 
                posx(CER_WindowPos_Centered), posy(CER_WindowPos_Centered),
                windowFlags(winFlags) {
    this->window = new cWindow( this->Title, 
            this->posx, this->posy,
            this->width, this->height, this->windowFlags );
    
}

cMainWindow::cMainWindow(unicodestring title, CER_WindowFlags winFlags) 
            : Title(title), width(800), height(600), 
                posx(CER_WindowPos_Centered), posy(CER_WindowPos_Centered),
                windowFlags(winFlags) {
    this->window = new cWindow( this->Title, 
            this->posx, this->posy,
            this->width, this->height, this->windowFlags );
}

cMainWindow::cMainWindow(unicodestring title, int width, int height, CER_WindowFlags winFlags) 
            : Title(title), width(width), height(height), 
                posx(CER_WindowPos_Centered), posy(CER_WindowPos_Centered),
                windowFlags(winFlags) {
    this->window = new cWindow( this->Title, 
            this->posx, this->posy,
            this->width, this->height, this->windowFlags );
}

cMainWindow::cMainWindow(unicodestring title, int width, int height, int posx, int posy, CER_WindowFlags winFlags) 
            : Title(title), width(width), height(height), 
                posx(posx), posy(posy),
                windowFlags(winFlags) {
    this->window = new cWindow( this->Title, 
            this->posx, this->posy,
            this->width, this->height, this->windowFlags );
}

cMainWindow::~cMainWindow() {
    delete this->window;
}

void cMainWindow::Update() {
}

void cMainWindow::Render() {
    // Do nothing.
}

void cMainWindow::renderAll() {
    this->beginRender();
    this->Render();
    this->guiRender();
    this->finishRender();
}

void cMainWindow::beginRender() {
#ifdef USING_SDL
    SDL_RenderClear(this->window->getSDLRenderer() );
#endif
}

void cMainWindow::guiRender() {
    for (auto i = mChildren.begin(); i != mChildren.end(); ++i) {
        static_cast<cWidget*>(*i)->Render_To(this->window);
    }
}

void cMainWindow::finishRender() {
#ifdef USING_SDL
    SDL_RenderPresent(this->window->getSDLRenderer() );
#endif
}

cWindow* cMainWindow::getWindow() { 
    return this->window; 
}

