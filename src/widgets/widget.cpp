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

#include "widget.h"
#include "layout.h"

using namespace cerritos;

cWidget::cWidget(cWidget* parent) {
    if(parent != NULL) {
        parent->addChild(dynamic_cast<cObject*>(this));
        m_Parent = dynamic_cast<cObject*>(parent);
    }
}

void cWidget::setLayout(cLayout* theLayout) { 
    m_Layout = theLayout; 
    m_Layout->reparent(this);
}

void cWidget::process_event(cEvent* event) {
    for (auto i = m_Children.begin(); i != m_Children.end(); ++i) {
        static_cast<cWidget*>(*i)->process_event(event);
    }
    if(event->isActive() ) {
        cBaseEventReceiver::process_event(event);
    }
}

/***********************************************************
 * Event Handlers
 * *********************************************************/

// Mouse events
//void cWidget::onMouseOver(cMouseMotionEvent* event) { }
//void cWidget::onMouseButtonDown(cMouseButtondownEvent* event) { }
//void cWidget::onMouseButtonUp(cMouseButtonupEvent* event) { }

// Keyboard events
//void cWidget::onKeydown(cKeydownEvent* event) { }
//void cWidget::onKeyup(cKeyupEvent* event) { }

