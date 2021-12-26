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

#include <iostream>

#include "backend.h"

#include "application.h"
#include "event.h"

// This is a generated file that contains the macro for processing
// hardware events.
#include "hardwareeventprocessor.h"

using namespace cerritos;

/// Constructor.
Application::Application(int argc, char* argv[]) {
    // Start by setting up the timestep
    unsigned int newTimestep = GetTicks();

    this->firstTimestep = newTimestep;
    
    this->currentTimestep.fromBeginning = 0;
    this->currentTimestep.fromLast = 0;
    
    // Create the event manager
    this->eventManager = new EventManager();
    
    // Setup miscellaneous stuff
    this->keepRunning = true;
}

void Application::setMainWindow(cMainWindow* window) {
    this->mainwindow = window;
}

cMainWindow* Application::getMainWindow() {
    return this->mainwindow;
}

bool Application::hasEvent() { 
    return this->eventManager->hasEvent();
}

Event* Application::PollEvent() {
    if(this->hasEvent())
        return this->eventManager->popEvent();
    
    return NULL;
}

const Timestep Application::getTimestep() {
    return this->currentTimestep;
}

void Application::BeginUpdate() {
    unsigned int newTimestep;
    
    // update timestep
    newTimestep = SDL_GetTicks();
    
    this->currentTimestep.fromBeginning = newTimestep - this->firstTimestep;
    this->currentTimestep.fromLast = newTimestep - this->lastTimestep;
    
    this->lastTimestep = newTimestep;

    // Get system-specific events from the backend
    PollHardwareEvents(this->eventManager);
}

void Application::ProcessEvents() {
    // This is the main event processing loop
    while(this->hasEvent() ) {
        Event* anEvent = NULL;
        anEvent = this->PollEvent();
        
        // Callback for users of the library
        if(anEvent != NULL)
            this->BeginProcessOneEvent(anEvent);
        
        // Actually process the event
        if(anEvent != NULL)
            if(anEvent->isActive() ) {
                this->ProcessOneEventI(anEvent);
            }
        
        // Callback for users of the library
        if(anEvent != NULL)
            if(anEvent->isActive() ) {
                this->ProcessOneEvent(anEvent);
            }

        // Just some protection in case users delete the event.
        if(anEvent != NULL)
            delete anEvent;
    } 
}

void Application::onQuit(QuitEvent* event) {
    this->keepRunning = false;
}

void Application::Update() {
}

void Application::UpdateView(const Timestep timestep) {
    if(this->mainwindow != NULL) {
        this->mainwindow->Update(timestep);
    }
}

void Application::UpdateAll(const Timestep timestep) {
    this->BeginUpdate();
    this->ProcessEvents();
    this->Update();
    this->UpdateView(timestep);
    this->EndUpdate();
}

void Application::loop() {
    while(keepRunning) {
        UpdateAll(this->getTimestep());
    }
}

void Application::EndUpdate() {
    if(this->mainwindow != NULL) {
        this->mainwindow->renderAll(this->getTimestep());
    }    
}

void Application::ProcessOneEventI(Event* evt) {
    // First delegate the event to the gui
    if(this->mainwindow != NULL) {
        this->mainwindow->process_event(evt);
    }
    
    // If it's still an active event, handle it here
    if(evt->isActive() )
        this->process_event(evt);
}

