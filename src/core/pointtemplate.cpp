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

#include "pointtemplate.h"

using namespace cerritos;

PointT<double> aPoint(0.0, 0.0);
VectorT<double> aVector(0.0, 0.0);

template <typename T>
PointT<T>::PointT(T x, T y) : m_X(x), m_Y(y) { 
}

template <typename T>
double PointT<T>::distance(PointT<T> other) {
    return sqrt( pow(other.m_X - m_X, 2) + pow(other.m_Y - m_Y, 2) );
}

template <typename T>
PointT<T> PointT<T>::operator+(const PointT<T>& other) {
    return PointT<T>(this->m_X + other.m_X, this->m_Y + other.m_Y);
}

template <typename T>
PointT<T> PointT<T>::operator-(const PointT<T>& other) {
    return PointT<T>(this->m_X - other.m_X, this->m_Y - other.m_Y);
}


