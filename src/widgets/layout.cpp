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

#include "layout.h"
#include "widget.h"
#include "object.h"

using namespace cerritos;

/******************************************
 * LayoutSlot
 *****************************************/

cLayoutSlot* cLayoutSlot::newWidgetSlot(cLayout* parent, cWidget* theWidget) {
    cLayoutSlot* newLayoutSlot = new cLayoutSlot(parent, WidgetSlot);
    
    newLayoutSlot->setWidget(theWidget);
    theWidget->reparent(parent->parent() );
    
    return newLayoutSlot;
}

cLayoutSlot* cLayoutSlot::newLayoutSlot(cLayout* parent, cLayout* theLayout) {
    cLayoutSlot* newLayoutSlot = new cLayoutSlot(parent, LayoutSlot);
    
    newLayoutSlot->setLayout(theLayout);
    theLayout->reparent(parent);
    
    return newLayoutSlot;
}

cLayoutSlot* cLayoutSlot::newStretchSlot(cLayout* parent) {
    cLayoutSlot* newLayoutSlot = new cLayoutSlot(parent, StretchSlot);

    return newLayoutSlot;
}

void cLayoutSlot::setWidget(cWidget* theWidget) {
    m_Widget = theWidget;
    m_Type = WidgetSlot;
}

void cLayoutSlot::setLayout(cLayout* theLayout) {
    m_Layout = theLayout;
    m_Type = LayoutSlot;
}



/******************************************
 * cLayout
 *****************************************/

cLayout::cLayout(Object* parent) : Object(parent) { }

void cLayout::addWidget(cWidget* widget) {
    addChild(dynamic_cast<Object*>(widget) );
}

void cLayout::addLayout(cLayout* layout) {
    addChild(dynamic_cast<Object*>(layout) );    
}


