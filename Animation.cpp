#include "Animation.h"



Animation::Animation() {
	currentFrame = 0;
	isPlaying = true;
	rotate = 0;
	sprite.setScale(0.5, 0.5);
}


Animation::~Animation()
{
}

void Animation::tick(float time) {
	if (!isPlaying) return;

	currentFrame += speed * time;

	if (currentFrame > frames.size())
		currentFrame -= frames.size();

	int i = currentFrame;
	sprite.setTextureRect(frames[i]);

	sprite.setRotation(rotate);

}
