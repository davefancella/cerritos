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

#undef NDEBUG
#include <assert.h>

#include "SDL.h"
#include "SDL_ttf.h"

#include "window.h"
#include "font.h"
#include "string.h"
#include "rect.h"

cFont::cFont() {
    this->mFont = NULL;
}

bool cFont::RenderText(cWindow* window, const char* text, cRect* dest, uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) {
    return this->RenderText(window, unicodestring(text), dest, red, blue, green, alpha);
}

bool cFont::RenderText(cWindow* window, unicodestring text, cRect* dest, uint8_t red, uint8_t blue, uint8_t green, uint8_t alpha) {
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
            std::cout << "Unable to render text surface! SDL_ttf Error: " << TTF_GetError() << std::endl;
            
            return false;
        } else {
            //Create texture from surface pixels
            texture = SDL_CreateTextureFromSurface(window->getSDLRenderer(), textSurface );
            if( texture == NULL )
            {
                std::cout << "Unable to create texture from rendered text! SDL Error: " << SDL_GetError() << std::endl;
                
                SDL_FreeSurface(textSurface);
                return false;
            } else {
                SDL_Rect aRect = { dest->x, dest->y, calcW, calcH };
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

    return true;
#else 
    return true;
#endif
}

int cFont::loadFontFile(const char* filename, int size) {
    return this->loadFontFile(unicodestring(filename), size);
}

int cFont::loadFontFile(unicodestring filename, int size) {
#ifdef USING_SDL
    this->mFont = TTF_OpenFont(filename.data(), size);
    if( this->mFont == NULL )
    {
        std::cout << "Failed to load font! SDL_ttf Error: " << TTF_GetError() << std::endl;
        TTF_CloseFont(this->mFont);
        this->mFont = NULL;
        assert(this->mFont == NULL);
        return -1;
    }
    TTF_SetFontStyle(this->mFont, TTF_STYLE_NORMAL);
    TTF_SetFontOutline(this->mFont, 0);
    TTF_SetFontKerning(this->mFont, 1);
    TTF_SetFontHinting(this->mFont, TTF_HINTING_NORMAL);
    std::cout << "Loaded font: "
        << TTF_FontFaceFamilyName(this->mFont) << " "
        << TTF_FontFaceStyleName(this->mFont) << " "
        << TTF_FontHeight(this->mFont)
        << std::endl;
    return 0;
#endif
}

cFont* cFont::loadFromFile(unicodestring filename, int size) {
    cFont* theFont = NULL;
    
    theFont = new cFont();
    if(theFont->loadFontFile(filename, size) == 0) {
        std::cout << "Loaded font '" << filename << "'" << std::endl;
    }
    
    return theFont;
}


