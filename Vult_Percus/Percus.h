
/* Code automatically generated by Vult https://github.com/modlfo/vult */
#ifndef PERCUS_H
#define PERCUS_H
#include <stdint.h>
#include <math.h>
#include "vultin.h"
#include "Percus.tables.h"

typedef struct _tuple___real_real__ {
   float field_0;
   float field_1;
} _tuple___real_real__;

typedef struct Percus__ctx_type_0 {
   uint8_t pre;
} Percus__ctx_type_0;

typedef Percus__ctx_type_0 Percus_edge_type;

static_inline void Percus__ctx_type_0_init(Percus__ctx_type_0 &_output_){
   Percus__ctx_type_0 _ctx;
   _ctx.pre = false;
   _output_ = _ctx;
   return ;
}

static_inline void Percus_edge_init(Percus__ctx_type_0 &_output_){
   Percus__ctx_type_0_init(_output_);
   return ;
}

static_inline uint8_t Percus_edge(Percus__ctx_type_0 &_ctx, uint8_t x){
   uint8_t ret;
   ret = (x && bool_not(_ctx.pre));
   _ctx.pre = x;
   return ret;
}

typedef struct Percus__ctx_type_1 {
   float pre_x;
} Percus__ctx_type_1;

typedef Percus__ctx_type_1 Percus_change_type;

static_inline void Percus__ctx_type_1_init(Percus__ctx_type_1 &_output_){
   Percus__ctx_type_1 _ctx;
   _ctx.pre_x = 0.0f;
   _output_ = _ctx;
   return ;
}

static_inline void Percus_change_init(Percus__ctx_type_1 &_output_){
   Percus__ctx_type_1_init(_output_);
   return ;
}

static_inline uint8_t Percus_change(Percus__ctx_type_1 &_ctx, float x){
   uint8_t v;
   v = (_ctx.pre_x != x);
   _ctx.pre_x = x;
   return v;
}

static_inline float Percus_pitchToRate_1024_raw_c0(int index){
   return Percus_pitchToRate_1024_c0[index];
};

static_inline float Percus_pitchToRate_1024_raw_c1(int index){
   return Percus_pitchToRate_1024_c1[index];
};

static_inline float Percus_pitchToRate_1024_raw_c2(int index){
   return Percus_pitchToRate_1024_c2[index];
};

static_inline float Percus_pitchToRate_1024(float pitch){
   int index;
   index = int_clip(float_to_int((0.244094488189f * pitch)),0,31);
   return (float_wrap_array(Percus_pitchToRate_1024_c0)[index] + (pitch * (float_wrap_array(Percus_pitchToRate_1024_c1)[index] + (pitch * float_wrap_array(Percus_pitchToRate_1024_c2)[index]))));
}

static_inline float Percus_cvToPitch(float cv){
   return (24.f + (120.f * cv));
};

static_inline float Percus_cvToRate_1024_raw_c0(int index){
   return Percus_cvToRate_1024_c0[index];
};

static_inline float Percus_cvToRate_1024_raw_c1(int index){
   return Percus_cvToRate_1024_c1[index];
};

static_inline float Percus_cvToRate_1024_raw_c2(int index){
   return Percus_cvToRate_1024_c2[index];
};

static_inline float Percus_cvToRate_1024(float cv){
   int index;
   index = int_clip(float_to_int((34.4444444444f * cv)),0,31);
   return (float_wrap_array(Percus_cvToRate_1024_c0)[index] + (cv * (float_wrap_array(Percus_cvToRate_1024_c1)[index] + (cv * float_wrap_array(Percus_cvToRate_1024_c2)[index]))));
}

float Percus_fold(float signal, float level);

static_inline float Percus_nsine_raw_c0(int index){
   return Percus_nsine_c0[index];
};

static_inline float Percus_nsine_raw_c1(int index){
   return Percus_nsine_c1[index];
};

static_inline float Percus_nsine_raw_c2(int index){
   return Percus_nsine_c2[index];
};

static_inline float Percus_nsine(float x){
   int index;
   index = int_clip(float_to_int((127.f * x)),0,127);
   return (float_wrap_array(Percus_nsine_c0)[index] + (x * (float_wrap_array(Percus_nsine_c1)[index] + (x * float_wrap_array(Percus_nsine_c2)[index]))));
}

typedef struct Percus__ctx_type_16 {
   float rate;
   float phase;
   Percus__ctx_type_0 _inst3be;
   Percus__ctx_type_1 _inst142;
} Percus__ctx_type_16;

typedef Percus__ctx_type_16 Percus_phase_type;

void Percus__ctx_type_16_init(Percus__ctx_type_16 &_output_);

static_inline void Percus_phase_init(Percus__ctx_type_16 &_output_){
   Percus__ctx_type_16_init(_output_);
   return ;
}

float Percus_phase(Percus__ctx_type_16 &_ctx, float cv, float reset);

typedef struct Percus__ctx_type_17 {
   uint8_t trig;
   Percus__ctx_type_16 p;
   Percus__ctx_type_0 _inst1be;
} Percus__ctx_type_17;

typedef Percus__ctx_type_17 Percus_sine_type;

void Percus__ctx_type_17_init(Percus__ctx_type_17 &_output_);

static_inline void Percus_sine_init(Percus__ctx_type_17 &_output_){
   Percus__ctx_type_17_init(_output_);
   return ;
}

float Percus_sine(Percus__ctx_type_17 &_ctx, float cv, float reset);

typedef struct Percus__ctx_type_18 {
   float target;
   int state;
   float rate;
   float out;
   float hold_phase;
   float ahr_ret_1;
   float ahr_ret_0;
   Percus__ctx_type_0 _inst3be;
   Percus__ctx_type_0 _inst1be;
} Percus__ctx_type_18;

typedef Percus__ctx_type_18 Percus_ahr_type;

void Percus__ctx_type_18_init(Percus__ctx_type_18 &_output_);

static_inline void Percus_ahr_init(Percus__ctx_type_18 &_output_){
   Percus__ctx_type_18_init(_output_);
   return ;
}

void Percus_ahr(Percus__ctx_type_18 &_ctx, float gate, float a, float h, float r);

typedef Percus__ctx_type_18 Percus_ahr_ret_0_type;

static_inline void Percus_ahr_ret_0_init(Percus__ctx_type_18 &_output_){
   Percus__ctx_type_18_init(_output_);
   return ;
}

static_inline float Percus_ahr_ret_0(Percus__ctx_type_18 &_ctx){
   return _ctx.ahr_ret_0;
};

typedef Percus__ctx_type_18 Percus_ahr_ret_1_type;

static_inline void Percus_ahr_ret_1_init(Percus__ctx_type_18 &_output_){
   Percus__ctx_type_18_init(_output_);
   return ;
}

static_inline float Percus_ahr_ret_1(Percus__ctx_type_18 &_ctx){
   return _ctx.ahr_ret_1;
};

typedef struct Percus__ctx_type_19 {
   float w1;
} Percus__ctx_type_19;

typedef Percus__ctx_type_19 Percus_pinker_type;

static_inline void Percus__ctx_type_19_init(Percus__ctx_type_19 &_output_){
   Percus__ctx_type_19 _ctx;
   _ctx.w1 = 0.0f;
   _output_ = _ctx;
   return ;
}

static_inline void Percus_pinker_init(Percus__ctx_type_19 &_output_){
   Percus__ctx_type_19_init(_output_);
   return ;
}

float Percus_pinker(Percus__ctx_type_19 &_ctx, float x);

typedef struct Percus__ctx_type_20 {
   int x2;
   int x1;
   Percus__ctx_type_19 _inst157;
} Percus__ctx_type_20;

typedef Percus__ctx_type_20 Percus_noise_type;

void Percus__ctx_type_20_init(Percus__ctx_type_20 &_output_);

static_inline void Percus_noise_init(Percus__ctx_type_20 &_output_){
   Percus__ctx_type_20_init(_output_);
   return ;
}

float Percus_noise(Percus__ctx_type_20 &_ctx, float color);

typedef struct Percus__ctx_type_21 {
   Percus__ctx_type_20 _inst3df;
   Percus__ctx_type_17 _inst2eb;
   Percus__ctx_type_18 _inst166;
} Percus__ctx_type_21;

typedef Percus__ctx_type_21 Percus_process_type;

void Percus__ctx_type_21_init(Percus__ctx_type_21 &_output_);

static_inline void Percus_process_init(Percus__ctx_type_21 &_output_){
   Percus__ctx_type_21_init(_output_);
   return ;
}

float Percus_process(Percus__ctx_type_21 &_ctx, float gate, float odecay, float pitch, float level, float noise);



#endif // PERCUS_H