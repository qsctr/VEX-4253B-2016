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

#define DUMP_HEIGHT_GROUND 3250
#define DUMP_HEIGHT_LOW    2950
#define DUMP_HEIGHT_MID    2500
#define DUMP_HEIGHT_HIGH   1750

void a_dump_to(int height);
void a_dump_to_ground(void);
int  a_dump_pots_avg(void);

task a_lcd();
