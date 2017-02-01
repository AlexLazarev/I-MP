#pragma once
#include "Animation.h" 

class AnimationManager
{
public:
	sf::String currentAnim;
	std::map<sf::String, Animation> animList;


	AnimationManager();
	~AnimationManager();

	void create(sf::String name, sf::Texture &t, int x, int y, int w, int h, int count, float speed, int step);
	void draw(sf::RenderWindow &window, int x, int y);


	void set(sf::String name) { currentAnim = name; }

	void setRotate(int b = 0) { animList[currentAnim].rotate = b; }
	void tick(float time);
	void pause() { animList[currentAnim].isPlaying = false; }
	void play() { animList[currentAnim].isPlaying = true; }
	void play(std::string name) { animList[name].isPlaying = true; }
};

