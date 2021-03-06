#ifndef __GAME_H__
#define __GAME_H_

/**
 * The game's driver class
*/
class GameData
{
	int mGameState; //change to enum /**< The state of game */
	bool mChange;	/**< Check if something changed */
	bool mDone;		/**< Has the game ended */
	SDL_Surface *mScreenSurface;
	SDL_Surface *mSurface2;
	SDL_Window *mWindow;
	SDL_Renderer *mRender;
	SDL_Texture *mTexture;
	//Private methods
	int Input();
	int Update();
	int Draw();
	
public:

	SDL_Texture *loadTexture(std::string path);
	int Setup();
	int DrawBackground();
	int Run();
	int Shutdown();
};

extern GameData game;
#endif //__GAME_H
