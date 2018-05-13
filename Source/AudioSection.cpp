/*
  ==============================================================================

    AudioSection.cpp
    Created: 3 May 2018 3:23:49pm
    Author:  David Lloyd

  ==============================================================================
*/

#include "AudioTrack.h"
#include "AudioSection.h"

AudioSection::AudioSection()
{
    for (int i = 0; i < 8; i++)
    {
        AudioTrack * a = new AudioTrack();
        a->addMouseListener(this, true);
        a->setComponentID(String(i));
        addAndMakeVisible (a);
        audioTracks.add(a);
    }
}

void AudioSection::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    newSampleRate = sampleRate;
    expectedSamplesPerBlock = samplesPerBlockExpected;
}

void AudioSection::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{
    bufferToFill.clearActiveBufferRegion();
    
    for (auto chan = 0; chan < bufferToFill.buffer->getNumChannels(); ++chan)
    {
        auto* channelData = bufferToFill.buffer->getWritePointer (chan, bufferToFill.startSample);
        
        for (auto i = 0; i < bufferToFill.numSamples ; ++i)
        {

        }
    }
}

void AudioSection::paint (Graphics& g)
{
    //g.setColour(Colours::grey);
    //g.drawRoundedRectangle(5, 5, getWidth() - 10, getHeight() - 10, 5, 2);
    //g.setColour(getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    //g.fillRoundedRectangle(0, 0, getWidth(), getHeight(), 5);
}

void AudioSection::resized()
{
    int border = 10;
    Rectangle<int> patternArea(border, border, getWidth() - (border * 2), getHeight() - (border * 2));
    float patternColumn = (float) patternArea.getWidth() / 8.0;
    
    for (int i = 0; i < 8; i++)
    {
        audioTracks[i]->setBounds(patternArea.removeFromLeft(patternColumn));
    }
}

void AudioSection::releaseResources()
{
    
}

void AudioSection::mouseDown (const MouseEvent &event)
{
    int trackID = event.originalComponent->getComponentID().getIntValue();
    setSelectedTrack(trackID);
    std::cout << trackID << std::endl;
}

void AudioSection::setSelectedTrack(const int& track)
{
    // unselect previously selected track
    audioTracks[selectedTrack]->setTrackIsSelected(false);
    // set new selected track
    selectedTrack = track;
    audioTracks[track]->setTrackIsSelected(true);
}

void AudioSection::updateNoteInCurrentPattern(const int& noteNumber, bool noteIsOn)
{
    audioTracks[selectedTrack]->updateNote(noteNumber, noteIsOn);
}


