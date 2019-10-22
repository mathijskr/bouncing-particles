#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

#include "termbox.h"

#include "constants.h"
#include "particle.h"

#define SIMULATION_SPEED 10 // Must be at least 10
#define DRAW_SPEED 16 // 16 := 60 fps

void *timer();

#endif
