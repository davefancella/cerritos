#include "sound.h"
#include "types.h"

using namespace cerritos;

Sound::Sound(int numSources) {
#ifdef USING_OPENAL
    alutInit(NULL, NULL);
#endif

    for (int i = 0; i < numSources; i++) {
        ALuint buffer;
        m_Buffers.push_back(buffer);
    }
    
    for (int i = 0; i < numSources; i++) {
        ALuint source;
        m_Sources.push_back(source);
    }
}
Sound::~Sound() {
#ifdef USING_OPENAL
    alutExit();
#endif
}

void Sound::LoadSoundFromFile(const char *filename, int index) {
#ifdef USING_OPENAL
    m_Buffers[index] = alutCreateBufferFromFile(filename);
    alGenSources((ALuint)1, &m_Sources[index]);
    alSourcei(m_Sources[index], AL_BUFFER, m_Buffers[index]);
#endif
}

void Sound::PlaySound(int index) {
#ifdef USING_OPENAL
    alSourcePlay(m_Sources[index]);
#endif
}
