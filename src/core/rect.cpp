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

#include "rect.h"

using namespace cerritos;

Rect::Rect(int x, int y, int w, int h) { 
    position.setX(x);
    position.setY(y);
    size.width = w;
    size.height = h;
}

bool Rect::overlaps(Rect& other) {
    if( position.x() > (other.position.x() + other.size.width) ||
        position.y() > (other.position.y() + other.size.height) ||
        (position.x() + size.width) < other.position.x() ||
        (position.y() + size.height) < other.position.y() ) {
        return false;
    }
    
    return true;
}

Rect Rect::operator+(PointInt& other) {
    return Rect(position.x() + other.x(), position.y() + other.y(),
        size.width, size.height
    );
}

Rect Rect::operator-(PointInt& other) {
    return Rect(position.x() - other.x(), position.y() - other.y(),
        size.width, size.height
    );
}

Rect Rect::operator+(const cSizeInt& other) {
    return Rect(position.x(), position.y(),
        size.width + other.width, size.height + other.height);
}

Rect Rect::operator-(const cSizeInt& other) {
    return Rect(position.x(), position.y(),
        size.width - other.width, size.height - other.height);
}


