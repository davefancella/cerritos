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

unsigned int GetTicks() {
    return SDL_GetTicks();
}

void Delay(unsigned int ms) {
    SDL_Delay(ms);
}

int backendInit(unsigned int flags) {
    int successCode;
    
    successCode = SDL_Init(flags);
    if(successCode == -1) {
        std::cout << "SDL_Init: " << SDL_GetError();
        return -1;
    }

    return successCode;
}

void backendClose() {
    SDL_Quit();
}

void PollHardwareEvents(cEventManager* eventManager) {
    // Get SDL events
    SDL_Event event;
    cEvent* newEvent = NULL;
    
    while (SDL_PollEvent(&event)) {
        newEvent = NULL;
        switch (event.type) {
            case SDL_MOUSEMOTION:
                newEvent = new cMouseOverEvent(event.motion.x, event.motion.y);
                break;
            case SDL_QUIT:
                newEvent = new cQuitEvent;
                break;
            // Keyboard events
            case SDL_KEYDOWN:
                newEvent = new cKeydownEvent;
                break;
            case SDL_KEYUP:
                newEvent = new cKeyupEvent;
                break;
            case SDL_TEXTEDITING:
            case SDL_TEXTINPUT:
            case SDL_KEYMAPCHANGED:
                std::cout << "Received a keyboard event that's not currently handled.\n";
                break;
            // Mobile events, currently not handled
            case SDL_APP_TERMINATING:
            case SDL_APP_LOWMEMORY:
            case SDL_APP_WILLENTERBACKGROUND:
            case SDL_APP_DIDENTERBACKGROUND:
            case SDL_APP_WILLENTERFOREGROUND:
            case SDL_APP_DIDENTERFOREGROUND:
                std::cout << "Received mobile event, not currently handled.\n";
                break;
            default:
                // printf("Unhandled Event!\n");
                break;
        }
        if(newEvent != NULL)
            eventManager->addEvent( (cEvent*) newEvent);
    }
}


