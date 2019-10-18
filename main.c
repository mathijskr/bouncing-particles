#include "main.h"

int main(int argv, char **argc)
{
	int code = tb_init();

	/* Check if termbox was initialized. */
	if (code < 0)
	{
		fprintf(stderr, "termbox init failed, code: %d\n", code);
		return -1;
	}

	tb_select_input_mode(TB_INPUT_ESC);
	tb_select_output_mode(TB_OUTPUT_NORMAL);
	tb_clear();

	bool exit = false;

	struct tb_event ev;

	/* Quit loop if exit is true */
	while(!exit)
	{
		tb_clear();

		/* Draw to screen. */
		tb_present();

		/* Update input with a timeout of n ms. */
		int input = tb_peek_event(&ev, 0);

		if(input == TB_INPUT_ESC)
			exit = true;
	}

	printf("Exit");

	tb_shutdown();
	return 0;
}
