#include "main.h"

int GROUND;
bool EXIT = false;

int simulation_step = 0;

void *timer() {
	/* Needed for nanosleep. */
	struct timespec tim, tim2;
	tim.tv_sec = 0;
	tim.tv_nsec = 1000000000L * SIMULATION_SPEED;

	while(!EXIT){
		nanosleep(&tim, &tim2);
		simulation_step++;
	}
}

int main(int argv, char **argc){
	int code = tb_init();

	/* Check if termbox was initialized. */
	if(code < 0){
		fprintf(stderr, "termbox init failed, code: %d\n", code);
		return -1;
	}

	tb_select_input_mode(TB_INPUT_ESC);
	tb_select_output_mode(TB_OUTPUT_NORMAL);
	tb_clear();

	GROUND = tb_height() - 1;

	struct tb_event ev;

	Particle testParticle;
	particle__init(&testParticle, 10.0f, 0.0f, 0.8f, '*', TB_GREEN);

	pthread_t timer_thread;
	pthread_create(&timer_thread, NULL, timer, NULL);

	/* Quit loop if exit is true. */
	while(!EXIT){
		tb_clear();

		/* Draw the background. */
		for(int x = 0; x < tb_width(); x++){
			for(int y = 0; y < tb_height(); y++){
				tb_change_cell(x, y, ' ', BACKGROUND_COLOR,
				BACKGROUND_COLOR);
			}
		}

		/* Update the simulation. */
		if(simulation_step > 0) {
			if(simulation_step != 1) { printf("Simulation speed to quick"); }
			particle__update(&testParticle, GRAVITY * SIMULATION_SPEED, GROUND);
			simulation_step = 0;
		}

		particle__draw(&testParticle);

		/* Draw to screen. */
		tb_present();

		/* Update input with a timeout of n ms. */
		int input = tb_peek_event(&ev, 0);

		if(input == TB_INPUT_ESC)
			EXIT = true;
	}

	tb_shutdown();
	return 0;
}
