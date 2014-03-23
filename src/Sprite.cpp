#include "Sprite.h"
#include <string>
#include "SDL.h"
#include "Graphics.h"


Sprite::Sprite(const std::string& file_path, int source_x, int source_y, int width, int height){
	sprite_sheet_ = SDL_LoadBMP(file_path.c_str());

	// Set pink as the transparent color
	SDL_SetColorKey(sprite_sheet_, SDL_TRUE, SDL_MapRGB(sprite_sheet_->format, 255, 0, 255));

	source_rect_.x = source_x;
	source_rect_.y = source_y;
	source_rect_.w = width;
	source_rect_.h = height;
}

Sprite::~Sprite(){
	SDL_FreeSurface(sprite_sheet_);
}

void Sprite::draw(Graphics& g, int x, int y){
	
	SDL_Rect dest_rect;
	dest_rect.x = x;
	dest_rect.y = y;

	g.blitSurface(sprite_sheet_, &source_rect_, &dest_rect);
}
