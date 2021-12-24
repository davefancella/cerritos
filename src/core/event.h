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

#include <queue>

#include "backend.h"

#ifndef EVENT__H
#define EVENT__H

namespace cerritos {

typedef enum {
    // hardwareenum is generated and comes from the backend.
    // It contains CER_* event types for hardware events.
    HARDWAREENUM
} CER_EventType;

/// The base class for events.
class Event {
public:
    CER_EventType type() { return this->evtype; };
    
    bool isActive() { return this->active; };
    
protected:
    CER_EventType evtype;
    bool active = true;
};

/// The class that manages the event queue
class EventManager {
public:
    void addEvent(Event* event);
    bool hasEvent();
    Event* popEvent();
private:
    std::queue<Event*> eventQueue;
};

}

// Now include all the specific event headers
#include "hardwareevents.h"

#endif // HEADER__H


