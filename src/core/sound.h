#include <AL/alut.h>
#include "types.h"

namespace cerritos {

/**
 * @class Sound
 * 
 * This is the Sound class, it is used to play sound on the default device initialized by OpenAL
 * For now all it can do is load files from your hard drive and play the sounds.
 * 
 */
    
class Sound {
public:
    ///Constructor
    ///Pass the number of sounds you want to be able to play,
    ///and it creates a list of buffers and sources to work with.
    ///Also initialized OpenAL device and context.
    Sound(int numSources);
    ~Sound();
    
    ///Loads a file to play into the given indix of the buffers list
    ///and sources list.
    void LoadSoundFromFile(const char *filename, int index);
    
    ///Plays file at given index
    void PlaySound(int index);

    ALvoid getBuffer(int index);
        
private:
    List<ALuint> m_Sources;
    List<ALuint> m_Buffers;

};

}
