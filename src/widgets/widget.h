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

#ifndef WIDGET__H
#define WIDGET__H

#include "object.h"

#include "event.h"

#include "eventreceiver.h"
#include "hardwareeventreceiver.h"
#include "point.h"

namespace cerritos {

class Window;
class cLayout;

/**
 * Contains relevant information for how big a widget needs to be, wants to
 * be, and can go if there's space available.
 */
class SizePolicy {
    SizePolicy() { };
    SizePolicy(cSizeInt minimum, cSizeInt preferred, unsigned int xpol, unsigned int ypol) :
        minimumSize(minimum), preferredSize(preferred), horizontalPolicy(xpol), verticalPolicy(ypol) 
        { };
    
    cSizeInt minimumSize;
    cSizeInt preferredSize;
    unsigned int horizontalPolicy;
    unsigned int verticalPolicy;
};

/** 
 * The base class for all widgets in Cerritos.
 * 
 * Every non-game object that a player interacts with is a widget.
 * Additionally, the GUI is rendered on top of the game screen and starts
 * with a single top-level widget that contains everything underneath it.
 * You would use widgets to provide an in-game HUD, an in-game GUI, and
 * for the application gui when the player is not in-game.
 * 
 * @defgroup widgetgroup Widgets
 * @ingroup widgetgroup
 */
class cWidget : public Object, 
                public cBaseEventReceiver {
public:
    cWidget(cWidget* parent=NULL);
    
    /// Set the layout for this widget.  Each widget can have only
    /// one top-level layout.  This is it.  The layout will be reparented
    /// to this widget.
    void setLayout(cLayout* theLayout);
    
    void setSize(unsigned int width, unsigned int height) {
        setSize(cSizeInt(width, height) );
    }
    void setSize(cSizeInt newSize) {
        m_Size = newSize;
    };
    
    /// Processes an event.  Generally no need to reimplement it, but
    /// if you do, make sure you call the base implementation.
    virtual void process_event(Event* event);
    
    /// Renders the widget.  Base class implementation doesn't really
    /// do anything.  You'll need to reimplement in your subclasses if
    /// you want them to actually get drawn to the window.
    virtual void Render_To(Window* window) { };
    
protected:
    /// The top level layout for this widget.
    cLayout* m_Layout;
    
private:
    cSizeInt m_Size;
    
// Following are event handlers for widgets.
public:
    // virtual void onNameofeventCamelCase(cNameofeventCamelCaseEvent* event);
};

} // namespace cerritos

#endif // WIDGET__H


