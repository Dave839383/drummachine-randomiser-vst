/*
  ==============================================================================

    PatternSequencer.cpp
    Created: 3 May 2018 3:24:30pm
    Author:  David Lloyd

  ==============================================================================
*/

#include "PatternSequencer.h"
#include "AudioSection.h"

void PatternSequencerLookAndFeel::drawButtonText (Graphics& g, TextButton& button, bool isMouseOverButton, bool isButtonDown)
{
    Font font("Courier New", 7, Font::plain);
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

PatternSequencer::PatternSequencer(AudioSection& a) : audioSection(a)
{
    int buttonCount = 1;
    char bank = 'A';
    Font patternButtonLabelFont("Courier New", 8, Font::plain);
    
    for (int i = 0; i < 8; i++)
    {
        TextButton * t = new TextButton();
        t->setColour(TextButton::buttonOnColourId, Colours::yellow);
        t->setName("patternBankButton");
        t->setButtonText(String(&bank));
        addAndMakeVisible (t);
        t->setColour(TextButton::buttonOnColourId, Colours::grey);
        t->setColour(TextButton::textColourOnId, getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
        t->addListener (this);
        patternBankButtons.add(t);
        bank++;
    }
    
    for (int i = 0; i < 16; i++)
    {
        // a button in the pattern sequencer
        TextButton * t = new TextButton();
        // a label for a button in the pattern sequencer.
        Label * l = new Label();
        
        t->setColour(TextButton::buttonOnColourId, Colours::yellow);
        t->setName("patternButton");
        addAndMakeVisible (t);
        t->setColour(TextButton::buttonOnColourId, Colours::grey);
        t->addListener (this);
        patternButtons.add(t);
        
        addAndMakeVisible (l);
        l->setText (String(buttonCount), dontSendNotification);
        l->setColour (Label::textColourId, Colours::grey);
        l->setJustificationType (Justification::left);
        l->setFont(patternButtonLabelFont);
        patternButtonLabels.add(l);
        buttonCount++;
    }
    setLookAndFeel (&patternSequencerLookAndFeel);
}

void PatternSequencer::paint (Graphics& g)
{
    g.setColour(Colours::grey);
    g.drawRoundedRectangle(5, 5, getWidth() - 10, getHeight() - 10, 5, 2);
}

void PatternSequencer::resized()
{
    int buttonDimensions = 16;
    int sequencerAreaX = getWidth() / 4;
    int sequencerAreaTop = getHeight() / 2;
    Rectangle<int> sequencerArea(sequencerAreaX, sequencerAreaTop, 16 * buttonDimensions, buttonDimensions);
    int buttonX = 0;
    
    // set up the 16 pattern Sequencer buttons
    for (int i = 0; i < patternButtons.size(); i++)
    {
        patternButtons[i]->setBounds(sequencerAreaX + buttonX, sequencerAreaTop, buttonDimensions, buttonDimensions);
        
        patternButtonLabels[i]->setBounds(sequencerAreaX + buttonX, sequencerAreaTop + buttonDimensions, buttonDimensions, buttonDimensions);
        buttonX += buttonDimensions;
    }
    
    int bankSectionArea = getWidth() / 4;
    int bankButtonDimensions = 16;
    int bankSectionTop = getHeight() / 2 - (buttonDimensions / 2);
    int bankSectionLeft = (bankSectionArea / 2) - (2 * bankButtonDimensions) + 5;
    buttonX = 0;
    
    // set up the 8 pattern bank buttons
    for (int i = 0; i < patternButtons.size() / 2; i++)
    {
        patternBankButtons[i]->setBounds(bankSectionLeft + buttonX, bankSectionTop, bankButtonDimensions, bankButtonDimensions);

        buttonX += bankButtonDimensions;
    }
    buttonX = 0;
    for (int i = 4; i < 8; i++)
    {
        patternBankButtons[i]->setBounds(bankSectionLeft + buttonX, bankSectionTop + bankButtonDimensions, bankButtonDimensions, bankButtonDimensions);
        
        buttonX += bankButtonDimensions;
    }
}

void PatternSequencer::buttonClicked(Button* button)
{
    if (button->getName() == "patternButton")
    {
        for (int i = 0; i < patternButtons.size(); i++)
        {
            if (button == patternButtons[i])
            {
                if (patternButtons[i]->getToggleState())
                {
                    patternButtons[i]->setToggleState(false, dontSendNotification);
                }
                else
                {
                    patternButtons[i]->setToggleState(true, dontSendNotification);
                }
                // audioSection.updateNoteInCurrentPattern(i, getToggleState);
                break;
            }
        }
    }
    else if (button->getName() == "patternBankButton")
    {
        for (int i = 0; i < patternBankButtons.size(); i++)
        {
            if (button == patternBankButtons[i])
            {
                if (patternBankButtons[i]->getToggleState())
                {
                    patternBankButtons[i]->setToggleState(false, dontSendNotification);
                }
                else
                {
                    patternBankButtons[i]->setToggleState(true, dontSendNotification);
                }
                
                // turn of any other bank button that's on.
                if (currentBankButton != i && patternBankButtons[currentBankButton]->getToggleState())
                {
                    patternBankButtons[currentBankButton]->setToggleState(false, dontSendNotification);
                }
                currentBankButton = i;
                break;
            }
        }
    }
}

PatternSequencer::~PatternSequencer()
{
    setLookAndFeel(nullptr);
}
