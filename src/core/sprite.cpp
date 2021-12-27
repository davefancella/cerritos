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
#include "point.h"

using namespace cerritos;

Sprite::Sprite(Window* window, int x, int y, int w, int h, int fps) {
    m_Position.x = x;
    m_Position.y = y;
    m_Size.width = w;
    m_Size.height = h;
    m_Surface = NULL;
    m_Fps = fps;
    m_CurrentFrame = 0;
    m_Window = window;
    int m_w = w;
    int m_h = h;
    
}

Sprite::~Sprite() {
    m_Surface->~Surface();
}

void Sprite::Draw() {
    PointInt* drawPos = new PointInt(m_Position.x - m_Origin.x,
                                     m_Position.y - m_Origin.y);
    m_Surface->Blit_To(drawPos, 0.0, &m_Origin);
}

void Sprite::addSpriteMode(int mode, List<String> frames) {
    List<Surface*> tempList;
    for (int frame = 0; frame != frames.size(); frame++) {
        Surface* surf = Surface::loadFromFile(m_Window, frames[frame]);
        m_Size = surf->size();
        m_Origin = PointInt(m_Size.width/2, m_Size.height/2);
        tempList.push_back(surf);
    }
    m_Modes.insert({mode, tempList});
}

double Sprite::distance(Sprite* other) {
    return m_Position.distance(other->getPosition() );
}

void Sprite::Update(const Timestep timestep) {
    int theMode = 0;
    if(m_Modes.has_key(m_Mode) ) {
        theMode = m_Mode;
    } else {
        cSTDOUT << "Improper mode for sprite selected" << EOL;
        m_Mode = m_DefaultMode;
        theMode = m_DefaultMode;
    }
    
    m_Frames = m_Modes[theMode];
    
    int dt = (timestep.fromBeginning / (1000 / m_Fps));
    m_CurrentFrame = dt % m_Frames.size();
    if (m_CurrentFrame >= m_Frames.size()) {
        m_CurrentFrame = 0;
    }
    
    m_Surface = m_Frames[m_CurrentFrame];
}

void Sprite::setDefaultMode(int mode) {
    m_DefaultMode = mode;
}

void Sprite::setMode(int mode) {
    m_Mode = mode;
}
