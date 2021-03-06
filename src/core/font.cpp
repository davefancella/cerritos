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

#ifdef USING_SDL
#include "SDL.h"
#include "SDL_ttf.h"
#endif

#include "window.h"
#include "font.h"
#include "types.h"
#include "rect.h"

using namespace cerritos;

Font::Font() {
    this->mFont = NULL;
}

/** This is an overloaded function that just calls the unicode version.
 * 
 * @param window: the Window object to which you'll be rendering this text
 * @param text: the text to render
 * @param dest: the Rect to which you'll render.  Only the position is used.
 * @param red: red part of color
 * @param green: green part of color
 * @param blue: blue part of color
 * @param alpha: the alpha part of color
 */
bool Font::RenderText(Window* window, const char* text, Rect* dest, uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) {
    return this->RenderText(window, String(text), dest, red, blue, green, alpha);
}

/**
 * @param window the Window object to which you'll be rendering this text
 * @param text   the text to render
 * @param dest   the Rect to which you'll render.  Only the position is used.
 * @param red    red part of color
 * @param green  green part of color
 * @param blue   blue part of color
 * @param alpha: the alpha part of color
 */
bool Font::RenderText(Window* window, String text, Rect* dest, uint8_t red, uint8_t blue, uint8_t green, uint8_t alpha) {
#ifdef USING_SDL
    int calcW, calcH;
    
    calcW = 0;
    calcH = 0;
    
    //Render text surface
    
    SDL_Surface* textSurface;
    SDL_Color textColor = {red, green, blue, alpha};

    SDL_Texture* texture = NULL;
    
    if(this->mFont != NULL) {
        TTF_SizeUTF8(this->mFont, text.c_str(), &calcW, &calcH);
        SDL_Surface* textSurface = TTF_RenderUTF8_Blended(this->mFont, text.c_str(), textColor);
        
        if( textSurface == NULL )
        {
            cSTDOUT << "Font: Unable to render text surface. SDL Error: " << TTF_GetError() << EOL;
            
            return false;
        } else {
            //Create texture from surface pixels
            texture = SDL_CreateTextureFromSurface(window->getSDLRenderer(), textSurface );
            if( texture == NULL )
            {
                cSTDOUT << "Font: Unable to create texture from rendered text. SDL Error: " << SDL_GetError() << EOL;
                
                SDL_FreeSurface(textSurface);
                return false;
            } else {
                SDL_Rect aRect = { dest->position.x(), dest->position.y(), calcW, calcH };
                SDL_RenderCopy(window->getSDLRenderer(), 
                            texture, 
                            NULL, 
                            &aRect);
            }

            //Get rid of old surface
            SDL_FreeSurface(textSurface);
            SDL_DestroyTexture(texture);
        }
    }
#endif
    return true;
}

int Font::loadFontFile(const char* filename, int size) {
    return this->loadFontFile(String(filename), size);
}

int Font::loadFontFile(String filename, int size) {
#ifdef USING_SDL
    this->mFont = TTF_OpenFont(filename.data(), size);
    if( this->mFont == NULL )
    {
        cSTDOUT << "Font: Failed to load font. SDL Error: " << TTF_GetError() << EOL;
        TTF_CloseFont(this->mFont);
        this->mFont = NULL;

        return -1;
    }
    return 0;
#endif
}

void Font::SetFontStyle(int style) {
#ifdef USING_SDL
    TTF_SetFontStyle(this->mFont, style);
#endif
}

void Font::SetFontOutline(int outline) {
#ifdef USING_SDL
    TTF_SetFontOutline(this->mFont, outline);
#endif
}

void Font::EnableFontKerning() {
    this->SetFontKerning(1);
}

void Font::DisableFontKerning() {
    this->SetFontKerning(0);
}

void Font::SetFontKerning(int kerning) {
#ifdef USING_SDL
    TTF_SetFontKerning(this->mFont, kerning);
#endif
}

void Font::SetFontHinting(int hinting) {
#ifdef USING_SDL
    TTF_SetFontHinting(this->mFont, hinting);
#endif
}

Font* Font::loadFromFile(String filename, int size) {
    Font* theFont = NULL;
    
    theFont = new Font();
    if(theFont->loadFontFile(filename, size) == 0) {
        theFont->SetFontOutline(0);
        theFont->EnableFontKerning();
#ifdef USING_SDL
        theFont->SetFontStyle(TTF_STYLE_NORMAL);
        theFont->SetFontHinting(TTF_HINTING_NORMAL);
#endif
    }
    
    return theFont;
}


