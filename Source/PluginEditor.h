/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "PatternSequencer.h"
#include "Randomiser.h"
//==============================================================================
/**
*/
class RandomisingSamplerAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    RandomisingSamplerAudioProcessorEditor (RandomisingSamplerAudioProcessor&);
    ~RandomisingSamplerAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    RandomisingSamplerAudioProcessor& processor;
    AudioSection * audioSection;
    ScopedPointer<PatternSequencer> patternSequencer;
    ScopedPointer<Randomiser> randomiser;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RandomisingSamplerAudioProcessorEditor)
};
