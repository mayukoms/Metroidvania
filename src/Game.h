#ifndef GAME_H_
#define GAME_H_

struct Graphics;

struct Game{	
public:
	Game();
	~Game();
	
	static int kTileSize;

private: 
	void eventLoop();
	void update(int elapsed_time);
	void draw(Graphics&);
	bool isRunning;
};

#endif // GAME_H_
