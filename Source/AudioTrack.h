/*
  ==============================================================================

    AudioTrack.h
    Created: 3 May 2018 3:24:10pm
    Author:  David Lloyd

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class AudioTrackLookAndFeel : public LookAndFeel_V4
{
    void drawButtonText (Graphics& g, TextButton& button, bool isMouseOverButton, bool isButtonDown) override;
};

class AudioTrack  : public AudioSource,
                    public ChangeBroadcaster,
                    public Component
{
public:
    AudioTrack();
    
    ~AudioTrack();
    
    void releaseResources() override;
    
    void paint (Graphics& g) override;
    void resized() override;
    
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    
    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override;
    
    void openButtonClicked();
private:
    AudioTrackLookAndFeel audioTrackLookAndFeel;
    TextButton openButton;
    TextButton playButton;
};
