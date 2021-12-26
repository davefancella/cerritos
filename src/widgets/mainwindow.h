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

#include "widget.h"
#include "types.h"

namespace cerritos {

class cLayout;

class cMainWindow : public cerritos::cWidget {
public:
    /// The title of the window
    String Title;
    
    /// Size of window
    int width;
    int height;
    
    /// Window position
    int posx;
    int posy;
    
    /// Timestep
    int timeStepBeginning;
    int timeStepLast;
    
    /// Window flags
    CER_WindowFlags windowFlags;
    
    // Constructors
    //cMainWindow();
    cMainWindow(CER_WindowFlags winFlags=CER_Shown);
    cMainWindow(String title, CER_WindowFlags winFlags=CER_Shown);
    cMainWindow(String title, int width, int height, CER_WindowFlags winFlags=CER_Shown);
    cMainWindow(String title, int width, int height, int posx, int posy, CER_WindowFlags winFlags=CER_Shown);
    virtual ~cMainWindow();
    
    void setTitle(String title);
    void setPosition(int posx, int posy);
    void setSize(int width, int height);
    
    void Move();
    
    /// Call to update the window.  This is where all new sizes are
    /// calculated, but no rendering is done.
    virtual void Update(Timestep* timestep=NULL);
    
    /// Call to render the window.  No new calculations should be needed,
    /// but anything not involving drawing the window does not happen
    /// here.
    virtual void Render(Timestep* timestep=NULL);
    
    /// Called at the start of rendering.  Typically clears the window.
    void beginRender(Timestep* timestep=NULL);
    
    /// Called to finish any rendering tasks, manage double-buffering,
    /// etc.
    void finishRender(Timestep* timestep=NULL);
    
    /// Called to render the gui.  It's called before finishRender(),
    /// but after the game screen has been rendered.
    void guiRender(Timestep* timestep=NULL);
    
    /// Called internally to render the window.
    void renderAll(Timestep* timestep=NULL);

    void onMouseOver(MouseMotionEvent* evt);
    
    Window* getWindow();
private:
    /// The window we'll be rendering to
    Window* m_Window = NULL;
    cLayout* m_Layout = NULL;
};

} // namespace cerritos

#endif




