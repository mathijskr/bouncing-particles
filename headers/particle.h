#ifndef PARTICLE_H
#define PARTICLE_H

#include "constants.h"

#define PARTICLE_COUNT 5

typedef struct Particle Particle;

struct Particle {
	float x, y;
	float vx, vy;
	float ax, ay;
	float bounciness;
	char symbol;
	int color;
};

/* Set the x, y position and speed of a particle
 * and set it's character symbol and color.
 * Set it's acceleration to zero. */
void particle__init(Particle *this, float x, float y, float vx, float vy, float bounciness, char symbol, int color);

/* Update a particle's acceleration, velocity and position. */
void particle__update(Particle *this, float gravity, int ground, int WALL);

/* Draw a particle at it's x, y position. */
void particle__draw(Particle *this);

void particle__collisions(Particle *particles, int par);

#endif
