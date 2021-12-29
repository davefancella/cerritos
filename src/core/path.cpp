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

#include "platform.h"

#include "path.h"
#include "types.h"

#ifdef USING_SDL
#include "sdl_backend.h"
#endif

using namespace cerritos;

Path::Path() {
    #ifdef USING_SDL
    m_AppPath = SDL_GetBasePath();
        
    // Find Linux system directories
    #ifdef BUILD_LINUX
    
    Dirpath tmpPath = m_AppPath.parent_path();
    bool keepGoing = true;
    bool foundPrefix = false;
    
    while(keepGoing) {
        if(tmpPath == "/usr/local/games") {
            setPrefix("/usr/local/games");
            keepGoing = false;
            foundPrefix = true;
            m_AllPaths["share"] = Dirpath("/usr/local/share/games") /= m_ProgramName;
            m_AllPaths["siteconfig"] = Dirpath("/usr/local/etc");
        }
        if(tmpPath == "/usr/local") {
            setPrefix("/usr/local");
            keepGoing = false;
            foundPrefix = true;
            m_AllPaths["share"] = Dirpath("/usr/local/share") /= m_ProgramName;
            m_AllPaths["siteconfig"] = Dirpath("/usr/local/etc");
        }
        if(tmpPath == "/usr/games") {
            setPrefix("/usr/games");
            keepGoing = false;
            foundPrefix = true;
            m_AllPaths["share"] = Dirpath("/usr/share/games") /= m_ProgramName;
            m_AllPaths["siteconfig"] = Dirpath("/etc");
        }
        if(tmpPath == "/usr") {
            setPrefix("/usr");
            keepGoing = false;
            foundPrefix = true;
            m_AllPaths["share"] = Dirpath("/usr/share") /= m_ProgramName;
            m_AllPaths["siteconfig"] = Dirpath("/etc");
        }
        tmpPath = tmpPath.parent_path();
        if(tmpPath == tmpPath.root_path() )
            keepGoing = false;
    }
        
    #endif // BUILD_LINUX
    
    // Need to figure out how to handle a few things here before adding this
    //m_ConfigPath = new String(SDL_GetPrefsPath(const char *org, const char *app) );
    #endif // USING_SDL
    
    for (auto& t : m_AllPaths) {
        cSTDOUT << t.first << ": " 
                << t.second << EOL;
    }
}

void Path::setPrefix(Dirpath prefix) {
    m_Prefix = prefix;
}

void Path::setProgramName(String programName) {
    m_ProgramName = programName;
    m_AllPaths["share"] = m_AllPaths["share"] /= m_ProgramName;
    
    cSTDOUT << m_AllPaths["share"] << EOL;
}

String Path::getFilepath(String filename, String searchpath, bool useSysDirs) {
    if (m_AllPaths.has_key(searchpath)) {
        // Found the path
        return String( (m_AllPaths[searchpath] / filename).c_str() );
    }
    
    return String("");
}

/**
 * Gets the Path singleton.  You'll usually use the _PATH macro instead
 * of this
 */
Path& Path::get() {
    static Path* instance = new Path();
    
    return *instance;
}


