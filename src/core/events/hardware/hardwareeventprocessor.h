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
            this->onQuit(static_cast<QuitEvent*>(event) ); \
            break; \
        case CER_WindowShownEvent: \
            this->onWindowShown(static_cast<WindowShownEvent*>(event) ); \
            break; \
        case CER_WindowHiddenEvent: \
            this->onWindowHidden(static_cast<WindowHiddenEvent*>(event) ); \
            break; \
        case CER_WindowExposedEvent: \
            this->onWindowExposed(static_cast<WindowExposedEvent*>(event) ); \
            break; \
        case CER_WindowMovedEvent: \
            this->onWindowMoved(static_cast<WindowMovedEvent*>(event) ); \
            break; \
        case CER_WindowResizedEvent: \
            this->onWindowResized(static_cast<WindowResizedEvent*>(event) ); \
            break; \
        case CER_WindowSizeChangedEvent: \
            this->onWindowSizeChanged(static_cast<WindowSizeChangedEvent*>(event) ); \
            break; \
        case CER_WindowMinimizedEvent: \
            this->onWindowMinimized(static_cast<WindowMinimizedEvent*>(event) ); \
            break; \
        case CER_WindowMaximizedEvent: \
            this->onWindowMaximized(static_cast<WindowMaximizedEvent*>(event) ); \
            break; \
        case CER_WindowRestoredEvent: \
            this->onWindowRestored(static_cast<WindowRestoredEvent*>(event) ); \
            break; \
        case CER_WindowEnterEvent: \
            this->onWindowEnter(static_cast<WindowEnterEvent*>(event) ); \
            break; \
        case CER_WindowLeaveEvent: \
            this->onWindowLeave(static_cast<WindowLeaveEvent*>(event) ); \
            break; \
        case CER_WindowFocusGainedEvent: \
            this->onWindowFocusGained(static_cast<WindowFocusGainedEvent*>(event) ); \
            break; \
        case CER_WindowFocusLostEvent: \
            this->onWindowFocusLost(static_cast<WindowFocusLostEvent*>(event) ); \
            break; \
        case CER_WindowCloseEvent: \
            this->onWindowClose(static_cast<WindowCloseEvent*>(event) ); \
            break; \
        case CER_WindowTakeFocusEvent: \
            this->onWindowTakeFocus(static_cast<WindowTakeFocusEvent*>(event) ); \
            break; \
        case CER_WindowHitTestEvent: \
            this->onWindowHitTest(static_cast<WindowHitTestEvent*>(event) ); \
            break; \
        case CER_KeydownEvent: \
            this->onKeydown(static_cast<KeydownEvent*>(event) ); \
            break; \
        case CER_KeyupEvent: \
            this->onKeyup(static_cast<KeyupEvent*>(event) ); \
            break; \
        case CER_TextEditingEvent: \
            this->onTextEditing(static_cast<TextEditingEvent*>(event) ); \
            break; \
        case CER_TextInputEvent: \
            this->onTextInput(static_cast<TextInputEvent*>(event) ); \
            break; \
        case CER_KeymapchangedEvent: \
            this->onKeymapchanged(static_cast<KeymapchangedEvent*>(event) ); \
            break; \
        case CER_MouseButtondownEvent: \
            this->onMouseButtondown(static_cast<MouseButtondownEvent*>(event) ); \
            break; \
        case CER_MouseMotionEvent: \
            this->onMouseMotion(static_cast<MouseMotionEvent*>(event) ); \
            break; \
        case CER_MouseButtonupEvent: \
            this->onMouseButtonup(static_cast<MouseButtonupEvent*>(event) ); \
            break; \
        case CER_MouseWheelEvent: \
            this->onMouseWheel(static_cast<MouseWheelEvent*>(event) ); \
            break; \
        case CER_JoyAxisMotionEvent: \
            this->onJoyAxisMotion(static_cast<JoyAxisMotionEvent*>(event) ); \
            break; \
        case CER_JoyBallMotionEvent: \
            this->onJoyBallMotion(static_cast<JoyBallMotionEvent*>(event) ); \
            break; \
        case CER_JoyHatMotionEvent: \
            this->onJoyHatMotion(static_cast<JoyHatMotionEvent*>(event) ); \
            break; \
        case CER_JoyButtondownEvent: \
            this->onJoyButtondown(static_cast<JoyButtondownEvent*>(event) ); \
            break; \
        case CER_JoyButtonupEvent: \
            this->onJoyButtonup(static_cast<JoyButtonupEvent*>(event) ); \
            break; \
        case CER_JoyDeviceAddedEvent: \
            this->onJoyDeviceAdded(static_cast<JoyDeviceAddedEvent*>(event) ); \
            break; \
        case CER_JoyDeviceRemovedEvent: \
            this->onJoyDeviceRemoved(static_cast<JoyDeviceRemovedEvent*>(event) ); \
            break; \
        case CER_ControllerAxisMotionEvent: \
            this->onControllerAxisMotion(static_cast<ControllerAxisMotionEvent*>(event) ); \
            break; \
        case CER_ControllerButtondownEvent: \
            this->onControllerButtondown(static_cast<ControllerButtondownEvent*>(event) ); \
            break; \
        case CER_ControllerButtonupEvent: \
            this->onControllerButtonup(static_cast<ControllerButtonupEvent*>(event) ); \
            break; \
        case CER_ControllerDeviceAddedEvent: \
            this->onControllerDeviceAdded(static_cast<ControllerDeviceAddedEvent*>(event) ); \
            break; \
        case CER_ControllerDeviceRemovedEvent: \
            this->onControllerDeviceRemoved(static_cast<ControllerDeviceRemovedEvent*>(event) ); \
            break; \
        case CER_ControllerDeviceRemappedEvent: \
            this->onControllerDeviceRemapped(static_cast<ControllerDeviceRemappedEvent*>(event) ); \
            break; \
        case CER_FingerdownEvent: \
            this->onFingerdown(static_cast<FingerdownEvent*>(event) ); \
            break; \
        case CER_FingerupEvent: \
            this->onFingerup(static_cast<FingerupEvent*>(event) ); \
            break; \
        case CER_FingerMotionEvent: \
            this->onFingerMotion(static_cast<FingerMotionEvent*>(event) ); \
            break; \
        case CER_DollarGestureEvent: \
            this->onDollarGesture(static_cast<DollarGestureEvent*>(event) ); \
            break; \
        case CER_DollarRecordEvent: \
            this->onDollarRecord(static_cast<DollarRecordEvent*>(event) ); \
            break; \
        case CER_MultiGestureEvent: \
            this->onMultiGesture(static_cast<MultiGestureEvent*>(event) ); \
            break; \
        case CER_ClipboardUpdateEvent: \
            this->onClipboardUpdate(static_cast<ClipboardUpdateEvent*>(event) ); \
            break; \
        case CER_DropFileEvent: \
            this->onDropFile(static_cast<DropFileEvent*>(event) ); \
            break; \
        case CER_DropTextEvent: \
            this->onDropText(static_cast<DropTextEvent*>(event) ); \
            break; \
        case CER_DropBeginEvent: \
            this->onDropBegin(static_cast<DropBeginEvent*>(event) ); \
            break; \
        case CER_DropCompleteEvent: \
            this->onDropComplete(static_cast<DropCompleteEvent*>(event) ); \
            break; \
        case CER_AudioDeviceAddedEvent: \
            this->onAudioDeviceAdded(static_cast<AudioDeviceAddedEvent*>(event) ); \
            break; \
        case CER_AudioDeviceRemovedEvent: \
            this->onAudioDeviceRemoved(static_cast<AudioDeviceRemovedEvent*>(event) ); \
            break; \
        case CER_RenderTargetsResetEvent: \
            this->onRenderTargetsReset(static_cast<RenderTargetsResetEvent*>(event) ); \
            break; \
        case CER_RenderDeviceResetEvent: \
            this->onRenderDeviceReset(static_cast<RenderDeviceResetEvent*>(event) ); \
            break; \


