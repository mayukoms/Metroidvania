#include "Player.h"
#include "AnimatedSprite.h"

Player::Player(SDL_Texture* texture, int x, int y) : 
	AnimatedSprite(texture, 32, 0, 32, 32, 15, 2),
	x_pos_(x),
	y_pos_(y)
{
}

void Player::movePlayer(Input input){
	if (input.isKeyHeld(SDLK_UP)){
		y_pos_--;
	}
	if (input.isKeyHeld(SDLK_DOWN)){
		y_pos_++;
	}
	if (input.isKeyHeld(SDLK_LEFT)){
		if (source_rect_.y == 32){
			source_rect_.y = 0;
		}
		x_pos_--;
	}
	if (input.isKeyHeld(SDLK_RIGHT)){
		if (source_rect_.y == 0){
			source_rect_.y = 32;
		}
		x_pos_++;
	}
}