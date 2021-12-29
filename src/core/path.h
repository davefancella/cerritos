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

#include "types.h"

#ifndef PATH__H
#define PATH__H

// Includes and forward declarations go here

/// A useful macro that simple gives you the Path singleton
#define _PATH Path::get()

namespace cerritos {

/** The class that provides access to the filesystem in a cross-platform
 *  way.
 */
class Path {
public:    
    static Path& get();
    
    /**
     * The workhorse of the Path object.  Tell it a searchpath and give it
     * a filename, and you get an absolute path to that file.  Possible
     * searchpaths are things like "share" for shared data, /usr/share in
     * POSIX operating systems, "site-config" for site config, /etc in
     * POSIX operating systems, or "user-config" for user config, ~/.local/appname
     * in POSIX operating systems.
     * 
     * @param filename The name of the file you want to find.  No checking is
     *                 done to see if the file actually exists.
     * @param searchpath The type of path you want, like "share" or "userconfig"
     * @param useSysDirs Whether or not to also use system directories.  Default
     *                   is not to use system directories, because games are
     *                   expected to ship with everything they need to run.
     */
    String getFilepath(String filename, String searchpath, bool useSysDirs=false);

    /// Overloaded member for convenience.
    String getFilepath(const char* filename, const char* searchpath, bool useSysDirs=false) { 
        return getFilepath(String(filename), String(searchpath), useSysDirs); 
    };
    
    /// Overloaded member for convenience.
    String getFilepath(const char* filename, String searchpath, bool useSysDirs=false) { 
        return getFilepath(String(filename), searchpath, useSysDirs); 
    };
    
    /// Overloaded member for convenience.
    String getFilepath(String filename, const char* searchpath, bool useSysDirs=false) {
        return getFilepath(filename, String(searchpath), useSysDirs ); 
    };
    
    String getAppPath() { return m_AppPath; };
    
    void setPrefix(const char* prefix) {
        setPrefix(String(prefix) );
    }
    
    void setPrefix(Dirpath prefix);
    
    void setProgramName(const char* programName) {
        setProgramName(String(programName) );
    }
    void setProgramName(String programName);
    
    String getProgramNameFile();
    
    void setAppDirectory(const char* appdir) {
        setAppDirectory(String(appdir) );
    }
    void setAppDirectory(String appdir);
    
    /// Just show all paths currently stored in the object
    void showPaths();
    
private:
    Dirpath m_ProgramName;
    
    Dirpath m_AppPath;
    /// The prefix where the program is installed.  In Posix, this will
    /// be /usr or /usr/local, /usr/games, or /usr/local/games.
    Dirpath m_Prefix;
    
    Dictionary<Dirpath> m_AllPaths;
    Path();
};
    
} // namespace cerritos

#endif // PATH__H


