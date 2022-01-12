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

#include <cstdarg>
#include <iostream>

#include "binreloc.h"

#include "application.h"
#include "cerritos_version.h"
#include "cerritosbase.h"
#include "imagemanager.h"
#include "mainwindow.h"
#include "path.h"
#include "types.h"

using namespace cerritos;

void cerritos::PrintCerritosVersion() {
    cSTDOUT << "Cerritos Version " 
              << CERRITOS_VERSION_MAJOR << "."
              << CERRITOS_VERSION_MINOR << "."
              << CERRITOS_VERSION_PATCH << "."
              << EOL;
}

/** Initialize cerritos
 */
void cerritos::cInit() {
    PrintCerritosVersion();
    backendInit();
    
#ifdef BUILD_LINUX
    // Setup binreloc
    br_init();
#endif
    
    // Create the path singleton without initializing it
    _PATH;
    // Create the imageloader singleton without initializing it
    _IMG;
};

/** Close cerritos
 */
void cerritos::cClose() {
    backendClose();
};

unsigned int cerritos::flags(int num, ...) {
    va_list args;
    unsigned int returnFlags = 0;
    int i;

    /* initialize valist for num number of arguments */
    va_start(args, num);

    /* access all the arguments assigned to valist */
    for (i = 0; i < num; i++) {
        returnFlags = returnFlags | va_arg(args, int);
    }
        
    /* clean memory reserved for valist */
    va_end(args);

    return returnFlags;
};

