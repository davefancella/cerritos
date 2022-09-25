#include "sound.h"
#include "types.h"

using namespace cerritos;

Sound::Sound(int numSources) {
    alutInit(NULL, NULL);
    
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
    alutExit();
}

void Sound::LoadSoundFromFile(const char *filename, int index) {
    m_Buffers[index] = alutCreateBufferFromFile(filename);
    alGenSources((ALuint)1, &m_Sources[index]);
    alSourcei(m_Sources[index], AL_BUFFER, m_Buffers[index]);
}

void Sound::PlaySound(int index) {
    alSourcePlay(m_Sources[index]);
}
