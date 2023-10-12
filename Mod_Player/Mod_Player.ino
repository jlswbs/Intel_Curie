// Amiga Mod player //

#include "CurieTimerOne.h"
#include "hxcmod.h"
#include "fairlight_quake.h"

#define AUDIO 5
#define SAMPLERATE 44100

volatile  uint16_t buff[1] ;

modcontext mcontext;
void* tune=(void*) &song;

int time;
const int oneSecInUsec = 1000000; // A second in micro second unit.


void setup(){

  pinMode(AUDIO, OUTPUT);
  analogWriteResolution(16); // set resolution 16bit
  analogWriteFrequency(AUDIO, SAMPLERATE);
  
  time = oneSecInUsec / SAMPLERATE;
  CurieTimerOne.start(time, &player); // set timer and callback

  hxcmod_init(&mcontext);
  hxcmod_setcfg(&mcontext, SAMPLERATE/2, 0, 0);
  hxcmod_load(&mcontext,tune, sizeof(song));
  
}

void loop() {

}

void player(){

  hxcmod_fillbuffer(&mcontext,(msample*) &buff, 1, 0);
  
  analogWrite(AUDIO, buff[0]);

  CurieTimerOne.restart(time);
  
}
