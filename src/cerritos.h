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

#ifndef CERRITOS_H
#define CERRITOS_H

/* This file is the base header file you need to include to use cerritos.
 */

#include "cerritos_version.h"

#include "backend.h"

#include "event.h"
#include "application.h"

namespace cerritos {

/// Simple function to take a variable list of flags and return a single
/// variable combining all flags together.
unsigned int flags(int num, ...);

/// Basic library initialization.  Call before you use the library.
void cInit();

/// Call this to cleanup the library when you're finished with it.
void cClose();

/// Initialize the library and get an application object with a an already
/// setup mainwindow
cApplication* cInitApp(CER_WindowFlags winFlags=CER_Shown);

/// Prints the cerritos library version
void PrintCerritosVersion();

} // namespace cerritos
#endif

