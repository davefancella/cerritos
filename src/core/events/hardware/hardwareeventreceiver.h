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

#ifndef HARDWAREEVENTRECEIVER__H
#define HARDWAREEVENTRECEIVER__H

#include "event.h"

// This file is periodically generated.  Do not edit it directly.

namespace cerritos {

class cHardwareEventReceiver {
public:
    cHardwareEventReceiver() { };
    
    virtual void onQuit(cQuitEvent* event) { };

    virtual void onWindowShown(cWindowShownEvent* event) { };

    virtual void onWindowHidden(cWindowHiddenEvent* event) { };

    virtual void onWindowExposed(cWindowExposedEvent* event) { };

    virtual void onWindowMoved(cWindowMovedEvent* event) { };

    virtual void onWindowResized(cWindowResizedEvent* event) { };

    virtual void onWindowSizeChanged(cWindowSizeChangedEvent* event) { };

    virtual void onWindowMinimized(cWindowMinimizedEvent* event) { };

    virtual void onWindowMaximized(cWindowMaximizedEvent* event) { };

    virtual void onWindowRestored(cWindowRestoredEvent* event) { };

    virtual void onWindowEnter(cWindowEnterEvent* event) { };

    virtual void onWindowLeave(cWindowLeaveEvent* event) { };

    virtual void onWindowFocusGained(cWindowFocusGainedEvent* event) { };

    virtual void onWindowFocusLost(cWindowFocusLostEvent* event) { };

    virtual void onWindowClose(cWindowCloseEvent* event) { };

    virtual void onWindowTakeFocus(cWindowTakeFocusEvent* event) { };

    virtual void onWindowHitTest(cWindowHitTestEvent* event) { };

    virtual void onKeydown(cKeydownEvent* event) { };

    virtual void onKeyup(cKeyupEvent* event) { };

    virtual void onTextEditing(cTextEditingEvent* event) { };

    virtual void onTextInput(cTextInputEvent* event) { };

    virtual void onKeymapchanged(cKeymapchangedEvent* event) { };

    virtual void onMouseButtondown(cMouseButtondownEvent* event) { };

    virtual void onMouseMotion(cMouseMotionEvent* event) { };

    virtual void onMouseButtonup(cMouseButtonupEvent* event) { };

    virtual void onMouseWheel(cMouseWheelEvent* event) { };

    virtual void onJoyAxisMotion(cJoyAxisMotionEvent* event) { };

    virtual void onJoyBallMotion(cJoyBallMotionEvent* event) { };

    virtual void onJoyHatMotion(cJoyHatMotionEvent* event) { };

    virtual void onJoyButtondown(cJoyButtondownEvent* event) { };

    virtual void onJoyButtonup(cJoyButtonupEvent* event) { };

    virtual void onJoyDeviceAdded(cJoyDeviceAddedEvent* event) { };

    virtual void onJoyDeviceRemoved(cJoyDeviceRemovedEvent* event) { };

    virtual void onControllerAxisMotion(cControllerAxisMotionEvent* event) { };

    virtual void onControllerButtondown(cControllerButtondownEvent* event) { };

    virtual void onControllerButtonup(cControllerButtonupEvent* event) { };

    virtual void onControllerDeviceAdded(cControllerDeviceAddedEvent* event) { };

    virtual void onControllerDeviceRemoved(cControllerDeviceRemovedEvent* event) { };

    virtual void onControllerDeviceRemapped(cControllerDeviceRemappedEvent* event) { };

    virtual void onFingerdown(cFingerdownEvent* event) { };

    virtual void onFingerup(cFingerupEvent* event) { };

    virtual void onFingerMotion(cFingerMotionEvent* event) { };

    virtual void onDollarGesture(cDollarGestureEvent* event) { };

    virtual void onDollarRecord(cDollarRecordEvent* event) { };

    virtual void onMultiGesture(cMultiGestureEvent* event) { };

    virtual void onClipboardUpdate(cClipboardUpdateEvent* event) { };

    virtual void onDropFile(cDropFileEvent* event) { };

    virtual void onDropText(cDropTextEvent* event) { };

    virtual void onDropBegin(cDropBeginEvent* event) { };

    virtual void onDropComplete(cDropCompleteEvent* event) { };

    virtual void onAudioDeviceAdded(cAudioDeviceAddedEvent* event) { };

    virtual void onAudioDeviceRemoved(cAudioDeviceRemovedEvent* event) { };

    virtual void onRenderTargetsReset(cRenderTargetsResetEvent* event) { };

    virtual void onRenderDeviceReset(cRenderDeviceResetEvent* event) { };

};

}

#endif // HARDWAREEVENTRECEIVER__H


