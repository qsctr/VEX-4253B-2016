void release_intake(void) {

    a_base_backward();
    while (a_base_encoders_avg() < 50);
    a_base_stop();

}
