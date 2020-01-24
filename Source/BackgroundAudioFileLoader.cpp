#include "BackgroundAudioFileLoader.hpp"
#include "Load.hpp"

using namespace std;

BackgroundAudioFileLoader::BackgroundAudioFileLoader() :
Thread("Thread"),
m_stopThread(false)
{
    startThread(0); // lowest priority
}

BackgroundAudioFileLoader::~BackgroundAudioFileLoader()
{
    m_stopThread = true;
    sleep(1 * 1000); // 1 second
}

void BackgroundAudioFileLoader::loadFile(const string& fileAddress)
{
    m_incoming.enqueue(fileAddress);
}

void BackgroundAudioFileLoader::run()
{
    while (!m_stopThread.load())
    {
        string fileAddress;
        if (m_incoming.try_dequeue(fileAddress))
        {
            auto buffer = make_shared<Buffer>();
            Load::audio(fileAddress, buffer);
            m_outgoing.enqueue(buffer);
        }
        sleep(33); // might be a little fast.
    }
}

bool BackgroundAudioFileLoader::isFileReady()
{
    if (m_outgoing.try_dequeue(m_newBuffer))
    {
        return true;
    }
    return false;
}

shared_ptr<Buffer> BackgroundAudioFileLoader::getLoadedAudioFile()
{
    return m_newBuffer;
}
