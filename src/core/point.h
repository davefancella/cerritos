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

#ifndef POINT__H
#define POINT__H

#include <math.h>

namespace cerritos {

template <typename T>
class Vector {
public:
    T m_X;
    T m_Y;

    Vector() { };
    Vector(T x, T y) : m_X(x), m_Y(y) { };

    T x() { return m_X; };
    T y() { return m_Y; };
    void setX(T newX) { m_X = newX; };
    void setY(T newY) { m_Y = newY; };
    
    double distance(Vector<T> other) {
        return sqrt( pow(other.x() - x(), 2) + pow(other.y() - y(), 2) );
    };
    
    double magnitude() {
        return sqrt( pow(x(), 2) + pow(y(), 2) );
    }

    // operators
    Vector<T> operator+(const Vector<T>& other) {
        return Vector<T>(x() + other.x(), y() + other.y() );
    };
    
    Vector<T> operator-(const Vector<T>& other) {
        return Vector<T>(x() - other.x(), y() - other.y() );
    };
};

/// A Point is just a position vector
template<typename T>
using Point = Vector<T>;

/// A Point is just a position vector
using PointInt = Vector<int>;

/**
 * A size, given as width x height.
 */
class cSizeInt {
public:
    cSizeInt() : width(0), height(0) { };
    cSizeInt(int width, int height) : width(width), height(height) { };
    cSizeInt(cSizeInt& other) {
        width = other.width;
        height = other.height;
    };
    
    int width;
    int height;
    
    cSizeInt operator+(const cSizeInt& other) {
        return cSizeInt(width + other.width, height + other.height );
    };
    
    cSizeInt operator-(const cSizeInt& other) {
        return cSizeInt(width - other.width, height - other.height );
    };
};

}

#endif // POINT__H


