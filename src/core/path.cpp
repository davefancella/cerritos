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

#ifdef BUILD_LINUX
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#endif

#include "path.h"
#include "types.h"

#ifdef USING_SDL
#include "sdl_backend.h"
#endif

using namespace cerritos;

Path::Path() {
    m_IsInit = false;
}

/// This method is declared static.
void Path::init(const char* programName, bool overwrite) {
    // Delegate to the instance
    _PATH.m_initialize(programName, overwrite);
}

/// This method is private, not static, and is called from the
/// static init method.
void Path::m_initialize(const char* programName, bool overwrite) {
    String p_name;
    
    // Do not initialize if we're already initialized
    if(isInit() && overwrite)
        return;
    
    if(programName != NULL) {
        p_name = Dirpath(programName).filename();
    } else {
        p_name = getProgramNameFile();
    }
    
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
            m_AllPaths["share"] = Dirpath("/usr/local/share/games") /= p_name;
            m_AllPaths["siteconfig"] = Dirpath("/usr/local/etc");
        }
        if(tmpPath == "/usr/local") {
            setPrefix("/usr/local");
            keepGoing = false;
            foundPrefix = true;
            m_AllPaths["share"] = Dirpath("/usr/local/share") /= p_name;
            m_AllPaths["siteconfig"] = Dirpath("/usr/local/etc");
        }
        if(tmpPath == "/usr/games") {
            setPrefix("/usr/games");
            keepGoing = false;
            foundPrefix = true;
            m_AllPaths["share"] = Dirpath("/usr/share/games") /= p_name;
            m_AllPaths["siteconfig"] = Dirpath("/etc");
        }
        if(tmpPath == "/usr") {
            setPrefix("/usr");
            keepGoing = false;
            foundPrefix = true;
            m_AllPaths["share"] = Dirpath("/usr/share") /= p_name;
            m_AllPaths["siteconfig"] = Dirpath("/etc");
        }
        tmpPath = tmpPath.parent_path();
        if(tmpPath == tmpPath.root_path() )
            keepGoing = false;
    }

    // What to do when the prefix is found
    if(foundPrefix) {
        const char *homedir;

        if ((homedir = getenv("XDG_CONFIG_HOME")) == NULL) {
            homedir = getpwuid(getuid())->pw_dir;
        }
        cSTDOUT << homedir << EOL;
        m_AllPaths["home"] = Dirpath(homedir);
        Dirpath userconfig = m_AllPaths["home"];
        String hname;
        hname = "." + p_name;
        userconfig /= hname;
        m_AllPaths["userconfig"] = userconfig;
    }
        
    #endif // BUILD_LINUX
    
    // Need to figure out how to handle a few things here before adding this
    //m_ConfigPath = new String(SDL_GetPrefsPath(const char *org, const char *app) );
#endif // USING_SDL
}

void Path::setPrefix(Dirpath prefix) {
    m_Prefix = prefix;
}

String Path::getProgramNameFile() {
    return String(m_ProgramName.filename() );
}

void Path::setProgramName(String programName) {
    m_ProgramName = programName;
}

void Path::showPaths() {
    cSTDOUT << "Program name: " << m_ProgramName << EOL;
    for (auto& t : m_AllPaths) {
        cSTDOUT << t.first << ": " 
                << t.second << EOL;
    }
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


