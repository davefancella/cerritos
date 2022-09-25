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

#ifndef LAYOUT__H
#define LAYOUT__H

#include "point.h"
#include "object.h"
#include "types.h"

namespace cerritos {
    
class cWidget;
class Object;
class cLayout;

/// The different types of layout slots.
typedef enum {
    WidgetSlot, LayoutSlot, StretchSlot
} LayoutSlotType;

/**
 * A slot in the layout that holds the actual widget.
 * 
 * @ingroup widgetgroup
 */
class cLayoutSlot : public Object {
public:
    cLayoutSlot(cLayout* parent, LayoutSlotType lType) { };
    
    cWidget* widget() { return m_Widget; };
    void setWidget(cWidget* theWidget);
    
    cLayout* layout() { return m_Layout; };
    void setLayout(cLayout* theLayout);
    
    /// Returns a new LayoutSlot of the requested type.
    static cLayoutSlot* newWidgetSlot(cLayout* parent, cWidget* theWidget);
    /// Returns a new LayoutSlot of the requested type.
    static cLayoutSlot* newLayoutSlot(cLayout* parent, cLayout* theLayout);
    /// Returns a new LayoutSlot of the requested type.
    static cLayoutSlot* newStretchSlot(cLayout* parent);

private:
    cWidget* m_Widget;
    cLayout* m_Layout;
    
    LayoutSlotType m_Type;
};

/** 
 * The base class for all layouts.
 * 
 * @ingroup widgetgroup
 */
class cLayout : public Object {
public:
    cLayout(Object* parent=NULL);
    
    /// Adds a widget to this layout.
    void addWidget(cWidget* widget);
    /// Adds a layout to this layout.
    void addLayout(cLayout* layout);
    
    /// The minimum size for this layout
    cSizeInt minSize;
    /// The current size for this layout
    cSizeInt size;
private:
    List<cLayoutSlot*> m_Slots;
};

} // namespace cerritos

#endif // LAYOUT__H


