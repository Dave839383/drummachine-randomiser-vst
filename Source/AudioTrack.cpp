/*
  ==============================================================================

    AudioTrack.cpp
    Created: 3 May 2018 3:24:10pm
    Author:  David Lloyd

  ==============================================================================
*/

#include "AudioTrack.h"

void AudioTrackLookAndFeel::drawButtonText (Graphics& g, TextButton& button, bool isMouseOverButton, bool isButtonDown)
{
    Font font("Courier New", 8, Font::plain);
    g.setFont (font);
    g.setColour (button.findColour (button.getToggleState() ? TextButton::textColourOnId
                                    : TextButton::textColourOffId)
                 .withMultipliedAlpha (button.isEnabled() ? 1.0f : 0.5f));
    const int yIndent = jmin (4, button.proportionOfHeight (0.3f));
    const int cornerSize = jmin (button.getHeight(), button.getWidth()) / 2;
    
    const int fontHeight = roundToInt (font.getHeight() * 0.6f);
    const int leftIndent  = jmin (fontHeight, 2 + cornerSize / (button.isConnectedOnLeft() ? 4 : 2));
    const int rightIndent = jmin (fontHeight, 2 + cornerSize / (button.isConnectedOnRight() ? 4 : 2));
    const int textWidth = button.getWidth() - leftIndent - rightIndent;
    
    if (textWidth > 0)
        g.drawFittedText (button.getButtonText(),
                          leftIndent, yIndent, textWidth, button.getHeight() - yIndent * 2,
                          Justification::centred, 2);
}

AudioTrack::AudioTrack()
{
    addAndMakeVisible (openButton);
    openButton.setButtonText ("Open");
    openButton.onClick = [this] { openButtonClicked(); };
    
    addAndMakeVisible (playButton);
    playButton.setButtonText ("Play");
    //playButton.onClick = [this] { ButtonClicked(); };
    
    setLookAndFeel (&audioTrackLookAndFeel);
}

AudioTrack::~AudioTrack()
{
    setLookAndFeel (nullptr);
}

void AudioTrack::paint (Graphics& g)
{
    Rectangle<float> audioName(10, 10, getWidth() - 20, 20);
    g.setColour(Colours::grey);
    g.drawRoundedRectangle(5, 5, getWidth() - 10, getHeight() - 10, 5, 2);
    g.drawRoundedRectangle(audioName, 5, 2);
    Font f("Courier New", 12, Font::plain);
    g.setFont(f);
    g.drawText("none", audioName, Justification::centred);
}

void AudioTrack::resized()
{
    Rectangle<float> audioName(10, 10, getWidth() - 20, 20);
    int audioNameBottom = audioName.getBottom();
    int audioNameX = audioName.getX();
    int width = audioName.getWidth();
    int border = 4;
    
    openButton.setBounds(audioNameX, audioNameBottom + border, width / 2 - (border / 2), 15);
    playButton.setBounds(audioNameX + width / 2 + (border / 2), audioNameBottom + border, width / 2 - (border / 2), 15);
}

void AudioTrack::releaseResources()
{
    
}

void AudioTrack::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    
}

void AudioTrack::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{
    
}

void AudioTrack::openButtonClicked()
{
    /*
    FileChooser chooser ("Select a Wave file shorter than 2 seconds to play...",
                         File::nonexistent,
                         "*.wav");
    
    if (chooser.browseForFileToOpen())
    {
        auto file = chooser.getResult();
        auto path = file.getFullPathName();
        chosenPath.swapWith (path);
        notify();
    }
     */
}

