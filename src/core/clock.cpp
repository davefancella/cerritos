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

#include "clock.h"

#include "backend.h"

using namespace cerritos;

Clock::Clock() {
    // Start by setting up the timestep
    unsigned int newTimestep = GetTicks();

    firstTimestep = newTimestep;
    
    currentTimestep.fromBeginning = 0;
    currentTimestep.fromLast = 0;
    currentTimestep.fromBeginningSeconds = 0.0;
    currentTimestep.fromLastSeconds = 0.0;
}

void Clock::newTimestep() {
    unsigned int newTimestep;
    
    // update timestep
    newTimestep = GetTicks();
    
    currentTimestep.fromBeginning = newTimestep - firstTimestep;
    currentTimestep.fromLast = newTimestep - lastTimestep;
    currentTimestep.fromBeginningSeconds = static_cast<double>(
        newTimestep - firstTimestep)/1000;
    currentTimestep.fromLastSeconds = static_cast<double>(
        newTimestep - lastTimestep)/1000;
    
    lastTimestep = newTimestep;
}

Clock& Clock::get() {
    static Clock* instance = new Clock();
    
    return *instance;
}




