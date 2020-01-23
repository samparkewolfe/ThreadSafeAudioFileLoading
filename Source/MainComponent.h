#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

#include "FilePlayer.hpp"

class MainComponent   :
public AudioAppComponent,
public Timer,
public FileDragAndDropTarget
{
public:
    MainComponent();
    ~MainComponent();

    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    void paint (Graphics& g) override;
    void resized() override;

    void timerCallback() override;
    
    bool isInterestedInFileDrag(const StringArray& files) override;
    void filesDropped(const StringArray& files, int x, int y) override;
    
private:

    FilePlayer m_filePlayer;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
