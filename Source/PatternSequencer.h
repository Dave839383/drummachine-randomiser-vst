/*
  ==============================================================================

    PatternSequencer.h
    Created: 3 May 2018 3:24:30pm
    Author:  David Lloyd

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "AudioSection.h"

class PatternSequencerLookAndFeel : public LookAndFeel_V4
{
    void drawButtonText (Graphics& g, TextButton& button, bool isMouseOverButton, bool isButtonDown) override;
};


class PatternSequencer  : public Component,
                          public Button::Listener
{
public:
    PatternSequencer(AudioSection& a);
    
    ~PatternSequencer();
    
    void paint (Graphics& g) override;
    
    void resized() override;
    
    void buttonClicked (Button* button) override;

private:
    AudioSection& audioSection;
    PatternSequencerLookAndFeel patternSequencerLookAndFeel;
    OwnedArray<TextButton> patternButtons;
    OwnedArray<Label> patternButtonLabels;
    OwnedArray<TextButton> patternBankButtons;
    
    // used to keep track of the current Bank Button that is on.
    int currentBankButton;
};
