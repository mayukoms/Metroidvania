#include "Sprite.h"
#include "SDL.h"
#include "Graphics.h"


Sprite::Sprite(SDL_Texture* texture, int source_x, int source_y, int width, int height){
	sprite_sheet_ = texture;

	w = width;
	h = height;
	source_rect_ = { source_x, source_y, width, height };
}

Sprite::~Sprite(){
	if (sprite_sheet_ != nullptr){
		SDL_DestroyTexture(sprite_sheet_);
	}
}

void Sprite::draw(Graphics& g, int x, int y){

	SDL_Rect dest_rect{x,y,w, h};

	g.RenderCopy(sprite_sheet_, &source_rect_, &dest_rect);
}
