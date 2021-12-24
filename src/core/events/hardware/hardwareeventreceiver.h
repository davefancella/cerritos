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
    
    virtual void onQuit(QuitEvent* event) { };

    virtual void onWindowShown(WindowShownEvent* event) { };

    virtual void onWindowHidden(WindowHiddenEvent* event) { };

    virtual void onWindowExposed(WindowExposedEvent* event) { };

    virtual void onWindowMoved(WindowMovedEvent* event) { };

    virtual void onWindowResized(WindowResizedEvent* event) { };

    virtual void onWindowSizeChanged(WindowSizeChangedEvent* event) { };

    virtual void onWindowMinimized(WindowMinimizedEvent* event) { };

    virtual void onWindowMaximized(WindowMaximizedEvent* event) { };

    virtual void onWindowRestored(WindowRestoredEvent* event) { };

    virtual void onWindowEnter(WindowEnterEvent* event) { };

    virtual void onWindowLeave(WindowLeaveEvent* event) { };

    virtual void onWindowFocusGained(WindowFocusGainedEvent* event) { };

    virtual void onWindowFocusLost(WindowFocusLostEvent* event) { };

    virtual void onWindowClose(WindowCloseEvent* event) { };

    virtual void onWindowTakeFocus(WindowTakeFocusEvent* event) { };

    virtual void onWindowHitTest(WindowHitTestEvent* event) { };

    virtual void onKeydown(KeydownEvent* event) { };

    virtual void onKeyup(KeyupEvent* event) { };

    virtual void onTextEditing(TextEditingEvent* event) { };

    virtual void onTextInput(TextInputEvent* event) { };

    virtual void onKeymapchanged(KeymapchangedEvent* event) { };

    virtual void onMouseButtondown(MouseButtondownEvent* event) { };

    virtual void onMouseMotion(MouseMotionEvent* event) { };

    virtual void onMouseButtonup(MouseButtonupEvent* event) { };

    virtual void onMouseWheel(MouseWheelEvent* event) { };

    virtual void onJoyAxisMotion(JoyAxisMotionEvent* event) { };

    virtual void onJoyBallMotion(JoyBallMotionEvent* event) { };

    virtual void onJoyHatMotion(JoyHatMotionEvent* event) { };

    virtual void onJoyButtondown(JoyButtondownEvent* event) { };

    virtual void onJoyButtonup(JoyButtonupEvent* event) { };

    virtual void onJoyDeviceAdded(JoyDeviceAddedEvent* event) { };

    virtual void onJoyDeviceRemoved(JoyDeviceRemovedEvent* event) { };

    virtual void onControllerAxisMotion(ControllerAxisMotionEvent* event) { };

    virtual void onControllerButtondown(ControllerButtondownEvent* event) { };

    virtual void onControllerButtonup(ControllerButtonupEvent* event) { };

    virtual void onControllerDeviceAdded(ControllerDeviceAddedEvent* event) { };

    virtual void onControllerDeviceRemoved(ControllerDeviceRemovedEvent* event) { };

    virtual void onControllerDeviceRemapped(ControllerDeviceRemappedEvent* event) { };

    virtual void onFingerdown(FingerdownEvent* event) { };

    virtual void onFingerup(FingerupEvent* event) { };

    virtual void onFingerMotion(FingerMotionEvent* event) { };

    virtual void onDollarGesture(DollarGestureEvent* event) { };

    virtual void onDollarRecord(DollarRecordEvent* event) { };

    virtual void onMultiGesture(MultiGestureEvent* event) { };

    virtual void onClipboardUpdate(ClipboardUpdateEvent* event) { };

    virtual void onDropFile(DropFileEvent* event) { };

    virtual void onDropText(DropTextEvent* event) { };

    virtual void onDropBegin(DropBeginEvent* event) { };

    virtual void onDropComplete(DropCompleteEvent* event) { };

    virtual void onAudioDeviceAdded(AudioDeviceAddedEvent* event) { };

    virtual void onAudioDeviceRemoved(AudioDeviceRemovedEvent* event) { };

    virtual void onRenderTargetsReset(RenderTargetsResetEvent* event) { };

    virtual void onRenderDeviceReset(RenderDeviceResetEvent* event) { };

};

}

#endif // HARDWAREEVENTRECEIVER__H


