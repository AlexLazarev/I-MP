#include "Essentiality.h"



Essentiality::Essentiality() {
	dir = 0;
	life = 1;
	dx = dy = 0;
	angle = 0;
}

void Essentiality::create(AnimationManager a, float X, float Y,float Angle, float R) {
	anim = a;
	x = X;
	y = Y;
	angle = Angle;
	r = R/2;
}



void Essentiality::draw(sf::RenderWindow *&window) {
	anim.draw(window, x, y);
	
}

bool Essentiality::collision(Essentiality *second) {
	return sqrt((second->x - this->x)*(second->x - this->x) + 
		(second->y - this->y)*(second->y - this->y)) < (this->r + second->r);
}

