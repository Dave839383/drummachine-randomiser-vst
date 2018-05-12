/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "PatternSequencer.h"
#include "Randomiser.h"

//==============================================================================
RandomisingSamplerAudioProcessorEditor::RandomisingSamplerAudioProcessorEditor (RandomisingSamplerAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p), audioSection(p.getAudioSection())
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    addAndMakeVisible (audioSection);
    addAndMakeVisible (patternSequencer = new PatternSequencer());
    addAndMakeVisible(randomiser = new Randomiser());
    setSize (750, 500);
}

RandomisingSamplerAudioProcessorEditor::~RandomisingSamplerAudioProcessorEditor()
{
    
}

//==============================================================================
void RandomisingSamplerAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    g.setColour(Colours::grey);
    g.drawRoundedRectangle(5, 5, getWidth() - 10, getHeight() - 10, 5, 2);
    /*
    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
     */
}

void RandomisingSamplerAudioProcessorEditor::resized()
{
    int border = 0;
    int audioSectionHeight = 350;
    int patternSequencerHeight = 160;
    audioSection->setBounds (border, border, getWidth() - (border * 2), audioSectionHeight - (border * 2));
    
    randomiser->setBounds(10, getHeight() - patternSequencerHeight, (getWidth() - (10 * 2)) / 2, patternSequencerHeight - 10);
    
    patternSequencer->setBounds(getWidth() / 2, getHeight() - patternSequencerHeight, (getWidth() - (10 * 2)) / 2, patternSequencerHeight - 10);
}
