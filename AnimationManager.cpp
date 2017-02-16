#include "AnimationManager.h"



AnimationManager::AnimationManager()
{
}


AnimationManager::~AnimationManager()
{
	animList.clear();
}


void AnimationManager::create(sf::String name, sf::Texture &t, int x, int y, int w, int h, int count, float speed, int step) {
	Animation a;
	a.speed = speed;
	a.sprite.setTexture(t);
	a.sprite.setOrigin(w/2, h/2);

	for (int i = 0; i<count; i++)
		a.frames.push_back(sf::IntRect(x + i*step, y, w, h));

	animList[name] = a;
	currentAnim = name;

}

void AnimationManager::draw(sf::RenderWindow &window, int x = 0, int y = 0) {
	animList[currentAnim].sprite.setPosition(x, y);
	window.draw(animList[currentAnim].sprite);



}

void AnimationManager::tick(float time) {
	animList[currentAnim].tick(time);
}

bool AnimationManager::End() {
	return animList[currentAnim].End();
}
