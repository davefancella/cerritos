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

namespace cerritos {
    
/** 
 * @class Application
 * 
 * The Application class is how your game interacts with the operating
 * system, hence why it's called an application rather than a game.
 * Cerritos distinguishes between three main objects, the application,
 * the main window, and the game itself.  The application contains the
 * main window, and the main window contains the game and the gui.  The
 * game renders to a game screen in the main window, and the gui then
 * renders on top of that.
 * 
 * This is the application portion of all of that.  It handles commandline
 * process, configuration loading, file access, networking, etc.
 * Polling for input is also done in Application.
 * 
 * There are several ways for you to use it.  The common, expected way 
 * is to use one of the #CERRITOSMAIN macros, passing it your subclass
 * of Application, where you will reimplement virtual functions that
 * are called at appropriate times.
 * 
 * Application contains the main application loop.
 */
class Application : public Object,
                     public cBaseEventReceiver {
public:
    Application(int argc, char* argv[]);
    
    /// Set the main window for the object.  If it's not set, it won't be
    /// updated.
    void setMainWindow(cMainWindow* window);
    cMainWindow* getMainWindow();
    
    bool hasEvent();
    
    /// Polls the event manager for a single event
    Event* PollEvent();
    
    /// Get the current timestep.
    const TimeStep getTimestep();
    
    /// Call to run the main loop.  Calling this surrenders control of
    /// the main loop to the application object.
    void loop();
    
    /// Call this at the beginning of your main loop.  This updates the
    /// timestep and collects all new events in the event queue.
    void BeginUpdate();
    
    /// Call this to process events.  It will delete the events as it goes.
    void ProcessEvents();
    
    /// This method will be called to process each event.
    virtual void ProcessOneEvent(Event* evt);
    
    /// This is the method provided for subclasses to do their own internal
    /// updating.
    virtual void Update();

    /// Updates the view, which is typically all graphics, used for animating
    /// stuff that needs to be animated.
    void UpdateView();
    
    /// Call at the end of the main loop to finish all pending updates.
    void EndUpdate();
    
    /// Call this to simply update everything at once.
    void UpdateAll();
    
    bool keepRunning;
    
    cMainWindow* mainwindow = NULL;

protected:
    void ProcessOneEventI(Event* evt);
    
private:
    EventManager* eventManager;
    
    TimeStep currentTimestep;

    /// The first timestep ever in the app
    unsigned int firstTimestep;
    /// The most recent timestep called
    unsigned int lastTimestep;
    
    // Disable default constructor
    Application();
};

} // namespace cerritos
#endif // APPLICATION__H


