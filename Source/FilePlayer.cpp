#include "FilePlayer.hpp"

FilePlayer::FilePlayer():
m_buffer(nullptr),
m_playhead(0)
{
}

void FilePlayer::loadFile(const string& s)
{
    m_loader.loadFile(s);
}

void FilePlayer::playCurrentFile (float *buffer, int numSamples)
{
    if (m_loader.isFileReady())
    {
        m_buffer = m_loader.getLoadedAudioFile();
        m_playhead = 0;
    }
    
    if (m_buffer == nullptr)
    {
        return;
    }
    
    if (m_playhead + numSamples < m_buffer->size())
    {
        std::memcpy(buffer, m_buffer->data() + m_playhead, sizeof(float) * numSamples);
        
        m_playhead += numSamples;
    }
    else
    {
        m_playhead = 0;
    }
}
