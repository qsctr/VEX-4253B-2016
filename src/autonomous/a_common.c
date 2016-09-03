#define a_abs_encoder(enc) abs(nMotorEncoder(enc))

void a_base_forward(void);
void a_base_backward(void);
void a_base_translate_left(void);
void a_base_translate_right(void);
void a_base_rotate_left(void);
void a_base_rotate_right(void);
void a_base_stop(void);
int  a_base_encoders_avg(void);
void a_base_encoders_reset(void);

task a_lcd();
