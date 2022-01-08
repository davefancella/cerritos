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

#ifndef POINTTEMPLATE__H
#define POINTTEMPLATE__H

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
template <typename T>
class Point {
public:
    T m_X;
    T m_Y;

    Point();
    Point(T x, T y);

    double distance(Point<T> other);
    
    // operators
    Point<T> operator+(const Point<T>& other);
    Point<T> operator-(const Point<T>& other);
};

template <typename T>
class Vector : public Point<T> {
    double magnitude() {
        return distance(Point<T>(0,0) );
    }
};

}

#endif // POINTTEMPLATE__H


