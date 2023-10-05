// Vult DSP float - fm sine wrap oscillator + reverb //

#include "CurieTimerOne.h"
#include "Fmwrap.h"

Fmwrap_process_type fmwrap;

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
  
  float cv;   // control voltage
  float rst;  // reset oscillator
  float wrap; // wrap distortion

void setup(){

  pinMode(AUDIO, OUTPUT);

  analogWriteResolution(16);
  analogWriteFrequency(AUDIO, SAMPLERATE);
  
  time = oneSecInUsec / SAMPLERATE;
  CurieTimerOne.start(time, &sample);

  Fmwrap_process_init(fmwrap);
 
}


void sample(){

  int16_t sample = 24576.0f * Fmwrap_process(fmwrap, cv, rst, wrap);

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

  cv = randomf(0.05f, 0.7f);
  wrap = randomf(0.1f, 0.9f);
  rst = 0.0;

  delay(120);
  
}
