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
#include "types.h"

/**
 * Application subclasses **must** use this macro to ensure the Application
 * object is constructed correctly.
 * 
 *      class MyApp : public Application {
 *      CONSTRUCTAPP(MyApp);
 *
 *      // The rest of your class declaration follows
 *      };
 *
 * Use this macro to setup all the appropriate methods and constructors.
 */
#define CONSTRUCTAPP(appClass) \
public:\
    appClass() : Application() { \
    };\


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
    /**
     * Constructor
     * Application subclasses **must** use the CONSTRUCTAPP macro to ensure 
     * the Application object is constructed correctly.
     * 
     *     class MyApp : public Application {
     *     CONSTRUCTAPP(MyApp);
     * 
     *     // The rest of your class declaration follows
     *     };
     *
     */
    Application();
    
    /** @name Setup
     * 
     * These methods are all used to set up the Application before the main
     * loop gets started.  No event processing or input is handled here.
     */
    ///@{
    /**
     * Called to initialize the Application.  The constructor is only used
     * to construct the object in memory, this method is used to initialize
     * the application.  It's where you'll load all your starting data like
     * fonts and images and stuff.
     */
    virtual void init() { };
        
    /// Set the main window for the object.  If it's not set, it won't be
    /// updated.
    void setMainWindow(cMainWindow* window);
    
    /// Creates a mainWindow.  Pass it a created MainWindow and it'll be
    /// used instead.
    void createMainWindow(CER_WindowFlags winFlags=CER_Shown);
    void createMainWindow(String title, CER_WindowFlags winFlags=CER_Shown);
    void createMainWindow(String title, int width, int height, CER_WindowFlags winFlags=CER_Shown);
    void createMainWindow(String title, int width, int height, int posx, int posy, CER_WindowFlags winFlags=CER_Shown);

    ///@}
    
    /** @name Informational Methods
     * 
     * These methods provide information only.  Each one only provides
     * useful information after it has been initialized by one of the
     * Setup methods.
     */
    ///@{
    
    /**
     * Call to see if Application already has a cMainWindow.
     * 
     * @returns true if there is one, false if not.
     */
    bool hasMainWindow() { 
        if(m_MainWindow != NULL)
            return true;
        
        return false;
    };
    
    /**
     * Gets the pointer to the MainWindow.  Returns NULL if there isn't
     * a MainWindow yet.  You should check with hasMainWindow() first.
     */
    cMainWindow* getMainWindow();

    ///@}
    
    /** @name Event Processing
     * 
     * Each of these methods is used for event processing during the main
     * loop.  Since that's the only place event processing happens, these
     * methods are only valid inside the main loop.
     */
    ///@{
    
    bool hasEvent();
    
    /*
     * Polls the event manager for a single event.  This will result
     * in the event being removed from the event queue, so if you call
     * this, you'll need to handle the event.
     * 
     * Also, as with SDL, if you don't use the event loop, you'll need
     * to call this anyway to keep the event queue from becoming a
     * memory leak in your game.
     */
    Event* PollEvent();
    
    /// Call this to process events.  It will delete the events as it goes.
    void ProcessEvents();
    
    /**
     * This method will be called to process each event.  It is called
     * before the event is dispatched to the rest of the game, including
     * the GUI, to allow developers to override event behavior, create
     * event filters, and so forth.  You can also use the event for your
     * own purposes and then let it move on to be processed by the rest
     * of the system.
     * 
     * Default implementation does nothing.
     */
    virtual void BeginProcessOneEvent(Event* evt) { };
    
    /**
     * This method will be called to process each event.  It is called
     * after the event is dispatched to the rest of the game, including
     * the GUI, after any event handlers have been called,
     * and only if the event is still active.
     * 
     * There's very little need to ever use this method, but it is provided
     * because just because we can't imagine needing it, doesn't mean the
     * need won't exist, and it'll typically be compiled out of the executable
     * when it's not needed.
     * 
     * Default implementation does nothing.
     */
    virtual void ProcessOneEvent(Event* evt) { };
protected:
    /**
     * Process one event internally.  This is where the events get delegated
     * for processing.
     */
    void ProcessOneEventI(Event* evt);
    
    ///@}
    
public:    
    /** @name Main Loop
     * 
     * These methods collectively constitute the main loop.  They are
     * designed to be easily overridden, and some have no default
     * implementation because they're only useful if overridden.
     * 
     * Event processing, while handled in the main loop, gets its own
     * subgroup.
     */
    ///@{
    
    void setGuiMode(GUIMode newMode) {
        getMainWindow()->setGuiMode(newMode);
        m_guiMode = newMode;
    };
    
    /**
     * Call to run the main loop.  Calling this surrenders control of
     * the main loop to the application object.  If you don't want to
     * let cerritos handle your main loop, then obviously you won't use
     * this method.  Also, you'll only ever call this directly in the
     * case where you handle all the initialization yourself, in which
     * case you'll need to call loop() to enter the main loop.
     * 
     * If you use any of the CERRITOSMAIN macros, this will be called
     * automatically.
     */
    void loop();
    
    /// Call this at the beginning of your main loop.  This updates the
    /// timestep and collects all new events in the event queue.
    void BeginUpdate();
    
    /**
     * This is the driving part of the main loop.  This is where you'll
     * put your own timestep for the main loop.  As the API is still under
     * heavy development, this method will likely split into smaller parts.
     *
     * Default implementation does nothing.
     */
    virtual void Update();

    /**
     * Updates the view, which is typically all graphics, used for animating
     * stuff that needs to be animated.  Sound is mixed and sent to sound
     * buffers, and all the goodness of the GUI gets rendered.
     * 
     * Absolutely no game simulation or user interaction happens in this
     * method.
     * 
     */
    virtual void UpdateView();
    
    /// Call at the end of the main loop to finish all pending updates.
    void EndUpdate();
    
    /**
     * Call this to simply update everything at once.  It will also
     * initialize anything that needs to be initialized before getting
     * started.  This is a way to keep some control of your main() function,
     * while surrendering some control to cerritos.
     * 
     * It's probably a case of YouMightNeedThis.
     */
    void UpdateAll();
    
    ///@}
    
    bool keepRunning;
    
    /**
     * This is the main function of the Application.  If you need to
     * overload it, you assume responsibility for all of the Application.
     * 
     * This method handles all of the initialization, gui switching,
     * everything.
     */
    virtual int main(int argc, char* argv[]);
    
protected:
    void onQuit(QuitEvent* event);
    
private:
    cMainWindow* m_MainWindow = NULL;

    EventManager* eventManager;
    
    GUIMode m_guiMode;
};

} // namespace cerritos
#endif // APPLICATION__H


