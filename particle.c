#include "headers/particle.h"

void particle__init(Particle *this, float x, float y, float bounciness, char symbol, int color) {
	this->x = x;
	this->y = y;
	this->bounciness = bounciness;
	this->symbol = symbol;
	this->color = color;
	this->vx = 0.0f;
	this->vy = 0.0f;
	this->ax = 0.0f;
	this->ay = 0.0f;
}

void particle__update(Particle *this, float gravity, int GROUND) {
	this->ay = gravity;

	this->vy += this->ay;
	this->vx += this->ax;
	this->y += this->vy;
	this->x += this->vx;

	if(this->y > GROUND)
	{
		this->y = GROUND;
		this->vy = this->bounciness * -this->vy;
	}
}

void particle__draw(Particle *this) {
	tb_change_cell(this->x, this->y, this->symbol, this->color, BACKGROUND_COLOR);
}
