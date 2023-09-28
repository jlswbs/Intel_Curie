// Vult DSP float - phase distortion oscillator + reverb //

#include "CurieTimerOne.h"
#include "Phasedist.h"

Phasedist_process_type phasedist;

#define AUDIO 5
#define SAMPLERATE 44100

const int FIXED_BITS = 14;
const int FIXED_SCALE = (1 << FIXED_BITS);
const int REVERB_SIZE = 0x500;
const int REVERB_LENGTH = (int)(REVERB_SIZE * 0.9f);
const int REVERB_DECAY = (int)(FIXED_SCALE * 0.7f);

int16_t reverbAddr;
int reverbBuffer[REVERB_SIZE];

float randomf(float minf, float maxf) {return minf + random(1UL << 31)*(maxf - minf) / (1UL << 31);} 

  int time;
  const int oneSecInUsec = 1000000;
  
  float cv;      // control voltage
  float detune;  // detune

void setup(){

  pinMode(AUDIO, OUTPUT);

  analogWriteResolution(16);
  analogWriteFrequency(AUDIO, SAMPLERATE);
  
  time = oneSecInUsec / SAMPLERATE;
  CurieTimerOne.start(time, &sample);

  Phasedist_process_init(phasedist);
 
}


void sample(){

  int16_t sample = 24576.0f * Phasedist_process(phasedist, cv , detune);

  int reverb = ((int)reverbBuffer[reverbAddr] * REVERB_DECAY) >> FIXED_BITS;
  reverb += sample;
  reverbBuffer[reverbAddr] = reverb;
  reverbAddr++;
  if (reverbAddr > REVERB_LENGTH) reverbAddr = 0;
  int16_t output = sample + (reverbBuffer[reverbAddr]>>3);

  analogWrite(AUDIO, 32768 + output);
    
  CurieTimerOne.restart(time);
  
}


void loop(){

  cv = randomf(0.1f, 0.4f);
  detune = randomf(0.1f, 0.9f);

  delay(240);
  
}
