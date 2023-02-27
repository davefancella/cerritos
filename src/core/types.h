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

/** @file types.h
 * 
 * This file contains numerous types that are useful but don't
 * belong in their own headers.
 * 
 * Everything includes this file, so if you change it, all of cerritos will
 * be rebuilt.
 */

#ifndef TYPES__H
#define TYPES__H

#include <filesystem>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#include "map.h"
#include "point.h"

/// Use this instead of cout from iostream.
#define cSTDOUT std::cout
#define EOL std::endl

#define _USE_MATH_DEFINES
#include <cmath>

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

#ifndef M_PIl
#define M_PIl (3.14159265358979323846264338327950288)
#endif

// Just a random bit here that I wrote because I didn't have enough bandwidth
// to google up the proper standard library constant to use here
#define cerpi M_PI

/// Converts angles to/from radians/degrees
#define DEGREES(angle) (angle * 180/cerpi)
#define RADIANS(angle) (angle * cerpi/180)

namespace cerritos {

/** 
 * This enum represents the three basic GUI modes.
 * 
 * - AppGUI: The Application GUI, which is typically the GUI that contains
 *           configuration, user settings, and the start game option.
 * - gameGUI: The Game GUI, which is the GUI that is shown overlaid on top
 *            of the game screen as you're playing.  It's often just a
 *            simple HUD.
 * - inGameGUI: The In-game GUI, which is the GUI that you bring up in-game
 *              to do whatever, including quitting the game and returning
 *              to the AppGUI.
 * 
 */
typedef enum {
    appGUI,
    gameGUI,
    inGameGUI
} GUIMode;
    

/** @class String
 * 
 * A simple string implementation, sorta.  Right now, it's just some
 * typedefs and defines that hopefully provide reasonable cross-platform
 * strings from the C++ standard library
 */
typedef std::string String;

typedef std::filesystem::path Dirpath;

template<typename T>
using Dictionary = cMap<String, T>;

template<typename T>
using List = std::vector<T>;

template<typename T>
using Queue = std::queue<T>;

struct Line {PointInt s; PointInt e; };

}

#endif // TYPES__H


