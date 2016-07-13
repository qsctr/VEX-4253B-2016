void dc_shooter() {

	  motor[port6] = motor[port7] = (vexRT[Btn7R] - vexRT[Btn7L]) * 80;
}
