/*
  ==============================================================================

    Randomiser.h
    Created: 12 May 2018 5:53:33pm
    Author:  David Lloyd

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class Randomiser    : public Component
{
public:
    Randomiser();
    ~Randomiser();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Randomiser)
};
