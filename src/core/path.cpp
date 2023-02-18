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
#include "binreloc.h"

#define MAX_BUF 200

#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <errno.h>
#endif

#include "path.h"
#include "types.h"

#ifdef USING_SDL
#include "sdl_backend.h"
#endif

using namespace cerritos;

Path::Path() {
    m_IsInit = false;
    m_AssetDir = "assets";
    m_Siteconfig = "config";
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
        p_name = Dirpath(programName).filename().u8string();
    } else {
        p_name = getProgramNameFile();
    }
    
#ifdef BUILD_LINUX
    BrInitError* brErr = NULL;
    
    // For the getcwd function
    char pathcwd[MAX_BUF];
    errno = 0;
    
    if (getcwd(pathcwd, MAX_BUF) == NULL) {
        if (errno == ERANGE)
            cSTDOUT << "[ERROR] pathname length exceeds the buffer size" << EOL;
        else
            perror("getcwd");
        //exit(EXIT_FAILURE);
    }
    
    m_Cwd = pathcwd;
    
    if(br_init(brErr) ) {
        
        m_AppPath = Dirpath(br_find_exe_dir(p_name.data() ) );
        
        // Look for the games path so we can set our Prefix correctly
        if(m_AppPath == "/usr/games" || m_AppPath == "/usr/local/games") {
            setPrefix(m_AppPath);
        } else {
            setPrefix(br_find_prefix(NULL) );
        }
        
        // Check to see if we're running in the prefix.  This code may
        // have issues if someone runs it where cwd == /usr or something
        // like that.  Otherwise, it's searching a source tree for files.
        if(m_Prefix == m_Cwd) {
            if(m_Prefix.filename() == "build") {
                m_AllPaths["share"] = Dirpath("../") /= m_AssetDir;
                m_AllPaths["siteconfig"] = Dirpath("../") /= m_Siteconfig;
            } else {
                // We're probably running from a binary archive directory
                // or somesuch.  This code should be rarely used, if ever.
                m_AllPaths["share"] = Dirpath("./") /= m_AssetDir;
                m_AllPaths["siteconfig"] = Dirpath("./") /= m_Siteconfig;
            }
        } else {
            // Find Linux system directories
            Dirpath tmpPath = getPrefix();
            bool keepGoing = true;
            bool foundPrefix = false;
            
            m_AllPaths["share"] = Dirpath(br_find_data_dir("./") ) /= p_name;
            m_AllPaths["siteconfig"] = Dirpath("/etc") /= p_name;
            
            // Work out locations if we're in a games prefix.  This is a
            // common installed prefix for Linux distributions.
            while(keepGoing) {
                if(tmpPath == "/usr/local/games") {
                    setPrefix("/usr/local/games");
                    keepGoing = false;
                    foundPrefix = true;
                    m_AllPaths["share"] = Dirpath("/usr/local/share/games") /= p_name;
                    m_AllPaths["siteconfig"] = Dirpath("/usr/local/etc") /= p_name;;
                }
                if(tmpPath == "/usr/games") {
                    setPrefix("/usr/games");
                    keepGoing = false;
                    m_AllPaths["share"] = Dirpath("/usr/share/games") /= p_name;
                    m_AllPaths["siteconfig"] = Dirpath("/etc") /= p_name;;
                }
                tmpPath = tmpPath.parent_path();
                if(tmpPath == tmpPath.root_path() )
                    keepGoing = false;
            }
            
            // Now setup the userconfig directories
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
    }
#elif defined(_WIN32)
    // Windows stuff goes here
#elif defined(USING_OSX)
    // Mac OS X stuff goes here
#endif

    // Now all the OS specific paths have been found, it's time to
    // add all the rest that are built on top of those
    m_AllPaths["images"] = Dirpath(m_AllPaths["share"]) /= "images";
    m_AllPaths["sprites"] = Dirpath(m_AllPaths["share"]) /= "sprites";
    m_AllPaths["fonts"] = Dirpath(m_AllPaths["share"]) /= "fonts";
    m_AllPaths["sounds"] = Dirpath(m_AllPaths["share"]) /= "sounds";
    m_AllPaths["music"] = Dirpath(m_AllPaths["share"]) /= "music";

}

void Path::setPrefix(Dirpath prefix) {
    m_Prefix = prefix;
}

void Path::setAssetDir(String newAssetdir) {
    m_AssetDir = newAssetdir;
}

String Path::getProgramNameFile() {
    return m_ProgramName.filename().u8string();
}

void Path::setProgramName(String programName) {
    m_ProgramName = programName;
}

void Path::showPaths() {
    cSTDOUT << "Program name: " << m_ProgramName << EOL;
    cSTDOUT << "App Path: " << m_AppPath << EOL;
    cSTDOUT << "Prefix: " << m_Prefix << EOL;
    for (auto& t : m_AllPaths) {
        cSTDOUT << t.first << ": " 
                << t.second << EOL;
    }
}

const Dirpath Path::getFilepath(String searchpath, String filename, bool useSysDirs) {
    if (m_AllPaths.has_key(searchpath)) {
        // Found the path
        return (m_AllPaths[searchpath] / filename).u8string();
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


