
/* Code automatically generated by Vult https://github.com/modlfo/vult */
#include "Fmwrap.h"

float Fmwrap_wrap(float inp, float lim){
   while((inp > lim) || (inp < (- lim))){
      if(inp > lim){
         inp = (inp + (- lim) + (- lim));
      }
      else
      {
         if(inp < (- lim)){
            inp = (lim + (- ((- inp) + (- lim))));
         }
      }
   }
   return inp;
}

void Fmwrap__ctx_type_16_init(Fmwrap__ctx_type_16 &_output_){
   Fmwrap__ctx_type_16 _ctx;
   _ctx.rate = 0.0f;
   _ctx.phase = 0.0f;
   Fmwrap__ctx_type_4_init(_ctx._inst34f);
   Fmwrap__ctx_type_5_init(_ctx._inst16d);
   _output_ = _ctx;
   return ;
}

float Fmwrap_phase(Fmwrap__ctx_type_16 &_ctx, float cv, float reset){
   if(Fmwrap_change(_ctx._inst16d,cv)){
      _ctx.rate = Fmwrap_cvToRate_1024(cv);
   }
   if(Fmwrap_edge(_ctx._inst34f,(reset > 0.5f))){
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

void Fmwrap__ctx_type_17_init(Fmwrap__ctx_type_17 &_output_){
   Fmwrap__ctx_type_17 _ctx;
   _ctx.trig = false;
   Fmwrap__ctx_type_16_init(_ctx._inst5ff);
   Fmwrap__ctx_type_16_init(_ctx._inst3ff);
   Fmwrap__ctx_type_4_init(_ctx._inst14f);
   _output_ = _ctx;
   return ;
}

float Fmwrap_sine(Fmwrap__ctx_type_17 &_ctx, float cv, float reset){
   if(Fmwrap_edge(_ctx._inst14f,(reset > 0.5f))){
      _ctx.trig = true;
   }
   float phase;
   phase = Fmwrap_phase(_ctx._inst3ff,cv,0.0f);
   if((phase < 1e-018f) && _ctx.trig){
      _ctx.trig = false;
      Fmwrap_phase(_ctx._inst5ff,cv,0.0f);
   }
   return Fmwrap_nsine(phase);
}

void Fmwrap__ctx_type_18_init(Fmwrap__ctx_type_18 &_output_){
   Fmwrap__ctx_type_18 _ctx;
   Fmwrap__ctx_type_17_init(_ctx._inst2d9);
   Fmwrap__ctx_type_17_init(_ctx._inst1d9);
   _output_ = _ctx;
   return ;
}


