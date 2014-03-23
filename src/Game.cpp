#include "game.h"
#include <SDL.h>
#include "Sprite.h"
#include "Graphics.h"

namespace{
	const int kFps = 60;
}
int Game::kTileSize = 32;

Game::Game(){
	isRunning = true;
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_ShowCursor(SDL_DISABLE);
	eventLoop();
}

Game::~Game(){
	SDL_Quit();
}

Sprite* s;

void Game::eventLoop(){
	Graphics g;

	Uint32 timeOfLastStateSwitch = SDL_GetTicks();
	Uint32 timeOfLastFrame = SDL_GetTicks();
	
	s = new Sprite("res/tommy.bmp", 0, 0, 32, 32);

	while (isRunning){

		// count the number of milliseconds since the last frame
		Uint32 timeOfThisFrame = SDL_GetTicks();
		Uint32 frameDeltaTime = timeOfThisFrame - timeOfLastFrame;


		if (frameDeltaTime < 1000 / kFps){
			continue;
		}
		timeOfLastFrame = timeOfThisFrame;

		update();
		draw(g);
	}
}

void Game::update(){
	// handle all the events
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		// if the window is being requested to close, then stop the game.
		if (e.type == SDL_QUIT) {
			isRunning = false;
		}

	}
}

void Game::draw(Graphics& g){
	s->draw(g, 320, 240);
	g.flipDisplay();
}