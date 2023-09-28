// Vult DSP float - phase fuzz oscillator //

#include "CurieTimerOne.h"
#include "Phasefuzz.h"

Phasefuzz_process_type phasefuzz;

#define AUDIO 5
#define SAMPLERATE 44100

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

  Phasefuzz_process_init(phasefuzz);
 
}


void sample(){

  int16_t sample = 24576.0f * Phasefuzz_process(phasefuzz, cv , detune);

  analogWrite(AUDIO, 32768 + sample);
    
  CurieTimerOne.restart(time);
  
}


void loop(){

  cv = randomf(0.1f, 0.4f);
  detune = randomf(0.1f, 0.9f);

  delay(240);
  
}
