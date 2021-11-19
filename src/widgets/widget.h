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

class cWindow;
class cLayout;

namespace cerritos {

class cWidget : public cObject, 
                public cBaseEventReceiver {
public:
    cWidget(cWidget* parent=NULL) { 
        mParent = dynamic_cast<cObject*>(parent); 
    };

    virtual void process_event(cEvent* event);
    virtual void Render_To(cWindow* window) { };
    
protected:
    /// The top level layout for this widget.
    cLayout* mLayout;
// Following are event handlers for widgets.
public:
    // virtual void onNameofeventCamelCase(cNameofeventCamelCaseEvent* event);
};

} // namespace cerritos

#endif // WIDGET__H


