#include "game.h"
#include <SDL.h>
#include "Graphics.h"
#include "input.h"

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

#include "Player.h"
Player* p;

Game::~Game(){
	SDL_Quit();
	delete p;
}

void Game::eventLoop(){
	Graphics g;
	Input input;

	Uint32 timeOfLastStateSwitch = SDL_GetTicks();
	Uint32 timeOfLastFrame = SDL_GetTicks();
	
	p = new Player(g.LoadTexture("res/tommy.bmp"), 320, 240);

	while (isRunning){

		// count the number of milliseconds since the last frame
		Uint32 timeOfThisFrame = SDL_GetTicks();
		Uint32 frameDeltaTime = timeOfThisFrame - timeOfLastFrame;


		if (frameDeltaTime < 1000 / kFps){
			continue;
		}

		// handle all the events
		input.beginNewframe();
		SDL_Event e;
		while (SDL_PollEvent(&e))
		{
			// if the window is being requested to close, then stop the game.
			if (e.type == SDL_QUIT) {
				isRunning = false;
			}
			switch (e.type){
				case SDL_KEYDOWN:
					input.keyDownEvent(e);
					break;
				case SDL_KEYUP:
					input.keyUpEvent(e);
					break;
				default:
					break;
			}
		}

		p->movePlayer(input);

		Uint32 elapsed_time = timeOfThisFrame - timeOfLastFrame;
		timeOfLastFrame = timeOfThisFrame;

		update(elapsed_time);
		draw(g);
	}
}

void Game::update(int elapsed_time){
	p->update(elapsed_time);
}

void Game::draw(Graphics& g){
	g.clear();
	p->draw(g, p->x_pos_, p->y_pos_);
	g.flipDisplay();
}