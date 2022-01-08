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

#include <cmath>

#include "point.h"

using namespace cerritos;

PointInt::PointInt(int x, int y) : x(x), y(y) { }

double PointInt::distance(PointInt other) {
    return sqrt( pow(other.x - x, 2) + pow(other.y - y, 2) );
}

PointInt PointInt::operator+(const PointInt& other) {
    return PointInt(this->x + other.x, this->y + other.y);
}

PointInt PointInt::operator-(const PointInt& other) {
    return PointInt(this->x - other.x, this->y - other.y);
}

cSizeInt::cSizeInt(int width, int height) : width(width), height(height) { }

cSizeInt cSizeInt::operator+(const cSizeInt& other) {
    return cSizeInt(this->width + other.width, this->height + other.height);
}

cSizeInt cSizeInt::operator-(const cSizeInt& other) {
    return cSizeInt(this->width - other.width, this->height - other.height);
}

FloatVector::FloatVector(double x, double y) : x(x), y(y) { }

FloatVector FloatVector::operator+(const FloatVector& other) {
    return FloatVector(this->x + other.y, this->y + other.y);
}

FloatVector FloatVector::operator-(const FloatVector& other) {
    return FloatVector(this->x - other.x, this->y - other.y);
}


