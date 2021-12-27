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

namespace cerritos {

/**
 * The base class for points.  Since every type of point is
 * different enough, the base class doesn't do anything. It
 * exists to allow for classes to store pointers to a point
 * without needing to know the details of the point.
 * 
 * So, a class can store a pointer to a point without getting
 * the point.
 */
class Point {
    
};

/**
 * An integer point.  It is a two dimensional point, usually
 * referring to a point on the screen.  It is written under
 * the assumption that it usually means screen coordinates.
 */
class PointInt : public Point {
public:
    PointInt() : x(0), y(0) { };
    PointInt(int x, int y);
    
    int x;
    int y;
    
    double distance(PointInt other);
    
    // operators
    PointInt operator+(const PointInt& other);
    PointInt operator-(const PointInt& other);
};

/**
 * A size, given as width x height.  It subclasses Point just
 * to allow pointers to be held to it without knowing the
 * details.  This is usually pointless, as size is pointless,
 * i.e. it's not a Point.
 */
class cSizeInt : public Point {
public:
    cSizeInt() : width(0), height(0) { };
    cSizeInt(int width, int height);
    
    int width;
    int height;
    
    cSizeInt operator+(const PointInt& other);
    cSizeInt operator+(const cSizeInt& other);
    cSizeInt operator-(const cSizeInt& other);
};

}

#endif // POINT__H


