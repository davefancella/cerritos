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

// This is a basic hello, world app for cerritos.  It breaks the convention
// of being the most basic code needed by opting for providing the code that
// is both correct and basic.  A simpler app is possible, but not suggested.

// Include the cerritos header file.  This brings in pretty much everything.
#include "cerritos.h"

using namespace cerritos;

// All cerritos games must subclass Application.  This is where all of your
// game code will live.  It's ok to separate your implementation into
// different files, some of the methods you have to implement are going to
// get pretty big.
class hello : public Application {
public:
    // This sets up the default constructor that processes commandline
    // arguments.  It is required in every Application subclass.
    // You cannot implement your own constructor.
    CONSTRUCTAPP(hello);
    
    // Since you cannot implement your own constructor, init() is provided.
    // It is called before any GUI is constructed, so if you don't use a gui,
    // you don't have to create one.  But since you'll probably use one,
    // because what's a game without a GUI, this is where you'll construct it.
    //
    // Here we just create the MainWindow and set its title, because this is
    // Hello, World!.
    void init() {
        setMainWindow(new cMainWindow("Hello, world!") );
    };
};

CERRITOSMAIN(hello)
