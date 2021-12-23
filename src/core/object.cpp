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

#include "object.h"

using namespace cerritos;

cObject::cObject() {
    m_Parent = NULL;
};

cObject::cObject(cObject* parent) : m_Parent(parent) {
    if(parent != NULL)
        parent->addChild(this);
}

void cObject::addChild(cObject* newChild) {
    //for (auto i = m_Children.begin(); i != m_Children.end(); ++i) {
    //    if(*i == newChild)
    //        return;
    //}
    
    //m_Children.push_back(newChild);
}

void cObject::reparent(cObject* newParent) {
    // First let the old parent know we're leaving their family
    if(m_Parent != NULL) {
        m_Parent->removingObject(this);
    }
    
    // Now join the new parent
    newParent->addChild(this);
    m_Parent = newParent;
}


