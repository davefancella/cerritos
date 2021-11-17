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
#include "SDL_ttf.h"

#include "sdl_backend.h"

#include "event.h"

const char* GetError() {
    return SDL_GetError();
}

unsigned int GetTicks() {
    return SDL_GetTicks();
}

void Delay(unsigned int ms) {
    SDL_Delay(ms);
}

int backendInit() {
    int successCode;
    
    successCode = SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
    if(successCode == -1) {
        std::cout << "SDL_Init: " << SDL_GetError();
        return -1;
    }

    return successCode;
}

void backendClose() {
    SDL_Quit();
}

cWindow* CreateWindow(unicodestring title,
                    int x, int y, int w,
                    int h, Uint32 flags) {
    return static_cast<cWindow*>(SDL_CreateWindow(title.data(),
        x, y, w, h, flags) );
}

cSurfaceS* GetWindowSurface(cWindow* window) {
    return static_cast<cSurfaceS*>(SDL_GetWindowSurface(
        window) );
}

void DestroyWindow(cWindow* window) {
    SDL_DestroyWindow(window);
}

/*
int BlitSurface(cSurfaceS* src, const cRect* srcrect,
                    cSurfaceS* dst, cRect* dstrect) {
    return SDL_BlitSurface(src, srcrect, dst, dstrect);
}*/

cSurfaceS* ConvertSurface(cSurfaceS * src, const cPixelFormat * fmt, unsigned int flags) {
    return static_cast<cSurfaceS*>(SDL_ConvertSurface(
        src, fmt, flags) );
}

/*
int FillRect(cSurfaceS* dst, const cRect* rect, unsigned int color) {
    return SDL_FillRect(dst, rect, color);
}*/

unsigned int MapRGB(cPixelFormat* format,
                  uint8_t r, uint8_t g, uint8_t b) {
    return SDL_MapRGB(format, r, g, b);
}

/*
SDL_CreateRGBSurface
SDL_CreateRGBSurfaceFrom
SDL_FillRect
SDL_FillRects
SDL_FreeSurface
SDL_GetClipRect
SDL_GetColorKey
SDL_GetSurfaceAlphaMod
SDL_GetSurfaceBlendMode
SDL_GetSurfaceColorMod
SDL_LoadBMP_RW
SDL_LockSurface
SDL_LowerBlit
SDL_MUSTLOCK
SDL_SaveBMP_RW
SDL_SetClipRect
SDL_SetColorKey
SDL_SetSurfaceAlphaMod
SDL_SetSurfaceBlendMode
SDL_SetSurfaceColorMod
SDL_SetSurfacePalette
SDL_SetSurfaceRLE
SDL_SoftStretch
SDL_UnlockSurface
*/

