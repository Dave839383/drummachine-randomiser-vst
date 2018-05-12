/*
  ==============================================================================

    Randomiser.cpp
    Created: 12 May 2018 5:53:33pm
    Author:  David Lloyd

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Randomiser.h"

//==============================================================================
Randomiser::Randomiser()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

Randomiser::~Randomiser()
{
}

void Randomiser::paint (Graphics& g)
{
    g.setColour(Colours::grey);
    g.drawRoundedRectangle(5, 5, getWidth() - 10, getHeight() - 10, 5, 2);
}

void Randomiser::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
}
