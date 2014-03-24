#ifndef GRAPHICS_H_
#define GRAPHICS_H_

struct SDL_Texture;
struct SDL_Window;
struct SDL_Renderer;
struct SDL_Rect;

struct Graphics{
	Graphics();
	~Graphics();

	void RenderCopy(SDL_Texture *src, SDL_Rect *src_rect, SDL_Rect *dst_rect);
	void flipDisplay();
	void clear();
	SDL_Texture* LoadTexture(const char* sprite_sheet);

private:
	SDL_Window *gWindow;
	SDL_Renderer *gRenderer;
};

#endif