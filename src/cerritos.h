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

#include "SDL.h"

/* This file is the base header file you need to include to use davenetgame.
 */

#ifndef CERRITOS_H
#define CERRITOS_H

int cInit();
void cClose();

/** Window flags
 */
typedef enum {
    CER_Fullscreen = SDL_WINDOW_FULLSCREEN,
    CER_FullDesktop = SDL_WINDOW_FULLSCREEN_DESKTOP,
    CER_OpenGl = SDL_WINDOW_OPENGL,
    CER_Vulkan = SDL_WINDOW_VULKAN,
    CER_Shown = SDL_WINDOW_SHOWN,
    CER_Hidden = SDL_WINDOW_HIDDEN,
    CER_Borderless = SDL_WINDOW_BORDERLESS,
    CER_Resizable = SDL_WINDOW_RESIZABLE,
    CER_Minimized = SDL_WINDOW_MINIMIZED,
    CER_Maximized = SDL_WINDOW_MAXIMIZED,
    CER_GrabInput = SDL_WINDOW_INPUT_GRABBED,
    CER_FocusInput = SDL_WINDOW_INPUT_FOCUS,
    CER_FocusMouse = SDL_WINDOW_MOUSE_FOCUS,
    CER_Foreign = SDL_WINDOW_FOREIGN,
    CER_HighDpi = SDL_WINDOW_ALLOW_HIGHDPI,
    CER_CaptureMouse = SDL_WINDOW_MOUSE_CAPTURE,
    CER_AlwaysOnTop = SDL_WINDOW_ALWAYS_ON_TOP,
    CER_NoTaskbar = SDL_WINDOW_SKIP_TASKBAR,
    CER_Utility = SDL_WINDOW_UTILITY,
    CER_Tooltip = SDL_WINDOW_TOOLTIP,
    CER_PopupMenu = SDL_WINDOW_POPUP_MENU,
} CER_WindowFlags;

// Simple function to take a variable list of flags and return a single
// variable combining all flags together.
unsigned int flags(int num, ...);


#endif

