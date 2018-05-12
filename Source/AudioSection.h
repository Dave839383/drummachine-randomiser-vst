/*
  ==============================================================================

    AudioSection.h
    Created: 3 May 2018 3:23:49pm
    Author:  David Lloyd

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "AudioTrack.h"

class AudioSection  : public AudioSource,
                      public Component
{
public:
    AudioSection();
    void releaseResources() override;
    
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    
    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override;
    
    void paint (Graphics& g) override;
    
    void resized() override;
private:
    OwnedArray<AudioTrack> audioTracks;
    int expectedSamplesPerBlock;
    double newSampleRate;
};
