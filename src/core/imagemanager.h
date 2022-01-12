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

#ifndef IMAGEMANAGER__H
#define IMAGEMANAGER__H

#include "path.h"
#include "types.h"

// Includes and forward declarations go here

/// A useful macro that gets you the ImageManager's singleton
#define _IMG ImageManager::get()

namespace cerritos {

class Surface;
class Window;

/**
 * Manages images on disk, loads them into memory, etc.
 */
class ImageManager {
public:
    static ImageManager& get();
    
    void setWindow(Window* newWindow);
    
    Surface* loadFromFile(const char* filename);
    Surface* loadFromFile(String filename);
    
    /**
     * Load a file using the Path object.
     */
    Surface* loadPath(String searchpath, String filename);
    /// Overloaded for convenience
    Surface* loadPath(const char* searchpath, const char* filename) {
        return loadPath(String(searchpath), String(filename) );
    };
    /// Overloaded for convenience
    Surface* loadPath(String searchpath, const char* filename) {
        return loadPath(searchpath, String(filename) );
    };
    /// Overloaded for convenience
    Surface* loadPath(const char* searchpath, String filename) {
        return loadPath(String(searchpath), filename);
    };
    
    Window* getWindow() { return m_Window; };
private:
    Window* m_Window;
    
    Dictionary<Surface*> m_ImageList;
    
    ImageManager();
};
    
} // namespace cerritos

#endif // IMAGEMANAGER__H


