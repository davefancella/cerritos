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

/** The base class for all cerritos objects.  This class 
 *  provides parent/child relationship management and should
 *  be used wherever such relationships are needed.  It's
 *  used extensively in the widget subsystem.
 */
class Object {
public:
    /**
     * Default constructor.  It does not parent the object,
     * so should only be used for the top-level object in
     * a hierarchy.
     */
    Object();
    
    /**
     * The constructor the provides parentage for your
     * object.  It will automatically add itself as
     * a child to the parent provided.
     * 
     * @param parent the parent for this object
     */
    Object(Object* parent);
    
    /// Adds a child to the object
    void addChild(Object* newChild);
    
    /// Changes the parent of this widget
    void reparent(Object* newParent);
    
    /** 
     * Called whenever a child is removed from this object.
     * It allows for any last-minute work the object needs
     * to do before it loses a child.
     */
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

