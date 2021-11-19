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

#ifndef APPLICATION__H
#define APPLICATION__H

#include "object.h"
#include "event.h"
#include "eventreceiver.h"
#include "mainwindow.h"

class cApplication : public cObject,
                     public cBaseEventReceiver {
public:
    cApplication();
    
    // Set the main window for the object.  If it's not set, it won't be
    // updated.
    void setMainWindow(cMainWindow* window);
    cMainWindow* getMainWindow();
    
    bool hasEvent();
    
    // Polls the event manager for a single event
    cEvent* PollEvent();
    
    // Get the current timestep.
    const TimeStep getTimestep();
    
    // Call to run the main loop.  Calling this surrenders control of
    // the main loop to the application object.
    void loop();
    
    // Call this at the beginning of your main loop.  This updates the
    // timestep and collects all new events in the event queue.
    void BeginUpdate();
    
    // Call this to process events.  It will delete the events as it goes.
    void ProcessEvents();
    
    // This method will be called to process each event.
    virtual void ProcessOneEvent(cEvent* evt);
    
    // This is the method provided for subclasses to do their own internal
    // updating.
    virtual void Update();

    // Updates the view, which is typically all graphics, used for animating
    // stuff that needs to be animated.
    void UpdateView();
    
    // Call at the end of the main loop to finish all pending updates.
    void EndUpdate();
    
    // Call this to simply update everything at once.
    void UpdateAll();
    
    bool keepRunning;
    
    cMainWindow* mainwindow = NULL;

protected:
    void ProcessOneEventI(cEvent* evt);
    
private:
    cEventManager* eventManager;
    
    TimeStep currentTimestep;

    // The first timestep ever in the app
    unsigned int firstTimestep;
    // The most recent timestep called
    unsigned int lastTimestep;
};

#endif // APPLICATION__H


