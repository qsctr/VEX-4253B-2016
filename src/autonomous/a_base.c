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
