void a_base_forward(void) {

    base_set(BASE_SPEED_FULL);

}

void a_base_backward(void) {

    base_set(-BASE_SPEED_FULL);

}

void a_base_translate_left(void) {

    base_set(BASE_SPEED_FULL, -BASE_SPEED_FULL, BASE_SPEED_FULL, -BASE_SPEED_FULL);

}

void a_base_translate_right(void) {

    base_set(-BASE_SPEED_FULL, BASE_SPEED_FULL, -BASE_SPEED_FULL, BASE_SPEED_FULL);

}

void a_base_rotate_left(void) {

    base_set(BASE_SPEED_FULL, BASE_SPEED_FULL, -BASE_SPEED_FULL, -BASE_SPEED_FULL);

}

void a_base_rotate_right(void) {

    base_set(-BASE_SPEED_FULL, -BASE_SPEED_FULL, BASE_SPEED_FULL, BASE_SPEED_FULL);

}

void a_base_stop(void) {

    base_set(0);

}

int a_base_encoders_avg(void) {

    return (a_abs_encoder(BFR) + a_abs_encoder(BBR) + a_abs_encoder(BBL) + a_abs_encoder(BFL)) / 4;

}

void a_base_encoders_reset(void) {

    resetMotorEncoder(BFR);
    resetMotorEncoder(BBR);
    resetMotorEncoder(BBL);
    resetMotorEncoder(BFL);

}
