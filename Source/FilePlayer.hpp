#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "BackgroundAudioFileLoader.hpp"
#include "Buffer.hpp"

using namespace std;

class FilePlayer
{
public:
    FilePlayer();
    
    void loadFile(const string& s);
    
    void playCurrentFile(float *buffer, int numSamples);
    
private:
    BackgroundAudioFileLoader m_loader;
    
    shared_ptr<Buffer> m_buffer;
    size_t m_playhead;
};
