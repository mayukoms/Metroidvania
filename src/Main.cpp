#include <iostream>
#include <SDL.h>
#include <string.h>
#include <stdio.h>

SDL_Window *gWindow;
SDL_Renderer *gRenderer;

int main(int argc, char **argv){

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	// Create window and renderer
	if (SDL_CreateWindowAndRenderer(640, 480, 0, &gWindow, &gRenderer)) {
		printf("SDL_CreateWindowAndRenderer: %s\n", SDL_GetError());
		return -1;
	}

	Uint32 timeOfLastStateSwitch = SDL_GetTicks();

	Uint32 timeOfLastFrame = SDL_GetTicks();

	// begin main loop
	int isGameRunning = 1;
	while (isGameRunning)
	{
		// count the number of milliseconds since the last frame
		Uint32 timeOfThisFrame = SDL_GetTicks();
		Uint32 frameDeltaTime = timeOfThisFrame - timeOfLastFrame;

		if (frameDeltaTime < 1000/60){
			continue;
		}
		timeOfLastFrame = timeOfThisFrame;

		// handle all the events
		SDL_Event e;
		while (SDL_PollEvent(&e))
		{
			// if the window is being requested to close, then stop the game.
			if (e.type == SDL_QUIT) {
				isGameRunning = 0;
			}

			// clear the screen
			if (SDL_RenderClear(gRenderer)) {
				printf("SDL_RenderClear: %s\n", SDL_GetError());
				return -1;
			}

			// flip the display
			SDL_RenderPresent(gRenderer);

		}
	}
	
	// throw everything away
	SDL_Quit();

	return 0;
}