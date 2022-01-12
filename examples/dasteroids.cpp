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

// Include the cerritos header file.  This brings in pretty much everything.
#include "cerritos.h"

using namespace cerritos;

class Ship : public Sprite {
public:
    Ship(Window* window, int x, int y, int w, int h, int fps) : Sprite(
                window, x, y, w, h, fps) {
        m_RotateDirection = 0;
        m_Speed = 0.0;
    };
    
    void setRotateLeft() { m_RotateDirection = -1; };
    void setRotateRight() { m_RotateDirection = 1; };
    void setRotateStop() { m_RotateDirection = 0; };
    int getRotationDirection() { return m_RotateDirection; };
    
    bool getMoving() { 
        if(m_Speed > 0 || m_Speed < 0) 
            return true; 
        return false; 
    };
    void setMoving() { m_Speed = 2; };
    void Stop() { m_Speed = 0; };
    
    double getSpeed() { return m_Speed; };
    
private:
    int m_RotateDirection;
    
    double m_Speed;
};

class ftApplication : public Application {
public:
    CONSTRUCTAPP(ftApplication);
    
    Ship* m_Ship;
    
    void init() {
        setMainWindow(new cMainWindow("Dad's Asteroid Game") );

        m_Ship = new Ship(getMainWindow()->getWindow(), 200,200, 40, 40, 1 );
        
        List<String> ship = {
            _PATH.getFilepath("share", "dadship.png") 
        };
        
        m_Ship->addSpriteMode(0, ship);
        m_Ship->setDefaultMode(0);
        m_Ship->setMode(0);
        
        m_Ship->setPosition(200,200);
    };
    
    void Update() {
        Timestep dt = _CLOCK.getTimestep();
        m_Ship->Update(dt);
        
        // Calculate rotation direction
        if(m_Ship->getRotationDirection() != 0) {
            m_Ship->setHeading(
                m_Ship->getHeading() +
                static_cast<float>(m_Ship->getRotationDirection() ) *
                dt.fromLastSeconds);
            m_Ship->normalizeHeading();
        }
        
        if(m_Ship->getMoving() == true) {
            PointInt pos = m_Ship->getPosition();
            double dcos = cos(m_Ship->getHeading() );
            double dsin = sin(m_Ship->getHeading() );
            int xm=0, ym=0;
            
            // QI
            if(dcos > 0.0 && dsin > 0.0) {
                xm = 1; ym = 1;
            }
            // QII
            if(dcos < 0.0 && dsin > 0.0) {
                xm = -1; ym = 1;
            } 
            // QIII
            if(dcos < 0.0 && dsin < 0.0) {
                xm = -1; ym = -1;
            }
            // QIV
            if(dcos > 0.0 && dsin < 0.0) {
                xm = 1; ym = -1;
            }
            
            double dx = static_cast<double>(pos.x() ) + 
                (static_cast<double>(xm) * (m_Ship->getSpeed() * abs(dcos) * dt.fromLast) );
            double dy = static_cast<double>(pos.y() ) + 
                static_cast<double>(ym) * ( (m_Ship->getSpeed() * abs(dsin) * dt.fromLast) );
            
            m_Ship->setPosition(static_cast<int>(dx), 
                                         static_cast<int>(dy) );
            cSTDOUT << dx << ", " << dy << EOL;
        }
    };
    
    void UpdateView() {
        m_Ship->Render();
    }
    
    virtual void onKeydown(KeydownEvent* event) {
        switch(event->mKey) {
            case K_LEFT:
                m_Ship->setRotateLeft();
                break;
            case K_RIGHT:
                m_Ship->setRotateRight();
                break;
            case K_UP:
                m_Ship->setMoving();
                break;
            case K_DOWN:
                break;
        }
    };

    virtual void onKeyup(KeyupEvent* event) {
        switch(event->mKey) {
            case K_LEFT:
                m_Ship->setRotateStop();
                break;
            case K_RIGHT:
                m_Ship->setRotateStop();
                break;
            case K_UP:
                m_Ship->Stop();
                break;
            case K_DOWN:
                
                break;
        }
    };
};

CERRITOSMAIN(ftApplication)


