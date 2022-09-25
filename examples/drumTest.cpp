#include "cerritos.h"

#include "application.h"
#include "mainwindow.h"

#include "event.h"

using namespace cerritos;

class dmApplication : public Application {
public:
    CONSTRUCTAPP(dmApplication);
    
    Sound* m_Mixer = NULL;
    
    void init() {
        setMainWindow( new cMainWindow );
        
        m_Mixer = new Sound(2);
        
        const char *kick = "/home/pi/cerritos/assets/music/Kick-Drum-1.wav";
        const char *snare = "/home/pi/cerritos/assets/music/Snare-Drum-1.wav";
    
        m_Mixer->LoadSoundFromFile(kick, 0);
        m_Mixer->LoadSoundFromFile(snare, 1);
        
    }
    
    void onKeydown(KeydownEvent* evt) {
        switch (evt->mKey) {
            case K_LEFT:
                m_Mixer->PlaySound(0);
                break;
            case K_RIGHT:
                m_Mixer->PlaySound(1);
                break;
        }
    }
};

CERRITOSMAIN(dmApplication); 
    
