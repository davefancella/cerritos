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

#ifndef MACROS__H
#define MACROS__H

/** @file
 * 
 * This file contains useful and important macros that don't have
 * a specific home, or for whom this file is the most specific home.
 */

/** This macro provides a main loop.  Using it enables more Java-style
 *  programming.  The arguments provide the names of the classes used.
 * 
 *  @arg app : The name of your Application class.
 *  @arg window : The name of your cMainWindow class.
 */
#define CERRITOSMAIN(app) \
int main( int argc, char* argv[] ) { \
    app* theApp; \
\
    cInit(); \
\
    theApp = new app(); \
\
    int retValue = theApp->main(argc, argv); \
\
    cClose(); \
    return retValue;\
}\




// Includes and forward declarations go here

namespace cerritos {

// Code goes here
    
} // namespace cerritos

#endif // MACROS__H


