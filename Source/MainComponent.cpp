#include "MainComponent.h"

MainComponent::MainComponent()
{

    setSize (800, 600);

    setAudioChannels (0, 2);
    
    setSize(500, 500);
    startTimerHz(30);
}

MainComponent::~MainComponent()
{
    shutdownAudio();
}

void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    
}

void MainComponent::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{
    bufferToFill.clearActiveBufferRegion();
    
    m_filePlayer.playCurrentFile(bufferToFill.buffer->getWritePointer(0), bufferToFill.numSamples);
}

void MainComponent::releaseResources()
{
    
}

void MainComponent::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    
    g.drawText("Drop a file", getLocalBounds(), Justification::centred);
}

void MainComponent::resized()
{
    
}

void MainComponent::timerCallback()
{
    repaint();
}

bool MainComponent::isInterestedInFileDrag(const StringArray& files)
{
    return true;
}

void MainComponent::filesDropped(const StringArray& files, int x, int y)
{
    ignoreUnused(x, y);
    
    for(auto fileAddress : files)
    {
        m_filePlayer.loadFile(fileAddress.toStdString());
    }
}
