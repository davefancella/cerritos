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

#ifndef SPRITE__H
#define SPRITE__H

// Includes and forward declarations go here
#include "rect.h"
#include "surface.h"
#include "window.h"
#include "types.h"
#include "object.h"
#include "point.h"


namespace cerritos {

/**
 * @class Sprite
 * 
 * This is the Sprite class used to render images to the screen
 * For now it uses a Rect to know how big it is and where to
 * blit it's Surface to the screen.
 * 
 */
    
class Sprite {
public:
    Sprite(Window* window, int x, int y, int w, int h, int fps);
    ~Sprite();
    
    ///Draw method: simply passes m_Rect to surface->Blit_To()
    void Draw();
    
    ///Update takes the timestep from the app and
    ///updates the animation frame according to
    ///the programmer set Frames Per Second.
    void Update(const Timestep timestep);
    
    void addSpriteMode(int mode, List<String> frames);
    
    void setDefaultMode(int mode);
    void setMode(int mode);
    
    void setPosition(int x, int y) { setPosition(PointInt(x, y) ); };
    void setPosition(PointInt newPosition) { m_Position = newPosition; };

private:
    int m_Fps;
    int m_CurrentFrame;
    
    /// Position of the sprite on the screen.
    PointInt m_Position;
    cSizeInt m_Size;
    /// The actual origin of the sprite, defaults to center of graphic.
    PointInt m_Origin;
    
    Surface* m_Surface;
    List<Surface*> m_Frames;
    
    cMap<int, List<Surface*>> m_Modes;
    int m_Mode;
    int m_DefaultMode;
    
    Window* m_Window;
};
    
} // namespace cerritos

#endif // SPRITE__H


