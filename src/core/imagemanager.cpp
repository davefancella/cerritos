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

#include "imagemanager.h"

#include "path.h"
#include "surface.h"
#include "types.h"
#include "window.h"

#ifdef USING_SDL
#include "SDL_image.h"
#endif

using namespace cerritos;

ImageManager::ImageManager() {
    
}

ImageManager& ImageManager::get() {
    static ImageManager* instance = new ImageManager();
    
    return *instance;
}

void ImageManager::setWindow(Window* newWindow) {
    m_Window = newWindow;
}

Surface* ImageManager::loadFromFile(const char* filename) {
    return loadFromFile(String(filename) );
}

Surface* ImageManager::loadPath(String searchpath, String filename) {
    return loadFromFile(_PATH.getFilepath(searchpath, filename) );
}

Surface* ImageManager::loadFromFile(String filename) {
    Surface* theSurface = NULL;
    
    if(m_ImageList.has_key(filename) )
        return m_ImageList[filename];
    
    // Do all the safety checks first
    if(m_Window == NULL) {
        cSTDOUT << "ImageManager: No m_Window initialized.  Cannot load image." << EOL;
        return NULL;
    }
    
#ifdef USING_SDL
    SDL_ClearError();
    
    SDL_Renderer* renderer = m_Window->getSDLRenderer();
    
    if(renderer == NULL) {
        cSTDOUT << "ImageManager: m_Window has NULL renderer." << EOL;
        return NULL;
    }
    
    // Safety checks are done
    
    // Do the actual loading now
    SDL_Surface* tempSurface = NULL;
    
    tempSurface = IMG_Load(filename.data() );

    if(tempSurface == NULL) {
        cSTDOUT << "ImageManager: " << IMG_GetError() << EOL;
        
        return NULL;
    } else {
        theSurface = new Surface(m_Window);

        theSurface->setSize(cSizeInt(tempSurface->w, tempSurface->h) );

        SDL_Texture* tempText = SDL_CreateTextureFromSurface(renderer, tempSurface);
        
        if (tempText == NULL) {
            cSTDOUT << "ImageManager: Unable to create texture from surface.  ";
            cSTDOUT << "SDL Error: " << SDL_GetError() << EOL;
            
            return NULL;
        }

        theSurface->setTexture(tempText);
        
        SDL_FreeSurface(tempSurface);
    }
    
    // cache the file for future loads
    m_ImageList[filename] = theSurface;
    
    return theSurface;
    
    
#endif
}



