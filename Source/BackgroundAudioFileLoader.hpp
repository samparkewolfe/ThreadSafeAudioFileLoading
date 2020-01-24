#pragma once

#include <string>

#include "../JuceLibraryCode/JuceHeader.h"
#include "Buffer.hpp"
#include "queue/readerwriterqueue.h"

using namespace moodycamel;
using namespace std;

class BackgroundAudioFileLoader : public Thread
{
public:
    BackgroundAudioFileLoader();
    ~BackgroundAudioFileLoader();
    
    void run() override;
    
    bool isFileReady();
    
    shared_ptr<Buffer> getLoadedAudioFile();
    
    void loadFile(const string& fileAddress);
    
private:
    BlockingReaderWriterQueue<string> m_incoming;
    ReaderWriterQueue<shared_ptr<Buffer>> m_outgoing;
    shared_ptr<Buffer> m_newBuffer;
    
    atomic<bool> m_stopThread;
};
