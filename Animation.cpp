#include "Animation.h"



Animation::Animation() {
	currentFrame = 0;
	isPlaying = true;
	end = false;
	rotate = 0;
	sprite.setScale(0.5, 0.5);
}


Animation::~Animation()
{
}

void Animation::tick(float time) {
	//if (!isPlaying) return;

	currentFrame += speed * time;

	if (currentFrame > frames.size())
	{
		currentFrame -= frames.size();
		end = true;
	}

	int i = currentFrame;
	sprite.setTextureRect(frames[i]);

	sprite.setRotation(rotate);

}

bool Animation::End() {
	return end;
}