/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AlexDelayAudioProcessorEditor::AlexDelayAudioProcessorEditor (AlexDelayAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);

    auto& params = processor.getParameters();                                                   //Get Parameters from the processor

    //DRYWET SLIDER SETUP
    AudioParameterFloat* dryWetParameter = (AudioParameterFloat*)params.getUnchecked(0);        //Import specifically the dryWet Parameter (Zero'th Index, 0)

    mDryWetSlider.setBounds(0, 0, 100, 100);                                                    //Set Bounds of the DRYWET Slider
    mDryWetSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);                      //Set the style of Slider for DRYWET
    mDryWetSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);         //Set Textbox to NONE
    mDryWetSlider.setRange(dryWetParameter->range.start, dryWetParameter->range.end);           //Set the range of DRYWET to the start/end
    mDryWetSlider.setValue(*dryWetParameter);                                                   //Set the starting value of DRYWET
    addAndMakeVisible(mDryWetSlider);                                                           //Make DRYWET slider visible

    mDryWetSlider.onDragStart = [dryWetParameter] { dryWetParameter->beginChangeGesture(); };
    mDryWetSlider.onValueChange = [this, dryWetParameter] { *dryWetParameter = mDryWetSlider.getValue(); };
    mDryWetSlider.onDragEnd = [dryWetParameter] { dryWetParameter->endChangeGesture(); };

    //FEEDBACK SLIDER SETUP
    AudioParameterFloat* feedBackParameter = (AudioParameterFloat*)params.getUnchecked(1);        //Import specifically the FEEDBACK Parameter (First Index, 1)

    mFeedbackSlider.setBounds(100, 0, 100, 100);                                                    //Set Bounds of the FEEDBACK Slider
    mFeedbackSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);                      //Set the style of Slider for FEEDBACK
    mFeedbackSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);         //Set Textbox to NONE
    mFeedbackSlider.setRange(feedBackParameter->range.start, feedBackParameter->range.end);           //Set the range of FEEDBACK to the start/end
    mFeedbackSlider.setValue(*feedBackParameter);                                                   //Set the starting value of FEEDBACK
    addAndMakeVisible(mFeedbackSlider);                                                           //Make FEEDBACK slider visible

    mFeedbackSlider.onDragStart = [feedBackParameter] { feedBackParameter->beginChangeGesture(); };
    mFeedbackSlider.onValueChange = [this, feedBackParameter] { *feedBackParameter = mFeedbackSlider.getValue(); };
    mFeedbackSlider.onDragEnd = [feedBackParameter] { feedBackParameter->endChangeGesture(); };

    //DELAYTIME SLIDER SETUP
    AudioParameterFloat* delayTimeParameter = (AudioParameterFloat*)params.getUnchecked(2);        //Import specifically the DELAYTIME Parameter (First Index, 1)

    mDelayTimeSlider.setBounds(200, 0, 100, 100);                                                    //Set Bounds of the DELAYTIME Slider
    mDelayTimeSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);                      //Set the style of Slider for DELAYTIME
    mDelayTimeSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);         //Set Textbox to NONE
    mDelayTimeSlider.setRange(delayTimeParameter->range.start, delayTimeParameter->range.end);           //Set the range of DELAYTIME to the start/end
    mDelayTimeSlider.setValue(*delayTimeParameter);                                                   //Set the starting value of DELAYTIME
    addAndMakeVisible(mDelayTimeSlider);                                                           //Make DELAYTIME slider visible

    mDelayTimeSlider.onDragStart = [delayTimeParameter] { delayTimeParameter->beginChangeGesture(); };
    mDelayTimeSlider.onValueChange = [this, delayTimeParameter] { *delayTimeParameter = mDelayTimeSlider.getValue(); };
    mDelayTimeSlider.onDragEnd = [delayTimeParameter] { delayTimeParameter->endChangeGesture(); };

}

AlexDelayAudioProcessorEditor::~AlexDelayAudioProcessorEditor()
{
}

//==============================================================================
void AlexDelayAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void AlexDelayAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
