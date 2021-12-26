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

#include "sprite.h"

using namespace cerritos;

Sprite::Sprite(Window* window, int x, int y, int w, int h) {
    m_Rect = new Rect(x, y, w, h);
    m_Surface = NULL;
//    m_Fps = fps;
    m_CurrentFrame = 0;
    m_Window = window;
    
}

Sprite::~Sprite() {
    m_Surface->~Surface();
}

void Sprite::Draw() {
    if (m_Rect != NULL) {
        m_Surface->Blit_To(m_Rect);
    }
}
    
void Sprite::addFrame(String pathToFrame) {
    Surface* newSurface = Surface::loadFromFile(m_Window, pathToFrame);
    m_Frames.push_back(newSurface);
}

void Sprite::update() {
    m_CurrentFrame++;
    if (m_CurrentFrame > m_Frames.size()) {
        m_CurrentFrame = 0;
    }
    
    std::cout << m_Surface;
    
    m_Surface = m_Frames[m_CurrentFrame];
}

