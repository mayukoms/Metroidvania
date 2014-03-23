#ifndef GRAPHICS_H_
#define GRAPHICS_H_

struct SDL_Surface;
struct SDL_Window;
struct SDL_Renderer;
struct SDL_Rect;

struct Graphics{
	Graphics();
	~Graphics();

	void blitSurface(SDL_Surface *src, SDL_Rect *src_rect, SDL_Rect *dst_rect);
	void flipDisplay();

private:
	SDL_Window *gWindow;
	SDL_Renderer *gRenderer;
};

#endif