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
    
    void setSelectedTrack(const int& track);
    
    void updateNoteInCurrentPattern(const int& noteNumber, bool noteIsOn);
private:
    void mouseDown (const MouseEvent &event) override;
    
    int selectedTrack; // represents the currently selected track in the audioTracks array
    
    OwnedArray<AudioTrack> audioTracks;
    int expectedSamplesPerBlock;
    double newSampleRate;
};
