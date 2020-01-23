#pragma once

#include <string>

#include "../JuceLibraryCode/JuceHeader.h"
#include "Buffer.hpp"
#include "queue/readerwriterqueue.h"

using namespace moodycamel;
using namespace std;

class BackgroundAudioFileLoader : public Timer
{
public:
    BackgroundAudioFileLoader();
    
    void timerCallback() override;
    
    bool isFileReady()
    {
        if (m_audioQueue.try_dequeue(m_newBuffer))
        {
            return true;
        }
        return false;
    }
    
    shared_ptr<Buffer> getLoadedAudioFile()
    {
        return m_newBuffer;
    }
    
    void loadFile(const std::string& fileAddress);
    
private:
    BlockingReaderWriterQueue<std::string> m_fileQueue;
    ReaderWriterQueue<shared_ptr<Buffer>> m_audioQueue;
    shared_ptr<Buffer> m_newBuffer;
};
