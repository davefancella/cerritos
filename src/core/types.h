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
 */

#ifndef TYPES__H
#define TYPES__H

#include <string>
#include <vector>
#include <map>

namespace cerritos {

#ifdef _WIN32
/** A simple string implementation, sorta.  Right now, it's just some
 * typedefs and defines that hopefully provide reasonable cross-platform
 * strings from the C++ standard library
 */
typedef std::wstring String;
#define UNI(text) L ## text
/*
std::string _formatForConsole(const String &str)
{
    std::string result;
    //Call WideCharToMultiByte to do the conversion
    return result;
}
*/
#else
/** A simple string implementation, sorta.  Right now, it's just some
 * typedefs and defines that hopefully provide reasonable cross-platform
 * strings from the C++ standard library
 */
typedef std::string String;
#define UNI(text) text
/*
std::string _formatForConsole(const String &str)
{
    return str;
}
*/
#endif

template<typename T>
using Dictionary = std::map<String, T>;

template<typename T>
using List = std::vector<T>;

}

#endif // TYPES__H


