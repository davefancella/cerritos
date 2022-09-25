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

#include "backend.h"

#include "application.h"
#include "imagemanager.h"
#include "window.h"
#include "mainwindow.h"
#include "surface.h"
#include "types.h"

using namespace cerritos;

void cMainWindow::onMouseOver(MouseMotionEvent* evt) {

}

void cMainWindow::setTitle(const char* title) {
    setTitle(String(title) );
}

void cMainWindow::setTitle(String title) {
    m_Title = title;
#ifdef USING_SDL
    SDL_SetWindowTitle(m_Window->getSDLWindow(), Title().data() );
#endif // USING_SDL
}

void cMainWindow::setPosition(int posx, int posy) {
    m_Position = PointInt(posx, posy);
    
    Move();
}

void cMainWindow::setSize(int width, int height) {
    m_Size = cSizeInt(width, height);
    
    Move();
}

void cMainWindow::Move() {
#ifdef USING_SDL
    SDL_SetWindowPosition(m_Window->getSDLWindow(), m_Position.x(), m_Position.y() );
    SDL_SetWindowSize(m_Window->getSDLWindow(), m_Size.width, m_Size.height);
#endif // USING_SDL
}

cMainWindow::cMainWindow(String title, int width, int height, int posx, int posy, CER_WindowFlags winFlags) 
            : cWidget(NULL), m_Title(title), m_Size(width, height), 
                m_Position(posx, posy),
                m_WindowFlags(winFlags) {    
    m_Window = new Window( m_Title, 
            m_Position.x(), m_Position.y(),
            m_Size.width, m_Size.height, m_WindowFlags );
    _IMG.setWindow(m_Window);
    
    m_guiMode = appGUI;
}

cMainWindow::~cMainWindow() {
    delete m_Window;
}

String cMainWindow::Title() {
    return m_Title;
}

/// Size of window
cSizeInt cMainWindow::size() {
    return m_Size;
}

/// Window position
PointInt cMainWindow::position() {
    return m_Position;
}

/// Window flags
CER_WindowFlags cMainWindow::windowFlags() {
    return m_WindowFlags;
}

void cMainWindow::Update() {
    if(m_allGUIs.has_key(m_guiMode) )
        m_allGUIs[m_guiMode]->setSize(m_Window->getRenderArea() );
}

GUIMode cMainWindow::getGuiMode() {
    return m_guiMode;
}

void cMainWindow::setGuiMode(GUIMode newMode) {
    m_guiMode = newMode;
}

void cMainWindow::setGui(GUIMode newMode, cWidget* topWidget) {
    if(m_allGUIs.has_key(newMode) ) {
        // delete the existing gui and just toss it away
    }
    
    m_allGUIs[newMode] = topWidget;
}

/**
 * This method is intended to render the game screen.  It's likely
 * just a placeholder for now.
 */
void cMainWindow::Render(const Timestep timestep) {
    m_Application->UpdateView();
}

/**
 * This method will render the main window.  It will call the virtual
 * Render() method at the appropriate time for any subclass rendering
 * that needs to happen.
 */
void cMainWindow::renderAll(const Timestep timestep) {
    this->beginRender();
    this->Render(timestep);
    this->guiRender();
    this->finishRender();
}

void cMainWindow::beginRender() {
#ifdef USING_SDL
    SDL_RenderClear(m_Window->getSDLRenderer() );
#endif
}

void cMainWindow::guiRender() {
    if(m_allGUIs.has_key(m_guiMode) )
        m_allGUIs[m_guiMode]->Render_To(m_Window);
}

void cMainWindow::finishRender() {
#ifdef USING_SDL
    SDL_RenderPresent(m_Window->getSDLRenderer() );
#endif
}

Window* cMainWindow::getWindow() { 
    return m_Window; 
}

