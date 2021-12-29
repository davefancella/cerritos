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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "backend.h"

#include "point.h"
#include "widget.h"
#include "types.h"

namespace cerritos {

class cLayout;

/**
 * The main window for the application.  It contains the game
 * screen and GUI.
 * 
 * @ingroup widgetgroup
 */
class cMainWindow : public cerritos::cWidget {
public:
    /// The title of the window
    String Title();
    
    /// Size of window
    cSizeInt size();
    
    /// Window position
    PointInt position();
    
    /// Window flags
    CER_WindowFlags windowFlags();
    
    // Constructors
    //cMainWindow();
    cMainWindow(CER_WindowFlags winFlags=CER_Shown) :
            cMainWindow("Cerritos Window", 800, 600, CER_WindowPos_Centered, CER_WindowPos_Centered, winFlags) { };
    cMainWindow(String title, CER_WindowFlags winFlags=CER_Shown) :
            cMainWindow(title, 800, 600, CER_WindowPos_Centered, CER_WindowPos_Centered, winFlags) { };
    cMainWindow(String title, int width, int height, CER_WindowFlags winFlags=CER_Shown) :
            cMainWindow(title, 800, 600, CER_WindowPos_Centered, CER_WindowPos_Centered, winFlags) { };
    cMainWindow(String title, int width, int height, int posx, int posy, CER_WindowFlags winFlags=CER_Shown);
    virtual ~cMainWindow();
    
    void setTitle(const char* title);
    void setTitle(String title);
    void setPosition(int posx, int posy);
    void setSize(int width, int height);
    
    void Move();
    
    /// Call to update the window.  This is where all new sizes are
    /// calculated, but no rendering is done.
    virtual void Update(const Timestep timestep);
    
    /// Call to render the window.  No new calculations should be needed,
    /// but anything not involving drawing the window does not happen
    /// here.
    virtual void Render(const Timestep timestep);
    
    /// Called at the start of rendering.  Typically clears the window.
    void beginRender();
    
    /// Called to finish any rendering tasks, manage double-buffering,
    /// etc.
    void finishRender();
    
    /// Called to render the gui.  It's called before finishRender(),
    /// but after the game screen has been rendered.
    void guiRender();
    
    /// Called internally to render the window.
    void renderAll(const Timestep timestep);

    void onMouseOver(MouseMotionEvent* evt);
    
    Window* getWindow();
private:
    /// The title of the window
    String m_Title;
    
    /// Size of window
    cSizeInt m_Size;
    
    /// Window position
    PointInt m_Position;
    
    /// Window flags
    CER_WindowFlags m_WindowFlags;
    
    /// The window we'll be rendering to
    Window* m_Window = NULL;
    cLayout* m_Layout = NULL;
};

} // namespace cerritos

#endif




