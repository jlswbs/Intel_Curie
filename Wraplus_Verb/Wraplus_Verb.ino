// Float karplus-strong + wrap filter + echoverb //

#include "CurieTimerOne.h"

#define AUDIO       5
#define SAMPLERATE  44100
#define BUFF_SIZE   2048
#define SIZE        128

float randomf(float minf, float maxf) {return minf + random(1UL << 31)*(maxf - minf) / (1UL << 31);}

  unsigned int buff_pos = 0;
  float buff[BUFF_SIZE];

  float r = 3.5699456f;
  float x = 0.1f;
  float b = 0.0f;
  float out = 0.0f;
  float last = 0.0f;
  float curr = 0.0f;
  float delaymem[SIZE];
  uint16_t locat = 0;
  uint16_t bound = SIZE;
  float accum = 0.0f;
  float lowpass = 0.0f;
  float lim = 0.0f;

  int time;
  const int oneSecInUsec = 1000000;

float echo_verb(float sample, float decay) {

  float old_sample = buff[buff_pos];
  float new_sample = (sample + (old_sample * decay)) / 2.0f;
  buff[buff_pos] = new_sample;
  buff_pos = buff_pos + 1;
  if (buff_pos == BUFF_SIZE) buff_pos = 0; 
  return new_sample;

}

float wrap(float x, float lim) {
  
  float out = x;
  while (out > lim || out < -lim) {
    if (out > lim) out = -lim + (out-lim);
    else if (out < -lim) out = lim - (-out-lim);
  }
  return out;

}

void setup(){

  pinMode(AUDIO, OUTPUT);

  analogWriteResolution(16);
  analogWriteFrequency(AUDIO, SAMPLERATE);
  
  time = oneSecInUsec / SAMPLERATE;
  CurieTimerOne.start(time, &sample);

}


void sample(){

  delaymem[locat++] = out;
  if (locat >= bound) locat = 0;
  curr = delaymem[locat];
  out = 0.5f * accum;
  accum = accum - (b * (accum - (last + curr))); 
  last = curr;

  int16_t sample = 32767.0f * echo_verb(wrap(out, lim), 1.5f);

  analogWrite(AUDIO, 32768 + sample);
    
  CurieTimerOne.restart(time);
  
}


void loop(){

  float nx = x;
  x = r * nx * (1.0f - nx);

  b = randomf(0.049f, x);
  lim = randomf(0.1f, x);

  for (int i = 0; i < SIZE; i++) delaymem[i] = randomf(-1.0f, 1.0f);
  bound = map(SIZE * x, 0, SIZE, 16, SIZE);

  int tempo = 60000 / random(30, 350);

  delay(tempo);
  
}
