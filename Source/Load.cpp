#include "Load.hpp"

#include "../JuceLibraryCode/JuceHeader.h"

using namespace std;

namespace Load
{
    void audio(const string& fileAddress, shared_ptr<Buffer> bufferToFill)
    {
        AudioFormatManager formatManager;
        formatManager.registerBasicFormats();
        
        unique_ptr<AudioFormatReader> reader(formatManager.createReaderFor(File(fileAddress)));
        
        AudioSampleBuffer buffer;
        if (reader.get() != nullptr)
        {
            buffer.setSize(1, (int)reader->lengthInSamples);
            reader->read(&buffer, 0, (int)reader->lengthInSamples, 0, true, false);
        }
        
        bufferToFill->resize(reader->lengthInSamples);
        
        memcpy(bufferToFill->data(),
               buffer.getReadPointer(0),
               sizeof(float) * reader->lengthInSamples);
    }
}
