#ifndef ANIMATED_SPRITE_H_
#define ANIMATED_SPRITE_H_

#include "Sprite.h"

class AnimatedSprite : public Sprite{

public:
	AnimatedSprite(SDL_Texture* texture, int source_x, int source_y, int width, int height, int fps, int num_frames);

	void update(int elapsed_time_ms);

private:
	const int frame_time_;
	const int num_frames_;
	int current_frame_;
	int elapsed_time_;
};


#endif