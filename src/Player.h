#ifndef PLAYER_H_
#define PLAYER_H_

#include "AnimatedSprite.h"
#include "Input.h"

struct SDL_Texture;

class Player : public AnimatedSprite{
public:
	Player(SDL_Texture* texture, int x, int y);
	int x_pos_;
	int y_pos_;

	void movePlayer(Input i);
};

#endif