#ifndef SPRITE_H_
#define SPRITE_H_

#include "SDL.h"

struct SDL_Surface;
struct Graphics;

class Sprite{
public:
	Sprite(SDL_Texture* texture, int source_x, int source_y, int width, int height);
	virtual ~Sprite();
	
	virtual void update(int){};
	void draw(Graphics& g, int x, int y);

	int w, h;

protected:
	SDL_Rect source_rect_;
private:
	SDL_Texture* sprite_sheet_;
};


#endif