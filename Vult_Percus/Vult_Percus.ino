// Vult DSP float - percussion fold oscillator + reverb //

#include "CurieTimerOne.h"
#include "Percus.h"

Percus_process_type percus;

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
  
  float gate, decay, pitch, fold, noise;

void setup(){

  pinMode(AUDIO, OUTPUT);

  analogWriteResolution(16);
  analogWriteFrequency(AUDIO, SAMPLERATE);
  
  time = oneSecInUsec / SAMPLERATE;
  CurieTimerOne.start(time, &sample);

  Percus_process_init(percus);
 
}


void sample(){

  int16_t sample = 24576.0f * Percus_process(percus, gate, decay, pitch, fold, noise);

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

  decay = randomf(0.001f, 0.005f);
  pitch = randomf(0.01f, 0.5f);
  fold = randomf(0.1f, 1.0f);
  noise = randomf(0.1f, 1.0f);
  gate = 1.0f;

  delay(1);
  
  gate = 0.0f;
  
  delay(139);
  
}
