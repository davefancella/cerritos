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
            if(this->mainwindow != NULL) \
                this->mainwindow->onQuit(static_cast<cQuitEvent*>(evt) ); \
            break; \
        case CER_WindowShownEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onWindowShown(static_cast<cWindowShownEvent*>(evt) ); \
            break; \
        case CER_WindowHiddenEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onWindowHidden(static_cast<cWindowHiddenEvent*>(evt) ); \
            break; \
        case CER_WindowExposedEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onWindowExposed(static_cast<cWindowExposedEvent*>(evt) ); \
            break; \
        case CER_WindowMovedEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onWindowMoved(static_cast<cWindowMovedEvent*>(evt) ); \
            break; \
        case CER_WindowResizedEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onWindowResized(static_cast<cWindowResizedEvent*>(evt) ); \
            break; \
        case CER_WindowSizeChangedEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onWindowSizeChanged(static_cast<cWindowSizeChangedEvent*>(evt) ); \
            break; \
        case CER_WindowMinimizedEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onWindowMinimized(static_cast<cWindowMinimizedEvent*>(evt) ); \
            break; \
        case CER_WindowMaximizedEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onWindowMaximized(static_cast<cWindowMaximizedEvent*>(evt) ); \
            break; \
        case CER_WindowRestoredEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onWindowRestored(static_cast<cWindowRestoredEvent*>(evt) ); \
            break; \
        case CER_WindowEnterEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onWindowEnter(static_cast<cWindowEnterEvent*>(evt) ); \
            break; \
        case CER_WindowLeaveEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onWindowLeave(static_cast<cWindowLeaveEvent*>(evt) ); \
            break; \
        case CER_WindowFocusGainedEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onWindowFocusGained(static_cast<cWindowFocusGainedEvent*>(evt) ); \
            break; \
        case CER_WindowFocusLostEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onWindowFocusLost(static_cast<cWindowFocusLostEvent*>(evt) ); \
            break; \
        case CER_WindowCloseEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onWindowClose(static_cast<cWindowCloseEvent*>(evt) ); \
            break; \
        case CER_WindowTakeFocusEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onWindowTakeFocus(static_cast<cWindowTakeFocusEvent*>(evt) ); \
            break; \
        case CER_WindowHitTestEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onWindowHitTest(static_cast<cWindowHitTestEvent*>(evt) ); \
            break; \
        case CER_KeydownEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onKeydown(static_cast<cKeydownEvent*>(evt) ); \
            break; \
        case CER_KeyupEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onKeyup(static_cast<cKeyupEvent*>(evt) ); \
            break; \
        case CER_TextEditingEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onTextEditing(static_cast<cTextEditingEvent*>(evt) ); \
            break; \
        case CER_TextInputEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onTextInput(static_cast<cTextInputEvent*>(evt) ); \
            break; \
        case CER_KeymapchangedEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onKeymapchanged(static_cast<cKeymapchangedEvent*>(evt) ); \
            break; \
        case CER_MouseButtondownEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onMouseButtondown(static_cast<cMouseButtondownEvent*>(evt) ); \
            break; \
        case CER_MouseMotionEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onMouseMotion(static_cast<cMouseMotionEvent*>(evt) ); \
            break; \
        case CER_MouseButtonupEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onMouseButtonup(static_cast<cMouseButtonupEvent*>(evt) ); \
            break; \
        case CER_MouseWheelEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onMouseWheel(static_cast<cMouseWheelEvent*>(evt) ); \
            break; \
        case CER_JoyAxisMotionEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onJoyAxisMotion(static_cast<cJoyAxisMotionEvent*>(evt) ); \
            break; \
        case CER_JoyBallMotionEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onJoyBallMotion(static_cast<cJoyBallMotionEvent*>(evt) ); \
            break; \
        case CER_JoyHatMotionEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onJoyHatMotion(static_cast<cJoyHatMotionEvent*>(evt) ); \
            break; \
        case CER_JoyButtondownEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onJoyButtondown(static_cast<cJoyButtondownEvent*>(evt) ); \
            break; \
        case CER_JoyButtonupEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onJoyButtonup(static_cast<cJoyButtonupEvent*>(evt) ); \
            break; \
        case CER_JoyDeviceAddedEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onJoyDeviceAdded(static_cast<cJoyDeviceAddedEvent*>(evt) ); \
            break; \
        case CER_JoyDeviceRemovedEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onJoyDeviceRemoved(static_cast<cJoyDeviceRemovedEvent*>(evt) ); \
            break; \
        case CER_ControllerAxisMotionEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onControllerAxisMotion(static_cast<cControllerAxisMotionEvent*>(evt) ); \
            break; \
        case CER_ControllerButtondownEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onControllerButtondown(static_cast<cControllerButtondownEvent*>(evt) ); \
            break; \
        case CER_ControllerButtonupEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onControllerButtonup(static_cast<cControllerButtonupEvent*>(evt) ); \
            break; \
        case CER_ControllerDeviceAddedEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onControllerDeviceAdded(static_cast<cControllerDeviceAddedEvent*>(evt) ); \
            break; \
        case CER_ControllerDeviceRemovedEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onControllerDeviceRemoved(static_cast<cControllerDeviceRemovedEvent*>(evt) ); \
            break; \
        case CER_ControllerDeviceRemappedEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onControllerDeviceRemapped(static_cast<cControllerDeviceRemappedEvent*>(evt) ); \
            break; \
        case CER_FingerdownEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onFingerdown(static_cast<cFingerdownEvent*>(evt) ); \
            break; \
        case CER_FingerupEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onFingerup(static_cast<cFingerupEvent*>(evt) ); \
            break; \
        case CER_FingerMotionEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onFingerMotion(static_cast<cFingerMotionEvent*>(evt) ); \
            break; \
        case CER_DollarGestureEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onDollarGesture(static_cast<cDollarGestureEvent*>(evt) ); \
            break; \
        case CER_DollarRecordEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onDollarRecord(static_cast<cDollarRecordEvent*>(evt) ); \
            break; \
        case CER_MultiGestureEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onMultiGesture(static_cast<cMultiGestureEvent*>(evt) ); \
            break; \
        case CER_ClipboardUpdateEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onClipboardUpdate(static_cast<cClipboardUpdateEvent*>(evt) ); \
            break; \
        case CER_DropFileEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onDropFile(static_cast<cDropFileEvent*>(evt) ); \
            break; \
        case CER_DropTextEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onDropText(static_cast<cDropTextEvent*>(evt) ); \
            break; \
        case CER_DropBeginEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onDropBegin(static_cast<cDropBeginEvent*>(evt) ); \
            break; \
        case CER_DropCompleteEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onDropComplete(static_cast<cDropCompleteEvent*>(evt) ); \
            break; \
        case CER_AudioDeviceAddedEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onAudioDeviceAdded(static_cast<cAudioDeviceAddedEvent*>(evt) ); \
            break; \
        case CER_AudioDeviceRemovedEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onAudioDeviceRemoved(static_cast<cAudioDeviceRemovedEvent*>(evt) ); \
            break; \
        case CER_RenderTargetsResetEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onRenderTargetsReset(static_cast<cRenderTargetsResetEvent*>(evt) ); \
            break; \
        case CER_RenderDeviceResetEvent: \
            if(this->mainwindow != NULL) \
                this->mainwindow->onRenderDeviceReset(static_cast<cRenderDeviceResetEvent*>(evt) ); \
            break; \


