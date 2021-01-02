/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include <memory>
using namespace juce;
#define MAX_DELAY_TIME 2

//==============================================================================
/**
*/
class AlexDelayAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    AlexDelayAudioProcessor();
    ~AlexDelayAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    float lin_interp(float sample_x, float sample_x1, float inPhase);

private:

    int readHead_x;
    int readHead_x1;
    float readHeadFloat;

    //DEFINE OUR floating point POINTERS
    float* mCircularBufferRight;
    float* mCircularBufferLeft;

    //DEFINE THE LAST SPOT WE WROTE TO, or "WriteHead"
    int mCircularBufferWriteHead;

    //Define the length of our circular buffer.
    int mCircularBufferLength;

    //Define our Delay Time in samples
    AudioParameterFloat* mDelayTimeParameter;
    float mDelayTimeInSamples;

    //Define our Smoothing Delay Time Variable
    float mDelayTimeSmoothed;

    //Define our Delay Read Head
    float mDelayReadHead;

    //Define our feedback variables
    AudioParameterFloat* mFeedbackParameter;
    float mFeedbackLeft;
    float mFeedbackRight;

    //Define my DryWet variable
    AudioParameterFloat* mDryWetParameter;
    float mDryWet;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AlexDelayAudioProcessor)
};
