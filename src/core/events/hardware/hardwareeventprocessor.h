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

// This file is periodically generated.  Do not edit it directly.

#define PROCESSHARDWAREEVENTS \
        case CER_QuitEvent: \
            this->onQuit(static_cast<cQuitEvent*>(event) ); \
            break; \
        case CER_WindowShownEvent: \
            this->onWindowShown(static_cast<cWindowShownEvent*>(event) ); \
            break; \
        case CER_WindowHiddenEvent: \
            this->onWindowHidden(static_cast<cWindowHiddenEvent*>(event) ); \
            break; \
        case CER_WindowExposedEvent: \
            this->onWindowExposed(static_cast<cWindowExposedEvent*>(event) ); \
            break; \
        case CER_WindowMovedEvent: \
            this->onWindowMoved(static_cast<cWindowMovedEvent*>(event) ); \
            break; \
        case CER_WindowResizedEvent: \
            this->onWindowResized(static_cast<cWindowResizedEvent*>(event) ); \
            break; \
        case CER_WindowSizeChangedEvent: \
            this->onWindowSizeChanged(static_cast<cWindowSizeChangedEvent*>(event) ); \
            break; \
        case CER_WindowMinimizedEvent: \
            this->onWindowMinimized(static_cast<cWindowMinimizedEvent*>(event) ); \
            break; \
        case CER_WindowMaximizedEvent: \
            this->onWindowMaximized(static_cast<cWindowMaximizedEvent*>(event) ); \
            break; \
        case CER_WindowRestoredEvent: \
            this->onWindowRestored(static_cast<cWindowRestoredEvent*>(event) ); \
            break; \
        case CER_WindowEnterEvent: \
            this->onWindowEnter(static_cast<cWindowEnterEvent*>(event) ); \
            break; \
        case CER_WindowLeaveEvent: \
            this->onWindowLeave(static_cast<cWindowLeaveEvent*>(event) ); \
            break; \
        case CER_WindowFocusGainedEvent: \
            this->onWindowFocusGained(static_cast<cWindowFocusGainedEvent*>(event) ); \
            break; \
        case CER_WindowFocusLostEvent: \
            this->onWindowFocusLost(static_cast<cWindowFocusLostEvent*>(event) ); \
            break; \
        case CER_WindowCloseEvent: \
            this->onWindowClose(static_cast<cWindowCloseEvent*>(event) ); \
            break; \
        case CER_WindowTakeFocusEvent: \
            this->onWindowTakeFocus(static_cast<cWindowTakeFocusEvent*>(event) ); \
            break; \
        case CER_WindowHitTestEvent: \
            this->onWindowHitTest(static_cast<cWindowHitTestEvent*>(event) ); \
            break; \
        case CER_KeydownEvent: \
            this->onKeydown(static_cast<cKeydownEvent*>(event) ); \
            break; \
        case CER_KeyupEvent: \
            this->onKeyup(static_cast<cKeyupEvent*>(event) ); \
            break; \
        case CER_TextEditingEvent: \
            this->onTextEditing(static_cast<cTextEditingEvent*>(event) ); \
            break; \
        case CER_TextInputEvent: \
            this->onTextInput(static_cast<cTextInputEvent*>(event) ); \
            break; \
        case CER_KeymapchangedEvent: \
            this->onKeymapchanged(static_cast<cKeymapchangedEvent*>(event) ); \
            break; \
        case CER_MouseButtondownEvent: \
            this->onMouseButtondown(static_cast<cMouseButtondownEvent*>(event) ); \
            break; \
        case CER_MouseMotionEvent: \
            this->onMouseMotion(static_cast<cMouseMotionEvent*>(event) ); \
            break; \
        case CER_MouseButtonupEvent: \
            this->onMouseButtonup(static_cast<cMouseButtonupEvent*>(event) ); \
            break; \
        case CER_MouseWheelEvent: \
            this->onMouseWheel(static_cast<cMouseWheelEvent*>(event) ); \
            break; \
        case CER_JoyAxisMotionEvent: \
            this->onJoyAxisMotion(static_cast<cJoyAxisMotionEvent*>(event) ); \
            break; \
        case CER_JoyBallMotionEvent: \
            this->onJoyBallMotion(static_cast<cJoyBallMotionEvent*>(event) ); \
            break; \
        case CER_JoyHatMotionEvent: \
            this->onJoyHatMotion(static_cast<cJoyHatMotionEvent*>(event) ); \
            break; \
        case CER_JoyButtondownEvent: \
            this->onJoyButtondown(static_cast<cJoyButtondownEvent*>(event) ); \
            break; \
        case CER_JoyButtonupEvent: \
            this->onJoyButtonup(static_cast<cJoyButtonupEvent*>(event) ); \
            break; \
        case CER_JoyDeviceAddedEvent: \
            this->onJoyDeviceAdded(static_cast<cJoyDeviceAddedEvent*>(event) ); \
            break; \
        case CER_JoyDeviceRemovedEvent: \
            this->onJoyDeviceRemoved(static_cast<cJoyDeviceRemovedEvent*>(event) ); \
            break; \
        case CER_ControllerAxisMotionEvent: \
            this->onControllerAxisMotion(static_cast<cControllerAxisMotionEvent*>(event) ); \
            break; \
        case CER_ControllerButtondownEvent: \
            this->onControllerButtondown(static_cast<cControllerButtondownEvent*>(event) ); \
            break; \
        case CER_ControllerButtonupEvent: \
            this->onControllerButtonup(static_cast<cControllerButtonupEvent*>(event) ); \
            break; \
        case CER_ControllerDeviceAddedEvent: \
            this->onControllerDeviceAdded(static_cast<cControllerDeviceAddedEvent*>(event) ); \
            break; \
        case CER_ControllerDeviceRemovedEvent: \
            this->onControllerDeviceRemoved(static_cast<cControllerDeviceRemovedEvent*>(event) ); \
            break; \
        case CER_ControllerDeviceRemappedEvent: \
            this->onControllerDeviceRemapped(static_cast<cControllerDeviceRemappedEvent*>(event) ); \
            break; \
        case CER_FingerdownEvent: \
            this->onFingerdown(static_cast<cFingerdownEvent*>(event) ); \
            break; \
        case CER_FingerupEvent: \
            this->onFingerup(static_cast<cFingerupEvent*>(event) ); \
            break; \
        case CER_FingerMotionEvent: \
            this->onFingerMotion(static_cast<cFingerMotionEvent*>(event) ); \
            break; \
        case CER_DollarGestureEvent: \
            this->onDollarGesture(static_cast<cDollarGestureEvent*>(event) ); \
            break; \
        case CER_DollarRecordEvent: \
            this->onDollarRecord(static_cast<cDollarRecordEvent*>(event) ); \
            break; \
        case CER_MultiGestureEvent: \
            this->onMultiGesture(static_cast<cMultiGestureEvent*>(event) ); \
            break; \
        case CER_ClipboardUpdateEvent: \
            this->onClipboardUpdate(static_cast<cClipboardUpdateEvent*>(event) ); \
            break; \
        case CER_DropFileEvent: \
            this->onDropFile(static_cast<cDropFileEvent*>(event) ); \
            break; \
        case CER_DropTextEvent: \
            this->onDropText(static_cast<cDropTextEvent*>(event) ); \
            break; \
        case CER_DropBeginEvent: \
            this->onDropBegin(static_cast<cDropBeginEvent*>(event) ); \
            break; \
        case CER_DropCompleteEvent: \
            this->onDropComplete(static_cast<cDropCompleteEvent*>(event) ); \
            break; \
        case CER_AudioDeviceAddedEvent: \
            this->onAudioDeviceAdded(static_cast<cAudioDeviceAddedEvent*>(event) ); \
            break; \
        case CER_AudioDeviceRemovedEvent: \
            this->onAudioDeviceRemoved(static_cast<cAudioDeviceRemovedEvent*>(event) ); \
            break; \
        case CER_RenderTargetsResetEvent: \
            this->onRenderTargetsReset(static_cast<cRenderTargetsResetEvent*>(event) ); \
            break; \
        case CER_RenderDeviceResetEvent: \
            this->onRenderDeviceReset(static_cast<cRenderDeviceResetEvent*>(event) ); \
            break; \


