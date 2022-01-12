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

#include "application.h"
#include "clock.h"
#include "event.h"
#include "path.h"

// This is a generated file that contains the macro for processing
// hardware events.
#include "hardwareeventprocessor.h"

using namespace cerritos;

/// Constructor.
Application::Application() {
}

void Application::setMainWindow(cMainWindow* window) {
    m_MainWindow = window;
    m_MainWindow->setApplication(this);
}

void Application::createMainWindow(CER_WindowFlags winFlags) {
    createMainWindow("Cerritos Window", 800, 600, CER_WindowPos_Centered, CER_WindowPos_Centered, winFlags);
}
void Application::createMainWindow(String title, CER_WindowFlags winFlags) {
    createMainWindow(title, 800, 600, CER_WindowPos_Centered, CER_WindowPos_Centered, winFlags);
}
void Application::createMainWindow(String title, int width, int height, CER_WindowFlags winFlags) {
    createMainWindow(title, width, height, CER_WindowPos_Centered, CER_WindowPos_Centered, winFlags);
}
/// Creates a cMainWindow for the Application.  Arguments are the same as
/// for cMainWindow constructors.
void Application::createMainWindow(String title, int width, int height, int posx, int posy, CER_WindowFlags winFlags) {
    setMainWindow(new cMainWindow(
                        title,
                        width, height, posx, posy,
                        winFlags
                      )
    );
}

cMainWindow* Application::getMainWindow() {
    return m_MainWindow;
}

bool Application::hasEvent() { 
    return eventManager->hasEvent();
}

Event* Application::PollEvent() {
    if(hasEvent())
        return eventManager->popEvent();
    
    return NULL;
}

void Application::BeginUpdate() {
    // Setup the new timestep
    _CLOCK.newTimestep();
    
    // Get system-specific events from the backend
    PollHardwareEvents(eventManager);
}

void Application::ProcessEvents() {
    // This is the main event processing loop
    while(hasEvent() ) {
        Event* anEvent = NULL;
        anEvent = PollEvent();
        
        // Callback for users of the library
        if(anEvent != NULL)
            BeginProcessOneEvent(anEvent);
        
        // Actually process the event
        if(anEvent != NULL)
            if(anEvent->isActive() ) {
                ProcessOneEventI(anEvent);
            }
        
        // Callback for users of the library
        if(anEvent != NULL)
            if(anEvent->isActive() ) {
                ProcessOneEvent(anEvent);
            }

        // Just some protection in case users delete the event.
        if(anEvent != NULL)
            delete anEvent;
    } 
}

void Application::onQuit(QuitEvent* event) {
    keepRunning = false;
}

void Application::Update() {
}

void Application::UpdateView() {
    if(m_MainWindow != NULL) {
        m_MainWindow->Update(_CLOCK.getTimestep() );
    }
}

void Application::UpdateAll() {
    BeginUpdate();
    ProcessEvents();
    Update();
    EndUpdate();
}

void Application::loop() {
    while(keepRunning) {
        UpdateAll();
    }
}

void Application::EndUpdate() {
    if(m_MainWindow != NULL) {
        m_MainWindow->renderAll(_CLOCK.getTimestep());
    }    
}

void Application::ProcessOneEventI(Event* evt) {
    // First delegate the event to the gui
    if(m_MainWindow != NULL) {
        m_MainWindow->process_event(evt);
    }
    
    // If it's still an active event, handle it here
    if(evt->isActive() )
        process_event(evt);
}

int Application::main(int argc, char* argv[]) {
    _PATH.setProgramName(argv[0]);
    Path::init();
    // Initialize the clock
    _CLOCK;
    
    // Create the event manager
    eventManager = new EventManager();
    
    // Setup miscellaneous stuff
    keepRunning = true;
    
    init();
    
    loop();
    
    return 0;
}

