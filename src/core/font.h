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

namespace cerritos {

class cWindow;
class cRect;

/** A simple font class.
 * 
 *  It loads fonts from a file and can render to a rect.  It does not
 *  do any multiline handling or range checking or anything.  Simply
 *  tell it to print text, give a cSurface to print it on, and it'll do
 *  that.
 */
class cFont {
public:
    /// Default constructor.
    cFont();
    
    /// Renders text to the screen
    bool RenderText(cWindow* window, const char* text, cRect* dest, uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha=0);
    /// Renders text to the screen
    bool RenderText(cWindow* window, cString text, cRect* dest, uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha=0);
    
    /// Loads a font from a file
    int loadFontFile(const char* filename, int size);
    int loadFontFile(cString filename, int size);

    /// Static method to create a new cFont object from a file.
    static cFont* loadFromFile(cString filename, int size);
    
    /// Set the style to be rendered, i.e. bold/italic/etc.
    void SetFontStyle(int style);

    /// Set the size of the font outline.
    void SetFontOutline(int outline);
    
    /// Enables font kerning.
    void EnableFontKerning();
    /// Disables font kerning.
    void DisableFontKerning();
    /// The actual method that enables/disables kerning.
    void SetFontKerning(int kerning);
    
    /// Set font hinting method.
    void SetFontHinting(int hinting);
    
private:
#ifdef USING_SDL
    TTF_Font* mFont;
#endif
};

}

#endif // FONT__H


