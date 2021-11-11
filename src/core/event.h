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
    CER_WindowEvent,
    CER_SyswmEvent,
    CER_TextEditingEvent,
    CER_TextInputEvent,
    CER_KeymapchangedEvent,
    CER_MouseMotionEvent,
    CER_MouseButtondownEvent,
    CER_MouseButtonupEvent,
    CER_MouseWheelEvent,
    CER_JoyAxisMotionEvent,
    CER_JoyBallMotionEvent,
    CER_JoyHatMotionEvent,
    CER_JoyButtondownEvent,
    CER_JoyButtonupEvent,
    CER_JoyDeviceAddedEvent,
    CER_JoyDeviceRemovedEvent,
    CER_ControllerAxisMotionEvent,
    CER_ControllerButtondownEvent,
    CER_ControllerButtonupEvent,
    CER_ControllerDeviceAddedEvent,
    CER_ControllerDeviceRemovedEvent,
    CER_ControllerDeviceRemappedEvent,
    CER_FingerdownEvent,
    CER_FingerupEvent,
    CER_FingerMotionEvent,
    CER_DollarGestureEvent,
    CER_DollarRecordEvent,
    CER_MultiGestureEvent,
    CER_ClipboardUpdateEvent,
    CER_DropFileEvent,
    CER_DropTextEvent,
    CER_DropBeginEvent,
    CER_DropCompleteEvent,
    CER_AudioDeviceAddedEvent,
    CER_AudioDeviceRemovedEvent,
    CER_RenderTargetsResetEvent,
    CER_RenderDeviceResetEvent,
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
#include "windowevent.h"
#include "syswmevent.h"
#include "keydownevent.h"
#include "keyupevent.h"
#include "texteditingevent.h"
#include "textinputevent.h"
#include "keymapchangedevent.h"
#include "mousemotionevent.h"
#include "mousebuttondownevent.h"
#include "mousebuttonupevent.h"
#include "mousewheelevent.h"
#include "joyaxismotionevent.h"
#include "joyballmotionevent.h"
#include "joyhatmotionevent.h"
#include "joybuttondownevent.h"
#include "joybuttonupevent.h"
#include "joydeviceaddedevent.h"
#include "joydeviceremovedevent.h"
#include "controlleraxismotionevent.h"
#include "controllerbuttondownevent.h"
#include "controllerbuttonupevent.h"
#include "controllerdeviceaddedevent.h"
#include "controllerdeviceremovedevent.h"
#include "controllerdeviceremappedevent.h"
#include "fingerdownevent.h"
#include "fingerupevent.h"
#include "fingermotionevent.h"
#include "dollargestureevent.h"
#include "dollarrecordevent.h"
#include "multigestureevent.h"
#include "clipboardupdateevent.h"
#include "dropfileevent.h"
#include "droptextevent.h"
#include "dropbeginevent.h"
#include "dropcompleteevent.h"
#include "audiodeviceaddedevent.h"
#include "audiodeviceremovedevent.h"
#include "rendertargetsresetevent.h"
#include "renderdeviceresetevent.h"

#endif // HEADER__H


