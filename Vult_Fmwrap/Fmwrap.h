
/* Code automatically generated by Vult https://github.com/modlfo/vult */
#ifndef FMWRAP_H
#define FMWRAP_H
#include <stdint.h>
#include <math.h>
#include "vultin.h"
#include "Fmwrap.tables.h"

static_inline float Fmwrap_nsine_raw_c0(int index){
   return Fmwrap_nsine_c0[index];
};

static_inline float Fmwrap_nsine_raw_c1(int index){
   return Fmwrap_nsine_c1[index];
};

static_inline float Fmwrap_nsine_raw_c2(int index){
   return Fmwrap_nsine_c2[index];
};

static_inline float Fmwrap_nsine(float x){
   int index;
   index = int_clip(float_to_int((127.f * x)),0,127);
   return (float_wrap_array(Fmwrap_nsine_c0)[index] + (x * (float_wrap_array(Fmwrap_nsine_c1)[index] + (x * float_wrap_array(Fmwrap_nsine_c2)[index]))));
}

typedef struct Fmwrap__ctx_type_4 {
   uint8_t pre;
} Fmwrap__ctx_type_4;

typedef Fmwrap__ctx_type_4 Fmwrap_edge_type;

static_inline void Fmwrap__ctx_type_4_init(Fmwrap__ctx_type_4 &_output_){
   Fmwrap__ctx_type_4 _ctx;
   _ctx.pre = false;
   _output_ = _ctx;
   return ;
}

static_inline void Fmwrap_edge_init(Fmwrap__ctx_type_4 &_output_){
   Fmwrap__ctx_type_4_init(_output_);
   return ;
}

static_inline uint8_t Fmwrap_edge(Fmwrap__ctx_type_4 &_ctx, uint8_t x){
   uint8_t ret;
   ret = (x && bool_not(_ctx.pre));
   _ctx.pre = x;
   return ret;
}

typedef struct Fmwrap__ctx_type_5 {
   float pre_x;
} Fmwrap__ctx_type_5;

typedef Fmwrap__ctx_type_5 Fmwrap_change_type;

static_inline void Fmwrap__ctx_type_5_init(Fmwrap__ctx_type_5 &_output_){
   Fmwrap__ctx_type_5 _ctx;
   _ctx.pre_x = 0.0f;
   _output_ = _ctx;
   return ;
}

static_inline void Fmwrap_change_init(Fmwrap__ctx_type_5 &_output_){
   Fmwrap__ctx_type_5_init(_output_);
   return ;
}

static_inline uint8_t Fmwrap_change(Fmwrap__ctx_type_5 &_ctx, float x){
   uint8_t v;
   v = (_ctx.pre_x != x);
   _ctx.pre_x = x;
   return v;
}

static_inline float Fmwrap_cvToPitch(float cv){
   return (24.f + (120.f * cv));
};

static_inline float Fmwrap_pitchToRate_1024_raw_c0(int index){
   return Fmwrap_pitchToRate_1024_c0[index];
};

static_inline float Fmwrap_pitchToRate_1024_raw_c1(int index){
   return Fmwrap_pitchToRate_1024_c1[index];
};

static_inline float Fmwrap_pitchToRate_1024_raw_c2(int index){
   return Fmwrap_pitchToRate_1024_c2[index];
};

static_inline float Fmwrap_pitchToRate_1024(float pitch){
   int index;
   index = int_clip(float_to_int((0.244094488189f * pitch)),0,31);
   return (float_wrap_array(Fmwrap_pitchToRate_1024_c0)[index] + (pitch * (float_wrap_array(Fmwrap_pitchToRate_1024_c1)[index] + (pitch * float_wrap_array(Fmwrap_pitchToRate_1024_c2)[index]))));
}

static_inline float Fmwrap_cvToRate_1024_raw_c0(int index){
   return Fmwrap_cvToRate_1024_c0[index];
};

static_inline float Fmwrap_cvToRate_1024_raw_c1(int index){
   return Fmwrap_cvToRate_1024_c1[index];
};

static_inline float Fmwrap_cvToRate_1024_raw_c2(int index){
   return Fmwrap_cvToRate_1024_c2[index];
};

static_inline float Fmwrap_cvToRate_1024(float cv){
   int index;
   index = int_clip(float_to_int((34.4444444444f * cv)),0,31);
   return (float_wrap_array(Fmwrap_cvToRate_1024_c0)[index] + (cv * (float_wrap_array(Fmwrap_cvToRate_1024_c1)[index] + (cv * float_wrap_array(Fmwrap_cvToRate_1024_c2)[index]))));
}

float Fmwrap_wrap(float inp, float lim);

typedef struct Fmwrap__ctx_type_16 {
   float rate;
   float phase;
   Fmwrap__ctx_type_4 _inst34f;
   Fmwrap__ctx_type_5 _inst16d;
} Fmwrap__ctx_type_16;

typedef Fmwrap__ctx_type_16 Fmwrap_phase_type;

void Fmwrap__ctx_type_16_init(Fmwrap__ctx_type_16 &_output_);

static_inline void Fmwrap_phase_init(Fmwrap__ctx_type_16 &_output_){
   Fmwrap__ctx_type_16_init(_output_);
   return ;
}

float Fmwrap_phase(Fmwrap__ctx_type_16 &_ctx, float cv, float reset);

typedef struct Fmwrap__ctx_type_17 {
   uint8_t trig;
   Fmwrap__ctx_type_16 _inst5ff;
   Fmwrap__ctx_type_16 _inst3ff;
   Fmwrap__ctx_type_4 _inst14f;
} Fmwrap__ctx_type_17;

typedef Fmwrap__ctx_type_17 Fmwrap_sine_type;

void Fmwrap__ctx_type_17_init(Fmwrap__ctx_type_17 &_output_);

static_inline void Fmwrap_sine_init(Fmwrap__ctx_type_17 &_output_){
   Fmwrap__ctx_type_17_init(_output_);
   return ;
}

float Fmwrap_sine(Fmwrap__ctx_type_17 &_ctx, float cv, float reset);

typedef struct Fmwrap__ctx_type_18 {
   Fmwrap__ctx_type_17 _inst2d9;
   Fmwrap__ctx_type_17 _inst1d9;
} Fmwrap__ctx_type_18;

typedef Fmwrap__ctx_type_18 Fmwrap_process_type;

void Fmwrap__ctx_type_18_init(Fmwrap__ctx_type_18 &_output_);

static_inline void Fmwrap_process_init(Fmwrap__ctx_type_18 &_output_){
   Fmwrap__ctx_type_18_init(_output_);
   return ;
}

static_inline float Fmwrap_process(Fmwrap__ctx_type_18 &_ctx, float cv, float rst, float drv){
   return Fmwrap_wrap((0.5f * Fmwrap_sine(_ctx._inst2d9,Fmwrap_sine(_ctx._inst1d9,cv,rst),rst)),drv);
};



#endif // FMWRAP_H
