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

#include <filesystem>

#include "types.h"

#ifndef PATH__H
#define PATH__H

// Includes and forward declarations go here

namespace cerritos {

typedef std::filesystem::path Filepath;

/** The class that provides access to the filesystem in a cross-platform
 *  way.
 */
class Path {
public:    
    static Path& get();
    
    String getFilepath(String filename, String searchpath);

    /** 
     * The workhorse of the Path object.  Tell it a searchpath and give it
     * a filename, and you get an absolute path to that file.  Possible
     * searchpaths are things like "share" for shared data, /usr/share in
     * POSIX operating systems, "site-config" for site config, /etc in
     * POSIX operating systems, or "user-config" for user config, ~/.local/appname
     * in POSIX operating systems.
     */
    String getFilepath(const char* filename, const char* searchpath) { return getFilepath(String(filename), String(searchpath) ); };
    String getFilepath(const char* filename, String searchpath) { return getFilepath(String(filename), searchpath); };
    String getFilepath(String filename, const char* searchpath) { return getFilepath(filename, String(searchpath) ); };
    
    String getAppPath() { return m_AppPath; };
    
    void setAppDirectory(String appdir);
    
private:
    String m_AppPath;
    String* m_ConfigPath;
    
    Dictionary<Filepath> m_AllPaths;
    Path();
};
    
} // namespace cerritos

#endif // PATH__H


