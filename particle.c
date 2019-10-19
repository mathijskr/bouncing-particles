#include "headers/particle.h"

void particle__init(Particle *this, float x, float y, float vx, float vy, float bounciness, char symbol, int color) {
	this->x = x;
	this->y = y;
	this->bounciness = bounciness;
	this->symbol = symbol;
	this->color = color;
	this->vx = vx;
	this->vy = vy;
	this->ax = 0.0f;
	this->ay = 0.0f;
}

void particle__collisions(Particle *particles, int par) {
	for(int i = par; i < PARTICLE_COUNT; i++) {
		if(((particles[par].x - particles[i].x) * (particles[par].x - particles[i].x) <= 1.0f) &&
		   ((particles[par].y - particles[i].y) * (particles[par].y - particles[i].y) <= 1.0f)) {
		}
	}
}

void particle__update(Particle *this, float gravity, int ground, int wall) {
	this->ay = gravity;

	this->vy += this->ay;
	this->vx += this->ax;
	this->y += this->vy;
	this->x += this->vx;

	if(this->y >= ground) {
		this->y = ground;
		this->vy = this->bounciness * -this->vy;
	}

	if(this->x >= wall) {
		this->x = wall;
		this->vx = this->bounciness * -this->vx;
	}

	if(this->x <= 0.0f) {
		this->x = 0.0f;
		this->vx = this->bounciness * -this->vx;
	}
}

void particle__draw(Particle *this) {
	tb_change_cell(this->x, this->y, this->symbol, this->color, BACKGROUND_COLOR);
}
