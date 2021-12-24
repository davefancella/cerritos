#!/usr/bin/env python3

# This script generates cerritos event header files and support code
# from SDL event types.  Since cerritos considers all of these things
# "hardware events", it's all backend code and glue code that gets
# generated.  If you write a new backend, you'll need a separate script
# to do the generations there, or do it by hand.  It's your time.  You
# do you.

# This script could be made more robust.  But it only has to run
# in a posix environment.  The files generated are added to the source
# repository, because they only need to be re-generated when SDL
# gets an update that includes any new or reshuffled hardware events.

import os, sys

printHeaders = False
saveHeaders = True

printSwitch = False
saveSwitch = True

printIncludes = False
saveIncludes = True

saveEnums = True
saveEventClass = True
saveEventProcessor = True

srcDir = "../src/"
eventDir = "core/events/hardware"
eventDir = os.path.join(srcDir, eventDir)

def main():
    global printHeaders, saveHeaders, printSwitch, saveSwitch, printIncludes, saveIncludes
    global eventDir

    caseFile = os.path.join(srcDir, "backend", "sdl_poll_hardware_events.cpp")
    includeFile = os.path.join(eventDir, "hardwareevents.h")
    hardwareEnumFile = os.path.join(eventDir, "sdl_hardwareventEnum.h")
    #hardwareEnumFile = os.path.join("./", "sdl_hardwareventEnum.h")
    eventClassFile = os.path.join(eventDir, "hardwareeventreceiver.h")
    eventProcessorFile = os.path.join(eventDir, "hardwareeventprocessor.h")

    maxLength = 0

    capStrings = [
        "Device",
        "Audio",
        "Motion", "Input", "Editing", "File", "Remapped", "Wheel",
        "Gesture", "Record", "Axis", "Ball", "Hat", "Button",
        "Added", "Removed", "Begin", "Text", "Complete", "Update",
    ]

    theString = ""
    
    with open('SDLeventTypes') as f:
        theString = f.readlines()
    f.close()
    
    evList = []
    
    newEvent = {}
    for a in theString:
        a = a.strip()

        # ignore empty lines
        if(len(a) == 0): continue
        # ignore comments
        if(a.startswith("#") or a.startswith("//") ): continue
    
        if(a.startswith("SDL") ):
            sdlET = a
            if(len(newEvent) != 0):
                evList.append(newEvent)

            membername = ''
            if(a.find(":") != -1):
                sdlET, membername = a.split(":")
            
            newEvent = {
                "SDL" : sdlET.strip(),
                "members" : [],
                'membername' : membername.strip()
            }
        else:
            # Parse the individual pieces of an event
            if(a.find(":") != -1):
                cerType, sdlType = a.split(":")
                cerMember = cerType[0:cerType.find("(")]
                cerMemberType, ctrArg = cerType[cerType.find("(")+1:cerType.find(")")].split(",")
                newEvent['members'].append( {
                    "member" : cerMember.strip(),
                    "mType" : cerMemberType.strip(),
                    "arg" : ctrArg.strip(),
                    'sdltype' : sdlType.strip(),
                } )
                    
            
    # Finish the last one
    evList.append(newEvent)
    
    if(saveSwitch):
        aFile = open(caseFile, "w")
        aFile.write(beginSDLPoller)
        aFile.close()
        
    if(saveIncludes):
        aFile = open(includeFile, "w")
        aFile.write(beginHardwareIncludes)
        aFile.close()
    
    if(saveEnums):
        aFile = open(hardwareEnumFile, "w")
        aFile.write(beginHardwareEnums)
        aFile.close()
        
    if(saveEventClass):
        aFile = open(eventClassFile, "w")
        aFile.write(beginEventHandlerClass)
        aFile.close()
    
    if(saveEventProcessor):
        aFile = open(eventProcessorFile, "w")
        aFile.write(beginEventProcessor)
        aFile.close()

    for a in evList:
        sdlEvent = a['SDL']

        if len(sdlEvent) > maxLength:
            maxLength = len(sdlEvent)
        
        theValues = sdlEvent.split("_")
        
        cerName = "CER_"
        headerName = ""
        className = "c"
        eventHandlerName = "on"
        
        for b in theValues:
            if b == "SDL": continue
            if b.lower() == "EVENT": continue
            
            b = b.replace("EVENT", "")
            
            cerName += b.capitalize()
            className += b.capitalize()
            headerName += b.lower()
            eventHandlerName += b.capitalize()
        
        headerNameCaps = headerName.upper() + "EVENT"
        headerName += "event.h"
        cerName = cerName + "Event"
        className += "Event"
        
        for c in capStrings:
            cerName = cerName.replace(c.lower(), c)
            className = className.replace(c.lower(), c)
            eventHandlerName = eventHandlerName.replace(c.lower(), c)

        # print the new cerritos enum name for this event
        #print(f'    {cerName},')
        
        header = outputHeader.replace("$HEADERNAMECAPS", headerNameCaps)
        header = header.replace("$eventtype", cerName)
        header = header.replace("$classname", className)
        
        newCtrArgs = ''

        if(len(a['members']) == 0):
            # Direct the writer to trim these lines completely
            header = header.replace("$members", "$trim")
            header = header.replace("$constructor", "$trim")
        else:
            ctrArgs = ''
            ctrArglist = []
            newCtrArgs = ''
            newCtrArglist = []
            memberinit = ''
            memberinitList = []
            memberDeclarations = []
            for member in a['members']:
                ctrArglist.append(member['mType'] + " " + member['arg'])
                newCtrArglist.append("event." + a['membername'] + "." + member['sdltype'])
                memberinitList.append("        " + member['member'] + " = " + member['arg'] + ";")
                memberDeclarations.append(
                    member['mType'] + " " + member['member'] + ";"
                )
            ctrArgs = ", ".join(ctrArglist)
            newCtrArgs = ", ".join(newCtrArglist)
            memberinit = "\n".join(memberinitList)
            
            memberT = memberText.replace("$eventtype", cerName)
            memberT = memberT.replace("$classname", className)
            memberT = memberT.replace("$args", ctrArgs)

            memberD = "\n    ".join(memberDeclarations)
                        
            header = header.replace("$constructor", memberT)
            header = header.replace("$memberinit", memberinit)
            header = header.replace("$members", memberD)
        
        headerText = ''
        for line in header.split("\n"):
            if line.strip() != "$trim":
                headerText += line + "\n"
        
        caseT = ''
        if(len(a['members']) == 0):
            caseT = caseText
        else:
            caseT = caseMemberText
            
        casestatement = caseT.replace("$classname", className)
        casestatement = casestatement.replace("$eventtype", cerName)
        casestatement = casestatement.replace("$sdlevent", sdlEvent)
        casestatement = casestatement.replace("$args", 
                "\n                    " + newCtrArgs + 
                "\n                ")

        # print or write the include statement needed
        includeString = '#include "' + headerName + '"'
        
        functionString = eventHandlerFunction.replace("$funcname", eventHandlerName)
        functionString = functionString.replace("$eventtype", className)
        
        eventProcessorString = eventProcessor.replace("$eventtype", cerName)
        eventProcessorString = eventProcessorString.replace("$eventhandler", eventHandlerName)
        eventProcessorString = eventProcessorString.replace("$eventclass", className)
        
        if(printIncludes): print(includeString)
        
        if(saveIncludes):
            aFile = open(includeFile, "a")
            aFile.write(includeString + "\n")
            aFile.close()
        
        # Write the header (.h) file
        if(printHeaders):
            print(headerText)
        
        if(saveHeaders):
            aFile = open(os.path.join(eventDir,headerName), "w")
            aFile.write(headerText)
            aFile.close()
            
        if(saveEnums):
            aFile = open(hardwareEnumFile, "a")
            aFile.write(cerName + ", \\\n")
            aFile.close()
        
        # print the code for the case statement for this event
        if(printSwitch):
            print(casestatement)

        if(saveSwitch):
            aFile = open(caseFile, "a")
            
            for line in casestatement.split("\n"):
                aFile.write(line + "\n")
            aFile.close()
            
        if(saveEventClass):
            aFile = open(eventClassFile, "a")
            aFile.write(functionString + "\n\n")
            aFile.close()
            
        if(saveEventProcessor):
            aFile = open(eventProcessorFile, "a")
            aFile.write(eventProcessorString + "\n")
            aFile.close()
            
    if(saveSwitch):
        aFile = open(caseFile, "a")
        aFile.write(endSDLPoller)
        aFile.close()
    if(saveIncludes):
        aFile = open(includeFile, "a")
        aFile.write(endHardwareIncludes)
        aFile.close()
    if(saveEnums):
        aFile = open(hardwareEnumFile, "a")
        aFile.write(endHardwareEnums)
        aFile.close()
    if(saveEventClass):
        aFile = open(eventClassFile, "a")
        aFile.write(endEventHandlerClass)
        aFile.close()
    if(saveEventProcessor):
        aFile = open(eventProcessorFile, "a")
        aFile.write(endEventProcessor)
        aFile.close()
    
            

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

// This file is periodically generated.  Do not edit it directly.

#ifndef $HEADERNAMECAPS__H
#define $HEADERNAMECAPS__H

namespace cerritos {

class $classname : public cEvent {
public:
    $classname() { 
        evtype=$eventtype; 
    };
    $constructor
    $members
};

}

#endif // $HEADERNAMECAPS__H
'''

memberText = '''
    $classname($args) { 
        evtype = $eventtype;
$memberinit
    };'''

caseText = '''            case $sdlevent:
                newEvent = new $classname;
                break;'''
caseMemberText = '''            case $sdlevent:
                newEvent = new $classname($args);
                break;'''

beginSDLPoller = '''/*
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
 
#include <iostream>

#include "SDL.h"

#include "sdl_backend.h"

#include "event.h"

// This file is periodically generated.  Do not edit it directly.
 
using namespace cerritos;
 
void cerritos::PollHardwareEvents(cEventManager* eventManager) {
    // Get SDL events
    SDL_Event event;
    cEvent* newEvent = NULL;
    
    while (SDL_PollEvent(&event)) {
        newEvent = NULL;
        switch (event.type) {
'''

endSDLPoller = '''            default:
                // std::cout << "Unhandled Event!" << std::endl;
                break;
        }
        if(newEvent != NULL)
            eventManager->addEvent( (cEvent*) newEvent);
    }
}

'''

beginHardwareIncludes = '''/*
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
 
// This file is periodically generated.  Do not edit it directly.
'''

endHardwareIncludes = '''

'''

beginHardwareEnums = '''/*
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

// This file is periodically generated.  Do not edit it directly.

#define HARDWAREENUM \\
'''

endHardwareEnums = '''

'''

beginEventHandlerClass = '''/*
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

#ifndef HARDWAREEVENTRECEIVER__H
#define HARDWAREEVENTRECEIVER__H

#include "event.h"

// This file is periodically generated.  Do not edit it directly.

namespace cerritos {

class cHardwareEventReceiver {
public:
    cHardwareEventReceiver() { };
    
'''

eventHandlerFunction = '    virtual void $funcname($eventtype* event) { };'

endEventHandlerClass = '''};

}

#endif // HARDWAREEVENTRECEIVER__H


'''

beginEventProcessor = '''/*
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

// This file is periodically generated.  Do not edit it directly.

#define PROCESSHARDWAREEVENTS \\
'''

eventProcessor = '''        case $eventtype: \\
            this->$eventhandler(static_cast<$eventclass*>(event) ); \\
            break; \\'''

endEventProcessor = '''

'''

main()

