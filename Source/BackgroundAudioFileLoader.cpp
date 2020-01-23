#include "BackgroundAudioFileLoader.hpp"
#include "Load.hpp"

using namespace std;

BackgroundAudioFileLoader::BackgroundAudioFileLoader()
{
    startTimerHz(1); // low priority checking.
}

void BackgroundAudioFileLoader::loadFile(const string& fileAddress)
{
    if (!m_fileQueue.try_enqueue(fileAddress))
    {
        // do something if fails.
    }
}
void BackgroundAudioFileLoader::timerCallback()
{
    string fileAddress;
    if(m_fileQueue.try_dequeue(fileAddress))
    {
        auto buffer = make_shared<Buffer>();
        Load::audio(fileAddress, buffer);
        m_audioQueue.enqueue(buffer);
    }
}
