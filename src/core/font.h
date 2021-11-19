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

#ifndef FONT__H
#define FONT__H

#include "SDL_ttf.h"

#include "string.h"

class cWindow;
class cRect;

class cFont {
public:
    cFont();
    
    bool RenderText(cWindow* window, const char* text, cRect* dest, uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha=0);
    bool RenderText(cWindow* window, unicodestring text, cRect* dest, uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha=0);
    
    int loadFontFile(const char* filename, int size);
    int loadFontFile(unicodestring filename, int size);
    
    static cFont* loadFromFile(unicodestring filename, int size);
    
    void SetFontStyle(int style);
    
    void SetFontOutline(int outline);
    
    void EnableFontKerning();
    void DisableFontKerning();
    void SetFontKerning(int kerning);
    
    void SetFontHinting(int hinting);
    
private:
#ifdef USING_SDL
    TTF_Font* mFont;
#endif
};

#endif // FONT__H


