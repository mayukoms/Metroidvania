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
	SDL_RenderPresent(gRenderer);
}

void Graphics::clear(){
	SDL_RenderClear(gRenderer);
}

// Routine for loading color keyed textures and doing all the stupid stuff that comes with it
SDL_Texture* Graphics::LoadTexture(const char* sprite_sheet)
{
	// load the image
	SDL_Surface *surface = SDL_LoadBMP(sprite_sheet);
	if (!surface) {
		return NULL;
	}

	// create a duplicate of the surface with the same pixel format as the window
	SDL_Surface *newSurface = SDL_ConvertSurfaceFormat(surface, SDL_GetWindowPixelFormat(gWindow), 0);

	// no longer need to hang on to the original image
	SDL_FreeSurface(surface);

	if (!newSurface) {
		return NULL;
	}

	// set (255,0,255) as the transparent color
	if (SDL_SetColorKey(newSurface, SDL_TRUE, SDL_MapRGB(newSurface->format, 255, 0, 255))) {
		return NULL;
	}

	// create a renderable texture from the image
	SDL_Texture *texture = SDL_CreateTextureFromSurface(gRenderer, newSurface);

	// no longer need to hang on to the converted image
	SDL_FreeSurface(newSurface);

	return texture;
}

void Graphics::RenderCopy(SDL_Texture *src, SDL_Rect *src_rect, SDL_Rect *dst_rect){
	SDL_RenderCopy(gRenderer, src, src_rect, dst_rect);
}