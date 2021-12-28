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

#ifndef SDL_MAIN_HANDLED
#define SDL_MAIN_HANDLED
#endif

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"

#include "sdl_backend.h"

#include "event.h"
#include "types.h"

using namespace cerritos;

const char* cerritos::GetError() {
    return SDL_GetError();
}

unsigned int cerritos::GetTicks() {
    return SDL_GetTicks();
}

void cerritos::Delay(unsigned int ms) {
    SDL_Delay(ms);
}

int cerritos::backendInit() {
    int successCode = 0;
    SDL_SetMainReady();
    
    successCode = SDL_Init(SDL_INIT_EVERYTHING);
    if(successCode < 0) {
        cSTDOUT << "SDL_Init: " << SDL_GetError() << EOL;
        return successCode;
    }
    successCode = TTF_Init();
    if(successCode<0) {
        cSTDOUT << "TTF_Init: " << TTF_GetError() << EOL;
        return successCode;
    }
    
    // load support for the JPG and PNG image formats
    int flags=IMG_INIT_JPG|IMG_INIT_PNG;
    int initted=IMG_Init(flags);
    if((initted&flags) != flags) {
        cSTDOUT << "IMG_Init: Failed to init required jpg and png support" << EOL;
        cSTDOUT << "IMG_Init: " << IMG_GetError() << EOL;
        // handle error
    }
    
    return successCode;
}

void cerritos::backendClose() {
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}


