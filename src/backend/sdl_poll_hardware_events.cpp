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
 
#include <iostream>

#include "SDL.h"

#include "sdl_backend.h"

#include "event.h"

// This file is periodically generated.  Do not edit it directly.
 
using namespace cerritos;
 
void cerritos::PollHardwareEvents(EventManager* eventManager) {
    // Get SDL events
    SDL_Event event;
    Event* newEvent = NULL;
    
    while (SDL_PollEvent(&event)) {
        newEvent = NULL;
        switch (event.type) {
            case SDL_QUIT:
                newEvent = new QuitEvent(
                    event.quit.timestamp
                );
                break;
            case SDL_WINDOWEVENT_SHOWN:
                newEvent = new WindowShownEvent(
                    event.window.timestamp, event.window.windowID
                );
                break;
            case SDL_WINDOWEVENT_HIDDEN:
                newEvent = new WindowHiddenEvent(
                    event.window.timestamp, event.window.windowID
                );
                break;
            case SDL_WINDOWEVENT_EXPOSED:
                newEvent = new WindowExposedEvent(
                    event.window.timestamp, event.window.windowID
                );
                break;
            case SDL_WINDOWEVENT_MOVED:
                newEvent = new WindowMovedEvent(
                    event.window.timestamp, event.window.windowID, event.window.data1, event.window.data2
                );
                break;
            case SDL_WINDOWEVENT_RESIZED:
                newEvent = new WindowResizedEvent(
                    event.window.timestamp, event.window.windowID, event.window.data1, event.window.data2
                );
                break;
            case SDL_WINDOWEVENT_SIZE_CHANGED:
                newEvent = new WindowSizeChangedEvent(
                    event.window.timestamp, event.window.windowID, event.window.data1, event.window.data2
                );
                break;
            case SDL_WINDOWEVENT_MINIMIZED:
                newEvent = new WindowMinimizedEvent(
                    event.window.timestamp, event.window.windowID
                );
                break;
            case SDL_WINDOWEVENT_MAXIMIZED:
                newEvent = new WindowMaximizedEvent(
                    event.window.timestamp, event.window.windowID
                );
                break;
            case SDL_WINDOWEVENT_RESTORED:
                newEvent = new WindowRestoredEvent(
                    event.window.timestamp, event.window.windowID
                );
                break;
            case SDL_WINDOWEVENT_ENTER:
                newEvent = new WindowEnterEvent(
                    event.window.timestamp, event.window.windowID
                );
                break;
            case SDL_WINDOWEVENT_LEAVE:
                newEvent = new WindowLeaveEvent(
                    event.window.timestamp, event.window.windowID
                );
                break;
            case SDL_WINDOWEVENT_FOCUS_GAINED:
                newEvent = new WindowFocusGainedEvent(
                    event.window.timestamp, event.window.windowID
                );
                break;
            case SDL_WINDOWEVENT_FOCUS_LOST:
                newEvent = new WindowFocusLostEvent(
                    event.window.timestamp, event.window.windowID
                );
                break;
            case SDL_WINDOWEVENT_CLOSE:
                newEvent = new WindowCloseEvent(
                    event.window.timestamp, event.window.windowID
                );
                break;
            case SDL_WINDOWEVENT_TAKE_FOCUS:
                newEvent = new WindowTakeFocusEvent(
                    event.window.timestamp, event.window.windowID
                );
                break;
            case SDL_WINDOWEVENT_HIT_TEST:
                newEvent = new WindowHitTestEvent(
                    event.window.timestamp, event.window.windowID
                );
                break;
            case SDL_KEYDOWN:
                newEvent = new KeydownEvent(
                    event.key.timestamp, event.key.windowID, event.key.keysym.sym, event.key.keysym.scancode
                );
                break;
            case SDL_KEYUP:
                newEvent = new KeyupEvent(
                    event.key.timestamp, event.key.windowID, event.key.keysym.sym, event.key.keysym.scancode
                );
                break;
            case SDL_TEXTEDITING:
                newEvent = new TextEditingEvent(
                    event.edit.timestamp, event.edit.windowID
                );
                break;
            case SDL_TEXTINPUT:
                newEvent = new TextInputEvent(
                    event.text.timestamp, event.text.windowID
                );
                break;
            case SDL_KEYMAPCHANGED:
                newEvent = new KeymapchangedEvent;
                break;
            case SDL_MOUSEBUTTONDOWN:
                newEvent = new MouseButtondownEvent(
                    event.button.timestamp
                );
                break;
            case SDL_MOUSEMOTION:
                newEvent = new MouseMotionEvent(
                    event.motion.timestamp, event.motion.windowID, event.motion.x, event.motion.y, event.motion.xrel, event.motion.yrel
                );
                break;
            case SDL_MOUSEBUTTONUP:
                newEvent = new MouseButtonupEvent(
                    event.button.timestamp
                );
                break;
            case SDL_MOUSEWHEEL:
                newEvent = new MouseWheelEvent(
                    event.wheel.timestamp
                );
                break;
            case SDL_JOYAXISMOTION:
                newEvent = new JoyAxisMotionEvent(
                    event.jaxis.timestamp
                );
                break;
            case SDL_JOYBALLMOTION:
                newEvent = new JoyBallMotionEvent(
                    event.jball.timestamp
                );
                break;
            case SDL_JOYHATMOTION:
                newEvent = new JoyHatMotionEvent(
                    event.jhat.timestamp
                );
                break;
            case SDL_JOYBUTTONDOWN:
                newEvent = new JoyButtondownEvent(
                    event.jbutton.timestamp
                );
                break;
            case SDL_JOYBUTTONUP:
                newEvent = new JoyButtonupEvent(
                    event.jbutton.timestamp
                );
                break;
            case SDL_JOYDEVICEADDED:
                newEvent = new JoyDeviceAddedEvent(
                    event.jdevice.timestamp
                );
                break;
            case SDL_JOYDEVICEREMOVED:
                newEvent = new JoyDeviceRemovedEvent(
                    event.jdevice.timestamp
                );
                break;
            case SDL_CONTROLLERAXISMOTION:
                newEvent = new ControllerAxisMotionEvent(
                    event.caxis.timestamp
                );
                break;
            case SDL_CONTROLLERBUTTONDOWN:
                newEvent = new ControllerButtondownEvent(
                    event.cbutton.timestamp
                );
                break;
            case SDL_CONTROLLERBUTTONUP:
                newEvent = new ControllerButtonupEvent(
                    event.cbutton.timestamp
                );
                break;
            case SDL_CONTROLLERDEVICEADDED:
                newEvent = new ControllerDeviceAddedEvent(
                    event.cdevice.timestamp
                );
                break;
            case SDL_CONTROLLERDEVICEREMOVED:
                newEvent = new ControllerDeviceRemovedEvent(
                    event.cdevice.timestamp
                );
                break;
            case SDL_CONTROLLERDEVICEREMAPPED:
                newEvent = new ControllerDeviceRemappedEvent(
                    event.cdevice.timestamp
                );
                break;
            case SDL_FINGERDOWN:
                newEvent = new FingerdownEvent(
                    event.tfinger.timestamp
                );
                break;
            case SDL_FINGERUP:
                newEvent = new FingerupEvent(
                    event.tfinger.timestamp
                );
                break;
            case SDL_FINGERMOTION:
                newEvent = new FingerMotionEvent(
                    event.tfinger.timestamp
                );
                break;
            case SDL_DOLLARGESTURE:
                newEvent = new DollarGestureEvent(
                    event.dgesture.timestamp
                );
                break;
            case SDL_DOLLARRECORD:
                newEvent = new DollarRecordEvent(
                    event.dgesture.timestamp
                );
                break;
            case SDL_MULTIGESTURE:
                newEvent = new MultiGestureEvent(
                    event.mgesture.timestamp
                );
                break;
            case SDL_CLIPBOARDUPDATE:
                newEvent = new ClipboardUpdateEvent;
                break;
            case SDL_DROPFILE:
                newEvent = new DropFileEvent(
                    event.drop.timestamp
                );
                break;
            case SDL_DROPTEXT:
                newEvent = new DropTextEvent(
                    event.drop.timestamp
                );
                break;
            case SDL_DROPBEGIN:
                newEvent = new DropBeginEvent(
                    event.drop.timestamp
                );
                break;
            case SDL_DROPCOMPLETE:
                newEvent = new DropCompleteEvent(
                    event.drop.timestamp
                );
                break;
            case SDL_AUDIODEVICEADDED:
                newEvent = new AudioDeviceAddedEvent(
                    event.adevice.timestamp
                );
                break;
            case SDL_AUDIODEVICEREMOVED:
                newEvent = new AudioDeviceRemovedEvent(
                    event.adevice.timestamp
                );
                break;
            case SDL_RENDER_TARGETS_RESET:
                newEvent = new RenderTargetsResetEvent;
                break;
            case SDL_RENDER_DEVICE_RESET:
                newEvent = new RenderDeviceResetEvent;
                break;
            default:
                // std::cout << "Unhandled Event!" << std::endl;
                break;
        }
        if(newEvent != NULL)
            eventManager->addEvent( (Event*) newEvent);
    }
}

