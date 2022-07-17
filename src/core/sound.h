#include <AL/alut.h>
#include "types.h"

namespace cerritos {

class Sound {
public:
    Sound(int numSources);
    ~Sound();
    void LoadSoundFromFile(const char *filename, int index);
    
    void PlaySound(int index);

    ALvoid getBuffer(int index);
        
private:
    List<ALuint> m_Sources;
    List<ALuint> m_Buffers;

};

}
