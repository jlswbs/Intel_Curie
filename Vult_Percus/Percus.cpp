
/* Code automatically generated by Vult https://github.com/modlfo/vult */
#include "Percus.h"

float Percus_fold(float signal, float level){
   float sign;
   if(signal > 0.0f){
      sign = 1.f;
   }
   else
   {
      sign = -1.f;
   }
   float amp;
   amp = (fabsf(signal) * (1.f + (8.f * level)));
   float base;
   base = floorf(amp);
   float delta;
   delta = (amp + (- base));
   float out;
   if((float_to_int(base) % 2) != 0){
      out = (1.f + (- delta));
   }
   else
   {
      out = delta;
   }
   return (out * sign);
}

void Percus__ctx_type_16_init(Percus__ctx_type_16 &_output_){
   Percus__ctx_type_16 _ctx;
   _ctx.rate = 0.0f;
   _ctx.phase = 0.0f;
   Percus__ctx_type_0_init(_ctx._inst3be);
   Percus__ctx_type_1_init(_ctx._inst142);
   _output_ = _ctx;
   return ;
}

float Percus_phase(Percus__ctx_type_16 &_ctx, float cv, float reset){
   if(Percus_change(_ctx._inst142,cv)){
      _ctx.rate = Percus_cvToRate_1024(cv);
   }
   if(Percus_edge(_ctx._inst3be,(reset > 0.5f))){
      _ctx.phase = 0.0f;
   }
   else
   {
      _ctx.phase = (_ctx.phase + _ctx.rate);
   }
   if(_ctx.phase > 1024.f){
      _ctx.phase = (-1024.f + _ctx.phase);
   }
   return (0.0009765625f * _ctx.phase);
}

void Percus__ctx_type_17_init(Percus__ctx_type_17 &_output_){
   Percus__ctx_type_17 _ctx;
   _ctx.trig = false;
   Percus__ctx_type_16_init(_ctx.p);
   Percus__ctx_type_0_init(_ctx._inst1be);
   _output_ = _ctx;
   return ;
}

float Percus_sine(Percus__ctx_type_17 &_ctx, float cv, float reset){
   if(Percus_edge(_ctx._inst1be,(reset > 0.5f))){
      _ctx.trig = true;
   }
   float phase;
   phase = Percus_phase(_ctx.p,cv,0.0f);
   if((phase < 1e-018f) && _ctx.trig){
      _ctx.trig = false;
      Percus_phase(_ctx.p,cv,0.0f);
   }
   return Percus_nsine(phase);
}

void Percus__ctx_type_18_init(Percus__ctx_type_18 &_output_){
   Percus__ctx_type_18 _ctx;
   _ctx.target = 0.0f;
   _ctx.state = 0;
   _ctx.rate = 0.0f;
   _ctx.out = 0.0f;
   _ctx.hold_phase = 0.0f;
   _ctx.ahr_ret_1 = 0.0f;
   _ctx.ahr_ret_0 = 0.0f;
   Percus__ctx_type_0_init(_ctx._inst3be);
   Percus__ctx_type_0_init(_ctx._inst1be);
   _output_ = _ctx;
   return ;
}

void Percus_ahr(Percus__ctx_type_18 &_ctx, float gate, float a, float h, float r){
   int release;
   release = 0;
   int attack;
   attack = 1;
   int hold;
   hold = 2;
   int reset;
   reset = 3;
   uint8_t bgate;
   bgate = (gate > 0.0f);
   if(Percus_edge(_ctx._inst1be,bgate)){
      _ctx.state = reset;
   }
   float resetting;
   if(_ctx.state == reset){
      resetting = 1.f;
   }
   else
   {
      resetting = 0.0f;
   }
   if(Percus_edge(_ctx._inst3be,(_ctx.out > 1024.f))){
      _ctx.hold_phase = 0.0f;
      _ctx.state = hold;
   }
   if((_ctx.out < 10.f) && (_ctx.state == reset)){
      _ctx.state = attack;
   }
   if((_ctx.hold_phase > 100.f) && (_ctx.state == hold)){
      _ctx.state = release;
   }
   if(_ctx.state == reset){
      _ctx.rate = 0.990099009901f;
      _ctx.target = 0.0f;
   }
   if(_ctx.state == attack){
      _ctx.rate = (1.f / (0.01f + (100.f * a)));
      _ctx.target = 1228.8f;
   }
   if(_ctx.state == hold){
      float hrate;
      hrate = (1.f / (0.01f + (100.f * h)));
      _ctx.hold_phase = (_ctx.hold_phase + hrate);
   }
   if(_ctx.state == release){
      _ctx.rate = (1.f / (0.01f + (100.f * r)));
      _ctx.target = 0.0f;
   }
   _ctx.out = (_ctx.out + (0.005f * _ctx.rate * (_ctx.target + (- _ctx.out))));
   _ctx.ahr_ret_0 = float_clip((0.0009765625f * _ctx.out),0.0f,1.f);
   _ctx.ahr_ret_1 = resetting;
   return ;
}

float Percus_pinker(Percus__ctx_type_19 &_ctx, float x){
   float b0;
   b0 = 0.0277129863191f;
   float b1;
   b1 = 0.0277129863191f;
   float a1;
   a1 = -0.944574027362f;
   float w0;
   w0 = (x + (- (_ctx.w1 * a1)));
   float y0;
   y0 = ((_ctx.w1 * b1) + (b0 * w0));
   _ctx.w1 = w0;
   return y0;
}

void Percus__ctx_type_20_init(Percus__ctx_type_20 &_output_){
   Percus__ctx_type_20 _ctx;
   _ctx.x2 = 0;
   _ctx.x1 = 0;
   Percus__ctx_type_19_init(_ctx._inst157);
   _output_ = _ctx;
   return ;
}

float Percus_noise(Percus__ctx_type_20 &_ctx, float color){
   _ctx.x1 = ((7919 + (17389 * _ctx.x1)) % 32768);
   float y1;
   y1 = (3.0517578125e-005f * int_to_float(_ctx.x1));
   _ctx.x2 = ((12553 + (27449 * _ctx.x2)) % 32768);
   float y2;
   y2 = (3.0517578125e-005f * int_to_float(_ctx.x2));
   float out;
   if(color > 0.5f){
      out = Percus_pinker(_ctx._inst157,(y1 + (- y2)));
   }
   else
   {
      out = (y1 + (- y2));
   }
   return (0.5f * out);
}

void Percus__ctx_type_21_init(Percus__ctx_type_21 &_output_){
   Percus__ctx_type_21 _ctx;
   Percus__ctx_type_20_init(_ctx._inst3df);
   Percus__ctx_type_17_init(_ctx._inst2eb);
   Percus__ctx_type_18_init(_ctx._inst166);
   _output_ = _ctx;
   return ;
}

float Percus_process(Percus__ctx_type_21 &_ctx, float gate, float odecay, float pitch, float level, float noise){
   float osc_env;
   float env_reset;
   Percus_ahr(_ctx._inst166,gate,0.01f,(0.1f + odecay),(0.01f + odecay));
   osc_env = Percus_ahr_ret_0(_ctx._inst166);
   env_reset = Percus_ahr_ret_1(_ctx._inst166);
   float osc;
   osc = Percus_sine(_ctx._inst2eb,pitch,env_reset);
   float folder;
   folder = Percus_fold((osc + Percus_noise(_ctx._inst3df,noise)),level);
   return (folder * osc_env);
}


