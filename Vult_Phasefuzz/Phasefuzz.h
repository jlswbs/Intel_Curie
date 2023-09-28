
/* Code automatically generated by Vult https://github.com/modlfo/vult */
#ifndef PHASEFUZZ_H
#define PHASEFUZZ_H
#include <stdint.h>
#include <math.h>
#include "vultin.h"
#include "Phasefuzz.tables.h"

static_inline float Phasefuzz_nsine_raw_c0(int index){
   return Phasefuzz_nsine_c0[index];
};

static_inline float Phasefuzz_nsine_raw_c1(int index){
   return Phasefuzz_nsine_c1[index];
};

static_inline float Phasefuzz_nsine_raw_c2(int index){
   return Phasefuzz_nsine_c2[index];
};

static_inline float Phasefuzz_nsine(float x){
   int index;
   index = int_clip(float_to_int((127.f * x)),0,127);
   return (float_wrap_array(Phasefuzz_nsine_c0)[index] + (x * (float_wrap_array(Phasefuzz_nsine_c1)[index] + (x * float_wrap_array(Phasefuzz_nsine_c2)[index]))));
}

typedef struct Phasefuzz__ctx_type_4 {
   uint8_t pre;
} Phasefuzz__ctx_type_4;

typedef Phasefuzz__ctx_type_4 Phasefuzz_edge_type;

static_inline void Phasefuzz__ctx_type_4_init(Phasefuzz__ctx_type_4 &_output_){
   Phasefuzz__ctx_type_4 _ctx;
   _ctx.pre = false;
   _output_ = _ctx;
   return ;
}

static_inline void Phasefuzz_edge_init(Phasefuzz__ctx_type_4 &_output_){
   Phasefuzz__ctx_type_4_init(_output_);
   return ;
}

static_inline uint8_t Phasefuzz_edge(Phasefuzz__ctx_type_4 &_ctx, uint8_t x){
   uint8_t ret;
   ret = (x && bool_not(_ctx.pre));
   _ctx.pre = x;
   return ret;
}

typedef struct Phasefuzz__ctx_type_5 {
   float pre_x;
} Phasefuzz__ctx_type_5;

typedef Phasefuzz__ctx_type_5 Phasefuzz_change_type;

static_inline void Phasefuzz__ctx_type_5_init(Phasefuzz__ctx_type_5 &_output_){
   Phasefuzz__ctx_type_5 _ctx;
   _ctx.pre_x = 0.0f;
   _output_ = _ctx;
   return ;
}

static_inline void Phasefuzz_change_init(Phasefuzz__ctx_type_5 &_output_){
   Phasefuzz__ctx_type_5_init(_output_);
   return ;
}

static_inline uint8_t Phasefuzz_change(Phasefuzz__ctx_type_5 &_ctx, float x){
   uint8_t v;
   v = (_ctx.pre_x != x);
   _ctx.pre_x = x;
   return v;
}

typedef struct Phasefuzz__ctx_type_6 {
   float x;
} Phasefuzz__ctx_type_6;

typedef Phasefuzz__ctx_type_6 Phasefuzz_smooth_type;

static_inline void Phasefuzz__ctx_type_6_init(Phasefuzz__ctx_type_6 &_output_){
   Phasefuzz__ctx_type_6 _ctx;
   _ctx.x = 0.0f;
   _output_ = _ctx;
   return ;
}

static_inline void Phasefuzz_smooth_init(Phasefuzz__ctx_type_6 &_output_){
   Phasefuzz__ctx_type_6_init(_output_);
   return ;
}

static_inline float Phasefuzz_smooth(Phasefuzz__ctx_type_6 &_ctx, float input){
   _ctx.x = (_ctx.x + (0.005f * (input + (- _ctx.x))));
   return _ctx.x;
}

static_inline float Phasefuzz_pitchToRate_1024_raw_c0(int index){
   return Phasefuzz_pitchToRate_1024_c0[index];
};

static_inline float Phasefuzz_pitchToRate_1024_raw_c1(int index){
   return Phasefuzz_pitchToRate_1024_c1[index];
};

static_inline float Phasefuzz_pitchToRate_1024_raw_c2(int index){
   return Phasefuzz_pitchToRate_1024_c2[index];
};

static_inline float Phasefuzz_pitchToRate_1024(float pitch){
   int index;
   index = int_clip(float_to_int((0.244094488189f * pitch)),0,31);
   return (float_wrap_array(Phasefuzz_pitchToRate_1024_c0)[index] + (pitch * (float_wrap_array(Phasefuzz_pitchToRate_1024_c1)[index] + (pitch * float_wrap_array(Phasefuzz_pitchToRate_1024_c2)[index]))));
}

static_inline float Phasefuzz_cvToPitch(float cv){
   return (24.f + (120.f * cv));
};

static_inline float Phasefuzz_cvToRate_1024_raw_c0(int index){
   return Phasefuzz_cvToRate_1024_c0[index];
};

static_inline float Phasefuzz_cvToRate_1024_raw_c1(int index){
   return Phasefuzz_cvToRate_1024_c1[index];
};

static_inline float Phasefuzz_cvToRate_1024_raw_c2(int index){
   return Phasefuzz_cvToRate_1024_c2[index];
};

static_inline float Phasefuzz_cvToRate_1024(float cv){
   int index;
   index = int_clip(float_to_int((34.4444444444f * cv)),0,31);
   return (float_wrap_array(Phasefuzz_cvToRate_1024_c0)[index] + (cv * (float_wrap_array(Phasefuzz_cvToRate_1024_c1)[index] + (cv * float_wrap_array(Phasefuzz_cvToRate_1024_c2)[index]))));
}

static_inline float Phasefuzz_fuzz(float input){
   return (input + (-0.15f * powf(input,2.f)) + (-0.15f * powf(input,3.f)));
};

typedef struct Phasefuzz__ctx_type_17 {
   float rate;
   float phase;
   Phasefuzz__ctx_type_4 _inst36f;
   Phasefuzz__ctx_type_5 _inst1b2;
} Phasefuzz__ctx_type_17;

typedef Phasefuzz__ctx_type_17 Phasefuzz_phase_type;

void Phasefuzz__ctx_type_17_init(Phasefuzz__ctx_type_17 &_output_);

static_inline void Phasefuzz_phase_init(Phasefuzz__ctx_type_17 &_output_){
   Phasefuzz__ctx_type_17_init(_output_);
   return ;
}

float Phasefuzz_phase(Phasefuzz__ctx_type_17 &_ctx, float cv, float reset);

typedef struct Phasefuzz__ctx_type_18 {
   float pre_phase1;
   Phasefuzz__ctx_type_17 _inst3f3;
   Phasefuzz__ctx_type_6 _inst27b;
   Phasefuzz__ctx_type_17 _inst1f3;
} Phasefuzz__ctx_type_18;

typedef Phasefuzz__ctx_type_18 Phasefuzz_process_type;

void Phasefuzz__ctx_type_18_init(Phasefuzz__ctx_type_18 &_output_);

static_inline void Phasefuzz_process_init(Phasefuzz__ctx_type_18 &_output_){
   Phasefuzz__ctx_type_18_init(_output_);
   return ;
}

float Phasefuzz_process(Phasefuzz__ctx_type_18 &_ctx, float cv, float detune);



#endif // PHASEFUZZ_H