#include "Graphics.h"
#include "SDL.h"

namespace{
	const int kScreenWidth = 640;
	const int kScreenHeight = 480;
}

Graphics::Graphics(){
	SDL_CreateWindowAndRenderer(kScreenWidth, kScreenHeight, 0, &gWindow, &gRenderer);
}

Graphics::~Graphics(){
	SDL_DestroyWindow(gWindow);
	SDL_DestroyRenderer(gRenderer);
}

void Graphics::flipDisplay(){
	SDL_UpdateWindowSurface(gWindow);
}

void Graphics::blitSurface(SDL_Surface *src, SDL_Rect *src_rect, SDL_Rect *dst_rect){
	SDL_BlitSurface(src, src_rect, SDL_GetWindowSurface(gWindow), dst_rect);
}