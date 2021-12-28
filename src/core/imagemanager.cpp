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

Surface* ImageManager::loadImageFromFile(const char* filename) {
    return loadImageFromFile(String(filename) );
}

Surface* ImageManager::loadImageFromFile(String filename) {
#ifdef USING_SDL
    SDL_Surface *tempSurface;
    
    if(m_Window == NULL) {
        cSTDOUT << "ImageManager: No m_Window initialized.  Cannot load image." << EOL;
        return NULL;
    }
    
    Surface* theSurface = new Surface(m_Window);
    
    tempSurface = IMG_Load(filename.data() );

    if(!tempSurface) {
        cSTDOUT << "ImageManager: " << IMG_GetError() << EOL;
    } else {
        theSurface->setSize(cSizeInt(tempSurface->w, tempSurface->h) );
        
        theSurface->setTexture(SDL_CreateTextureFromSurface(m_Window->getSDLRenderer(), tempSurface) );
        if (!theSurface->getTexture() ) {
            std::cout << "Unable to load create texture from surface! SDL Error: " << SDL_GetError() << "\n";
        }
        
        SDL_FreeSurface(tempSurface);
    }
    
    return theSurface;
    
    
#endif
}



