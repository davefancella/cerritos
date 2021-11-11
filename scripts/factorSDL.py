#!/usr/bin/env python3

# This script just takes a list of SDL variables with other crap and outputs
# a single list of only those variables

# Modify as needed when translating SDL enums to Cerritos enums

theString = '''

SDL_WINDOWEVENT

window state change

SDL_SYSWMEVENT

system specific event

<bgcolor="#EDEDED">Keyboard events

SDL_KEYDOWN

key pressed

SDL_KEYUP

key released

SDL_TEXTEDITING

keyboard text editing (composition)

SDL_TEXTINPUT

keyboard text input

SDL_KEYMAPCHANGED

keymap changed due to a system event such as an input language or keyboard layout change (>=  .0.4)

<bgcolor="#EDEDED">Mouse events

SDL_MOUSEMOTION

mouse moved

SDL_MOUSEBUTTONDOWN

mouse button pressed

SDL_MOUSEBUTTONUP

mouse button released

SDL_MOUSEWHEEL

mouse wheel motion

<bgcolor="#EDEDED">Joystick events

SDL_JOYAXISMOTION

joystick axis motion

SDL_JOYBALLMOTION

joystick trackball motion

SDL_JOYHATMOTION

joystick hat position change

SDL_JOYBUTTONDOWN

joystick button pressed

SDL_JOYBUTTONUP

joystick button released

SDL_JOYDEVICEADDED

joystick connected

SDL_JOYDEVICEREMOVED

joystick disconnected

<bgcolor="#EDEDED">Controller events

SDL_CONTROLLERAXISMOTION

controller axis motion

SDL_CONTROLLERBUTTONDOWN

controller button pressed

SDL_CONTROLLERBUTTONUP

controller button released

SDL_CONTROLLERDEVICEADDED

controller connected

SDL_CONTROLLERDEVICEREMOVED

controller disconnected

SDL_CONTROLLERDEVICEREMAPPED

controller mapping updated

<bgcolor="#EDEDED">Touch events

SDL_FINGERDOWN

user has touched input device

SDL_FINGERUP

user stopped touching input device

SDL_FINGERMOTION

user is dragging finger on input device

<bgcolor="#EDEDED">Gesture events

SDL_DOLLARGESTURE

SDL_DOLLARRECORD

SDL_MULTIGESTURE

<bgcolor="#EDEDED">Clipboard events

SDL_CLIPBOARDUPDATE

the clipboard changed

<bgcolor="#EDEDED">Drag and drop events

SDL_DROPFILE

the system requests a file open

SDL_DROPTEXT

text/plain drag-and-drop event

SDL_DROPBEGIN

a new set of drops is beginning (>=  .0.5)

SDL_DROPCOMPLETE

current set of drops is now complete (>=  .0.5)

<bgcolor="#EDEDED">Audio hotplug events

SDL_AUDIODEVICEADDED

a new audio device is available (>=  .0.4)

SDL_AUDIODEVICEREMOVED

an audio device has been removed (>=  .0.4)

<bgcolor="#EDEDED">Render events

SDL_RENDER_TARGETS_RESET

the render targets have been reset and their contents need to be updated (>=  .0.2)

SDL_RENDER_DEVICE_RESET

the device has been reset and all textures need to be recreated (>=  .0.4)


only for bounding internal arrays'''

outputHeader = '''/*
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

#include "event.h"

#ifndef $HEADERNAMECAPS__H
#define $HEADERNAMECAPS__H

// \\todo: full implement this class
class $classname : public cEvent {
public:
    $classname() { evtype=$eventtype; };
};

#endif // $HEADERNAMECAPS__H


'''

import sys

maxLength = 0

eventDir = "../src/core/events/"

capStrings = [
    "Device",
    "Audio",
    "Motion", "Input", "Editing", "File", "Remapped", "Wheel",
    "Gesture", "Record", "Axis", "Ball", "Hat", "Button",
    "Added", "Removed", "Begin", "Text", "Complete", "Update",
]

for a in theString.split():
    a = a.strip()
    
    if len(a) == 0: continue

    if len(a[3:]) > maxLength:
        maxLength = len(a[3:])
    
    if a.startswith("SDL"):
        print("            case " + a + ":")
        
    
sys.exit()

'''
        theValues = a.split("_")
        #print(theValues)
        
        cerName = "CER_"
        headerName = ""
        className = "c"
        
        for b in theValues:
            if b == "SDL": continue
            if b.lower() == "EVENT": continue
            
            b = b.replace("EVENT", "")
            
            cerName = cerName + b.capitalize()
            className += b.capitalize()
            headerName += b.lower()
        
        headerNameCaps = headerName.upper() + "EVENT"
        headerName += "event.h"
        cerName = cerName + "Event"
        className += "Event"
        
        for c in capStrings:
            cerName = cerName.replace(c.lower(), c)
            className = className.replace(c.lower(), c)

        print(f'    {cerName},')
        
        header = outputHeader.replace("$HEADERNAMECAPS", headerNameCaps)
        header = header.replace("$eventtype", cerName)
        header = header.replace("$classname", className)
        
        #print(header)
        aFile = open("includes", "a")
        
        aFile.write("#include \"" + headerName + "\"\n")
        aFile.close()
        
        aFile = open(eventDir + headerName, "w")
        
        for line in header.split("\n"):
            aFile.write(line + "\n")
        aFile.close()
        
        #sys.exit()
'''

