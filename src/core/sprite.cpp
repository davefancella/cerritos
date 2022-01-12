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

double CCW(PointInt a, PointInt b, PointInt c) { return (b.x()-a.x())*(c.y()-a.y()) - (b.y()-a.y())*(c.x()-a.x()); };

int middle(int a, int b, int c) {
  int t;    
  if ( a > b ) {
    t = a;
    a = b;
    b = t;
  }
  if ( a <= c && c <= b ) return 1;
  return 0;
}

int intersect(Line a, Line b) {
  if ( ( CCW(a.s, a.e, b.s) * CCW(a.s, a.e, b.e) < 0 ) &&
     ( CCW(b.s, b.e, a.s) * CCW(b.s, b.e, a.e) < 0 ) ) return 1;

  if ( CCW(a.s, a.e, b.s) == 0 && middle(a.s.x(), a.e.x(), b.s.x()) && middle(a.s.y(), a.e.y(), b.s.y()) ) return 1;
  if ( CCW(a.s, a.e, b.e) == 0 && middle(a.s.x(), a.e.x(), b.e.x()) && middle(a.s.y(), a.e.y(), b.e.y()) ) return 1;
  if ( CCW(b.s, b.e, a.s) == 0 && middle(b.s.x(), b.e.x(), a.s.x()) && middle(b.s.y(), b.e.y(), a.s.y()) ) return 1;
  if ( CCW(b.s, b.e, a.e) == 0 && middle(b.s.x(), b.e.x(), a.e.x()) && middle(b.s.y(), b.e.y(), a.e.y()) ) return 1;

    return 0;
}


Sprite::Sprite(Window* window, int x, int y, int w, int h, int fps) {
    m_Position.setX(x);
    m_Position.setY(y);
    m_Size.width = w;
    m_Size.height = h;
    m_Surface = NULL;
    m_Fps = fps;
    m_CurrentFrame = 0;
    m_Window = window;
    int m_w = w;
    int m_h = h;
    m_xVelocity = 0; m_yVelocity = 0;
    
}

Sprite::~Sprite() {
    m_Surface->~Surface();
}

void Sprite::Render() {
    PointInt* drawPos = new PointInt(m_Position.x() - m_Origin.x(),
                                     m_Position.y() - m_Origin.y());
    if(m_Surface != NULL) {
        m_Surface->Blit_To(drawPos, m_Heading, &m_Origin);
    }
    
}

void Sprite::addSpriteMode(int mode, List<String> frames) {
    List<Surface*> tempList;
    for (int frame = 0; frame != frames.size(); frame++) {
        Surface* surf = Surface::loadFromFile(frames[frame]);
        
        if(surf != NULL) {
            m_Size = surf->size();
            m_Origin = PointInt(m_Size.width/2, m_Size.height/2);
            m_Radius = m_Origin.distance(PointInt(0, 0));
            tempList.push_back(surf);
        }
    }
    m_Modes.insert({mode, tempList});
}

double Sprite::distance(Sprite* other) {
    return m_Position.distance(other->getPosition() );
}

void Sprite::Update(const Timestep timestep) {
    m_previousPosition.setX(m_Position.x() );
    m_previousPosition.setY(m_Position.y() );
    
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
    
    //m_Position.setX(m_Position.x() + m_xVelocity);
    //m_Position.setY(m_Position.y() + m_yVelocity);
    
}

void Sprite::setDefaultMode(int mode) {
    m_DefaultMode = mode;
}

void Sprite::setMode(int mode) {
    m_Mode = mode;
}

Rect& Sprite::getRect() {
    Rect* aRect = new Rect(
        m_Position.x(),
        m_Position.y(),
        m_Size.width,
        m_Size.height );
    
    return *aRect;
}

Collision* Sprite::GetCollideRect(Sprite* other) {
    bool collided = getRect().overlaps(other->getRect());
    Collision* collide;
    if (collided) {
        collide = new Collision(m_Position, Vector<double>(m_Position.x() - m_previousPosition.x(),
                                                        m_Position.y() - m_previousPosition.y()));
    } else {
        collide = NULL;
    }
    
    return collide;
}

Collision* Sprite::GetCollideCircle(Sprite* other) {
    Collision* collide;
    double dist = this->distance(other);
    if (dist <= m_Radius + other->getRadius()) {
        collide = new Collision( m_Position, Vector<double>( (other->getPosition().x() - m_Position.x()) / dist,
                                                          (other->getPosition().y() - m_Position.y()) / dist ) );
    } else {
        collide = NULL;
    }
    return collide;
}


Line Sprite::getSide(String side) {
    Line line;
    if (side == "top") {
        line.s = m_Position;
        line.e = PointInt(m_Position.x() + m_Size.width, m_Position.y());
    } else if (side == "bottom") {
        line.s = PointInt(m_Position.x(), m_Position.y() + m_Size.height);
        line.e = PointInt(m_Position.x() + m_Size.width, m_Position.y() + m_Size.height);
    } else if (side == "left") {
        line.s = m_Position;
        line.e = PointInt(m_Position.x(), m_Position.y() + m_Size.height);
    } else if (side == "right") {
        line.s = PointInt(m_Position.x() + m_Size.width, m_Position.y());
        line.e = PointInt(m_Position.x() + m_Size.width, m_Position.y() + m_Size.height);
    }
    
    return line;
}

Line Sprite::getMove() {
    Line line;
    PointInt slope = PointInt(m_Position.x() - m_previousPosition.x(), m_Position.y() - m_previousPosition.y());
    PointInt previous = PointInt(m_previousPosition.x() + slope.x(), m_previousPosition.y() + slope.y());
    PointInt current = PointInt(m_Position.x() - slope.x(), m_Position.y() - slope.y());
    line.s = previous;
    line.e = current;
    
    return line;
}


