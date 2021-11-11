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

// This is the file where all the translations from backend to cerritos
// should occur.

#ifndef BACKEND__H
#define BACKEND__H

class cEventManager;

// These are the functions a backend must implement

// Clock
unsigned int GetTicks();

// Just delay code execution, equivalent to sleep()
void Delay(unsigned int ms);

// Initialize the backend
int backendInit(unsigned int flags);
void backendClose();

// Poll backend for hardware events and put them in the event manager
void PollHardwareEvents(cEventManager* eventManager);

// These are the enums that a backend must provide

/*
typedef enum {
    CER_Fullscreen, CER_FullDesktop, CER_OpenGl, CER_Vulkan, CER_Shown, CER_Hidden,
    CER_Borderless, CER_Resizable, CER_Minimized, CER_Maximized, CER_GrabInput, CER_FocusInput,
    CER_FocusMouse, CER_Foreign, CER_HighDpi, CER_CaptureMouse, CER_AlwaysOnTop,
    CER_NoTaskbar, CER_Utility, CER_Tooltip, CER_PopupMenu,
} CER_WindowFlags;
*/

#include "sdl_backend.h"

#endif // BACKEND__H


