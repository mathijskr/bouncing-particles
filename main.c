#include "main.h"

int GROUND;
int WALL;
bool EXIT = false;

int elapsed_time = 0;


int main(int argv, char **argc)
{
	int code = tb_init();

	/* Check if termbox was initialized. */
	if(code < 0) {
		fprintf(stderr, "termbox init failed, code: %d\n", code);
		return -1;
	}

	tb_select_input_mode(TB_INPUT_ESC);
	tb_select_output_mode(TB_OUTPUT_NORMAL);
	tb_clear();

	GROUND = tb_height() - 1;
	WALL = tb_width() - 1;

	struct tb_event ev;

	Particle particles[PARTICLE_COUNT];

	for(int i = 0; i < PARTICLE_COUNT; i++)
		particle__init(&particles[i], 0.0f + 0.8f * i, 0.0f + 0.2f * i, 0.1f, 0.0f, 0.95f, '@', TB_RED);

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
		if(elapsed_time % SIMULATION_SPEED == 0) {

			/* Collision detection. */
			/*for(int i = 0; i < PARTICLE_COUNT; i++)
				particle__collisions(particles, i);*/

			for(int i = 0; i < PARTICLE_COUNT; i++)
				particle__update(&particles[i], GRAVITY / (1000.0f / SIMULATION_SPEED), GROUND, WALL);

			/* Increase time to ensure that the simulation won't be updated more than once. */
			elapsed_time++;
		}

		/* Draw. */
		if(elapsed_time % DRAW_SPEED == 0) {
			for(int i = 0; i < PARTICLE_COUNT; i++)
				particle__draw(&particles[i]);

			/* Draw to screen. */
			tb_present();

			/* Increase time to ensure that the simulation won't be drawn more than once. */
			elapsed_time++;
		}

		/* Update input with a timeout of n ms. */
		int input = tb_peek_event(&ev, 0);

		if(input == TB_INPUT_ESC)
			EXIT = true;
	}

	tb_shutdown();
	return 0;
}

void *timer()
{
	/* Needed for nanosleep. */
	struct timespec tim, tim2;
	tim.tv_sec = 0;
	tim.tv_nsec = 1000000;

	while(!EXIT){
		nanosleep(&tim, &tim2);
		elapsed_time++;

		if(elapsed_time == 160)
			elapsed_time = 0;
	}

	return &EXIT;
}
