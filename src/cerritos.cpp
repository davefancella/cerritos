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

#include "cerritos.h"
#include "application.h"
#include "mainwindow.h"

using namespace cerritos;

void cerritos::PrintCerritosVersion() {
    std::cout << "Cerritos Version " 
              << CERRITOS_VERSION_MAJOR << "."
              << CERRITOS_VERSION_MINOR << "."
              << CERRITOS_VERSION_PATCH << "."
              << std::endl;
}

/** Initialize cerritos
 */
void cerritos::cInit() {
    PrintCerritosVersion();
    backendInit();
};

/// Initializes and creates a default application object
Application* cerritos::cInitApp(CER_WindowFlags winFlags) {
    PrintCerritosVersion();
    if(backendInit() == -1)
        return NULL;
    
    Application* theApp = new Application();
    cMainWindow* mainWindow = new cMainWindow(winFlags);
    
    theApp->setMainWindow(mainWindow);
    
    return theApp;
}

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

