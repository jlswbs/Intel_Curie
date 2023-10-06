
/* Code automatically generated by Vult https://github.com/modlfo/vult */
#ifndef ADDFOLD_H
#define ADDFOLD_H
#include <stdint.h>
#include <math.h>
#include "vultin.h"
#include "Addfold.tables.h"

static_inline float Addfold_nsine_raw_c0(int index){
   return Addfold_nsine_c0[index];
};

static_inline float Addfold_nsine_raw_c1(int index){
   return Addfold_nsine_c1[index];
};

static_inline float Addfold_nsine_raw_c2(int index){
   return Addfold_nsine_c2[index];
};

static_inline float Addfold_nsine(float x){
   int index;
   index = int_clip(float_to_int((127.f * x)),0,127);
   return (float_wrap_array(Addfold_nsine_c0)[index] + (x * (float_wrap_array(Addfold_nsine_c1)[index] + (x * float_wrap_array(Addfold_nsine_c2)[index]))));
}

typedef struct Addfold__ctx_type_4 {
   uint8_t pre;
} Addfold__ctx_type_4;

typedef Addfold__ctx_type_4 Addfold_edge_type;

static_inline void Addfold__ctx_type_4_init(Addfold__ctx_type_4 &_output_){
   Addfold__ctx_type_4 _ctx;
   _ctx.pre = false;
   _output_ = _ctx;
   return ;
}

static_inline void Addfold_edge_init(Addfold__ctx_type_4 &_output_){
   Addfold__ctx_type_4_init(_output_);
   return ;
}

static_inline uint8_t Addfold_edge(Addfold__ctx_type_4 &_ctx, uint8_t x){
   uint8_t ret;
   ret = (x && bool_not(_ctx.pre));
   _ctx.pre = x;
   return ret;
}

typedef struct Addfold__ctx_type_5 {
   float pre_x;
} Addfold__ctx_type_5;

typedef Addfold__ctx_type_5 Addfold_change_type;

static_inline void Addfold__ctx_type_5_init(Addfold__ctx_type_5 &_output_){
   Addfold__ctx_type_5 _ctx;
   _ctx.pre_x = 0.0f;
   _output_ = _ctx;
   return ;
}

static_inline void Addfold_change_init(Addfold__ctx_type_5 &_output_){
   Addfold__ctx_type_5_init(_output_);
   return ;
}

static_inline uint8_t Addfold_change(Addfold__ctx_type_5 &_ctx, float x){
   uint8_t v;
   v = (_ctx.pre_x != x);
   _ctx.pre_x = x;
   return v;
}

static_inline float Addfold_cvToPitch(float cv){
   return (24.f + (120.f * cv));
};

static_inline float Addfold_pitchToRate_1024_raw_c0(int index){
   return Addfold_pitchToRate_1024_c0[index];
};

static_inline float Addfold_pitchToRate_1024_raw_c1(int index){
   return Addfold_pitchToRate_1024_c1[index];
};

static_inline float Addfold_pitchToRate_1024_raw_c2(int index){
   return Addfold_pitchToRate_1024_c2[index];
};

static_inline float Addfold_pitchToRate_1024(float pitch){
   int index;
   index = int_clip(float_to_int((0.244094488189f * pitch)),0,31);
   return (float_wrap_array(Addfold_pitchToRate_1024_c0)[index] + (pitch * (float_wrap_array(Addfold_pitchToRate_1024_c1)[index] + (pitch * float_wrap_array(Addfold_pitchToRate_1024_c2)[index]))));
}

static_inline float Addfold_cvToRate_1024_raw_c0(int index){
   return Addfold_cvToRate_1024_c0[index];
};

static_inline float Addfold_cvToRate_1024_raw_c1(int index){
   return Addfold_cvToRate_1024_c1[index];
};

static_inline float Addfold_cvToRate_1024_raw_c2(int index){
   return Addfold_cvToRate_1024_c2[index];
};

static_inline float Addfold_cvToRate_1024(float cv){
   int index;
   index = int_clip(float_to_int((34.4444444444f * cv)),0,31);
   return (float_wrap_array(Addfold_cvToRate_1024_c0)[index] + (cv * (float_wrap_array(Addfold_cvToRate_1024_c1)[index] + (cv * float_wrap_array(Addfold_cvToRate_1024_c2)[index]))));
}

float Addfold_fold(float x, float lim);

typedef struct Addfold__ctx_type_16 {
   float rate;
   float phase;
   Addfold__ctx_type_4 _inst32b;
   Addfold__ctx_type_5 _inst12f;
} Addfold__ctx_type_16;

typedef Addfold__ctx_type_16 Addfold_phase_type;

void Addfold__ctx_type_16_init(Addfold__ctx_type_16 &_output_);

static_inline void Addfold_phase_init(Addfold__ctx_type_16 &_output_){
   Addfold__ctx_type_16_init(_output_);
   return ;
}

float Addfold_phase(Addfold__ctx_type_16 &_ctx, float cv, float reset);

typedef struct Addfold__ctx_type_17 {
   uint8_t trig;
   Addfold__ctx_type_16 _inst5ce;
   Addfold__ctx_type_16 _inst3ce;
   Addfold__ctx_type_4 _inst12b;
} Addfold__ctx_type_17;

typedef Addfold__ctx_type_17 Addfold_sine_type;

void Addfold__ctx_type_17_init(Addfold__ctx_type_17 &_output_);

static_inline void Addfold_sine_init(Addfold__ctx_type_17 &_output_){
   Addfold__ctx_type_17_init(_output_);
   return ;
}

float Addfold_sine(Addfold__ctx_type_17 &_ctx, float cv, float reset);

typedef struct Addfold__ctx_type_18 {
   Addfold__ctx_type_17 _inst2b3;
   Addfold__ctx_type_17 _inst1b3;
} Addfold__ctx_type_18;

typedef Addfold__ctx_type_18 Addfold_process_type;

void Addfold__ctx_type_18_init(Addfold__ctx_type_18 &_output_);

static_inline void Addfold_process_init(Addfold__ctx_type_18 &_output_){
   Addfold__ctx_type_18_init(_output_);
   return ;
}

static_inline float Addfold_process(Addfold__ctx_type_18 &_ctx, float cv1, float cv2, float rst, float drv){
   return Addfold_fold((Addfold_sine(_ctx._inst1b3,cv1,rst) + (0.5f * Addfold_sine(_ctx._inst2b3,cv2,rst))),drv);
};



#endif // ADDFOLD_H