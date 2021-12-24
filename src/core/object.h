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

#ifndef CERRITOSCORE_H
#define CERRITOSCORE_H

#include "types.h"

namespace cerritos {

/** The base class for all cerritos objects
 */
class Object {
public:
    Object();
    Object(Object* parent);
    
    /// Adds a child to the object
    void addChild(Object* newChild);
    
    /// Changes the parent of this widget
    void reparent(Object* newParent);
    
    /// Call whenever you're removing a child from somewhere other than
    /// this class.
    void removingObject(Object* theChild) { };
    
    /// Call to update an object in a game loop.  Not all objects need this.
    virtual void Update() { };
    
protected:
    Object* m_Parent;
    List<Object*> m_Children;
};

/** Timesteps are such an integral part of everything that happens in a game
 *  that the timestep class is included here.
 */
class TimeStep {
public:   
    unsigned int fromBeginning;
    unsigned int fromLast;
};

}

#endif

