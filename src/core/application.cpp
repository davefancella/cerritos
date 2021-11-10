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

#include "SDL.h"

#include "application.h"

cApplication::cApplication() {
    unsigned int newTimestep = SDL_GetTicks();

    this->firstTimestep = newTimestep;
    
    this->currentTimestep.fromBeginning = 0;
    this->currentTimestep.fromLast = 0;
}

void cApplication::setMainWindow(cMainWindow* window) {
    this->mainwindow = window;
}

cMainWindow* cApplication::getMainWindow() {
    return this->mainwindow;
}

const TimeStep cApplication::getTimestep() {
    return this->currentTimestep;
}

void cApplication::BeginUpdate() {
    unsigned int newTimestep;
    
    newTimestep = SDL_GetTicks();
    
    this->currentTimestep.fromBeginning = newTimestep - this->firstTimestep;
    this->currentTimestep.fromLast = newTimestep - this->lastTimestep;
    
    this->lastTimestep = newTimestep;
}

void cApplication::Update() {
}

void cApplication::UpdateView() {
    if(this->mainwindow != NULL) {
        this->mainwindow->Update();
    }
}

void cApplication::UpdateAll() {
    this->BeginUpdate();
    this->Update();
    this->UpdateView();
    this->EndUpdate();
}

void cApplication::EndUpdate() {
    
}
