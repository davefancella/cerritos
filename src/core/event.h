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

#ifndef EVENT__H
#define EVENT__H

typedef enum {
    CER_QuitEvent,
    CER_MouseOverEvent,
    // Keyboard events
    CER_KeydownEvent,
    CER_KeyupEvent,
    CER_TexteditingEvent,
    CER_TextinputEvent,
    CER_KeymapChangedEvent,
    // Mobile events for Android, iOS and WinRT
    CER_APP_TerminatingEvent,
    CER_APP_LowmemoryEvent,
    CER_APP_WillEnterBackgroundEvent,
    CER_APP_DidEnterBackgroundEvent,
    CER_APP_WillEnterForegroundEvent,
    CER_APP_DidEnterForegroundEvent,
} CER_EventType;

// The base class for events.
class cEvent {
public:
    CER_EventType type() { return this->evtype; };
    
    unsigned int timestamp() { return this->evtimestamp; };
    unsigned int windowId() { return this->evwindowId; };
    
protected:
    CER_EventType evtype;
    unsigned int evtimestamp;
    unsigned int evwindowId;
};

// The class that manages the event queue
class cEventManager {
public:
    void addEvent(cEvent* event);
    bool hasEvent();
    cEvent* popEvent();
private:
    std::queue<cEvent*> eventQueue;
};

// Now include all the specific event headers
#include "quitevent.h"
#include "mouseoverevent.h"
#include "keydownevent.h"
#include "keyupevent.h"

#endif // HEADER__H


