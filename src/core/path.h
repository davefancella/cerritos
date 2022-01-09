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
    /**
     * Gets the singleton Path instance.  Use the _PATH macro instead.
     */
    static Path& get();

    /**
     * Initializes the Path instance.  It must be called from outside
     * the constructor (duh).  Application will call it and set the
     * program name to whatever's in argv[0].  Application will not
     * reinitialize, however, so if you initialize the Path instance
     * before creating Application, you can overright Application.
     *
     * @param programName the name of your program.  If NULL, it will
     *                    use m_ProgramName, which is set by calling
     *                    setProgramName.
     * @param overwrite If you want to overwrite the existing object
     *                  because it has already been initialized, set to
     *                  true.  It's usually safest to leave it alone.
     */
    static void init(const char* programName=NULL, bool overwrite=false);
    
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
    const Dirpath getFilepath(String searchpath, String filename, bool useSysDirs=false);

    /// Overloaded member for convenience.
    String getFilepath(const char* searchpath, const char* filename, bool useSysDirs=false) { 
        return getFilepath(String(searchpath), String(filename), useSysDirs); 
    };
    
    /// Overloaded member for convenience.
    String getFilepath(String searchpath, const char* filename, bool useSysDirs=false) { 
        return getFilepath(searchpath, String(filename), useSysDirs); 
    };
    
    /// Overloaded member for convenience.
    String getFilepath(const char* searchpath, String filename, bool useSysDirs=false) {
        return getFilepath(String(searchpath), filename, useSysDirs ); 
    };
    
    /**
     * Sets the name of the asset dir.  In Linux, this means the following things:
     * If the prefix is /usr/games, the asset directory will be /usr/share/games/PROGRAMNAME/ASSETDIR
     * If the prefix is /usr, the asset directory will be /usr/share/PROGRAMNAME/ASSETDIR
     * If you're running from a directory, the asset directory will be "./ASSETDIR".
     * If you're running from a **build** directory, the asset directory will be "../ASSETDIR"
     */
    void setAssetDir(String newAssetDir);
    
    /// Overloaded member for convenience.
    void setAssetDir(const char* newAssetdir) {
        setAssetDir(String(newAssetdir) );
    };
    
    String getAssetDir() { return m_AssetDir; };
    
    String getAppPath() { return m_AppPath; };
    
    void setPrefix(const char* prefix) {
        setPrefix(String(prefix) );
    }
    
    void setPrefix(Dirpath prefix);
    
    Dirpath getPrefix() {
        return m_Prefix;
    };
    
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
    
    bool isInit() {
        return m_IsInit;
    }
    
private:
    /// The name of the asset directory to be searched.  Can be configured.
    String m_AssetDir;
    /// The name of the config directory
    String m_Siteconfig;
    
    bool m_IsInit;
    Dirpath m_ProgramName;
    
    // Current working directory
    Dirpath m_Cwd;
    
    Dirpath m_AppPath;
    
    /// The prefix where the program is installed.  In Posix, this will
    /// be /usr or /usr/local, /usr/games, or /usr/local/games.
    Dirpath m_Prefix;
    
    Dictionary<Dirpath> m_AllPaths;

    /// The method that initializes the path instance
    void m_initialize(const char* programName=NULL, bool overwite=false);

    Path();
};
    
} // namespace cerritos

#endif // PATH__H


