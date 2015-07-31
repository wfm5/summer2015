#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "game.h"


int GameData::Setup()
{
	if(SDL_Init( SDL_INIT_EVERYTHING ) < 0)
	{
		printf("SDL ErrorL %s \n", SDL_GetError() );
		return -1;
	}

	if((mWindow = SDL_CreateWindow("RacingBoom", 100, 100, 840, 540, 0)) == NULL)
	{
		printf("SDL ErrorL %s \n", SDL_GetError());
		return -1;
	}else 
	{ 
		//Initialize renderer color 
		SDL_SetRenderDrawColor( mRender, 0xFF, 0xFF, 0xFF, 0xFF ); 
		//Initialize PNG loading 
		int imgFlags = IMG_INIT_PNG; 
		if( !( IMG_Init( imgFlags ) & imgFlags ) )
		{ 
			printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() ); 
			return -1;
		} 
	}

	if((mScreenSurface = SDL_GetWindowSurface(mWindow)) == NULL)
	{
		printf("SDL ErrorL %s \n", SDL_GetError());
		return -1;
	}
	if( (game.mSurface2 = SDL_LoadBMP("assets/background.bmp")) == NULL)
	{
		printf("SDL ErrorL %s \n", SDL_GetError());
		return -1;
	}
	//if( ( (game.mTexture = loadTexture("assets/track.png")) ) == NULL)
	//{
	//	printf("SDL ErrorL %s \n", SDL_GetError());
		//return -1;
	//}
	 //Load PNG texture  
	mRender = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED); 
	if( (loadTexture( "assets/track.png" )) == NULL ) 
	{ 
		fprintf(stdout, "Failed to load texture image!\n" ); 
		return -1; 
	}

	return 0;
}
/**
 * This function loads an image at a given path name and attempts to create
 * an SDL_Texture from it.
 * @params path A file path within the project folder
 * @return An SDL_Texture if successful, NULL if not
 */
SDL_Texture *GameData::loadTexture( std::string path ) 
{ 
	
	//The final texture 
	SDL_Texture* newTexture = NULL; 
	//Load image at specified path 
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() ); 
	if( loadedSurface == NULL ) 
	{ 
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() ); 
	} else { 
		//Create texture from surface pixels 
		newTexture = SDL_CreateTextureFromSurface( mRender, loadedSurface ); 
		if( newTexture == NULL ) 
		{ 
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() ); 
			SDL_Delay(1000);
		} 
		//Get rid of old loaded surface 
		SDL_FreeSurface( loadedSurface ); 
	} 
	return newTexture; 
}

int GameData::Shutdown()
{
	//Free images
	SDL_DestroyTexture(mTexture);
	mTexture = NULL;
	//Destroy windows
	SDL_DestroyRenderer(mRender);
	SDL_FreeSurface(mSurface2);
	SDL_DestroyWindow( mWindow );
	mWindow = NULL;
	mRender = NULL;
	//Quit SDL sub systems
	IMG_Quit();
	SDL_Quit();
	return 0;
}

int GameData::Draw()
{
	SDL_UpdateWindowSurface(mWindow);
	SDL_BlitSurface(mSurface2, NULL, mScreenSurface, NULL);
	//Render texture to screen 
	SDL_RenderCopy( mRender, mTexture, NULL, NULL ); 
	//Update screen 
	SDL_RenderPresent( mRender );
	return 0;
}

int GameData::Input()
{
	SDL_Event e;
	SDL_PollEvent(&e);
	if(e.type == SDL_QUIT)
	{
		mDone = true;
	}
	else if( e.type == SDL_KEYDOWN )
	{
		//Select surfaces based on key press
		switch( e.key.keysym.sym )
		{
		case SDLK_UP:

			break;
		
		case SDLK_DOWN:
			
			break;
		
		case SDLK_LEFT:
			
			break;

		case SDLK_RIGHT:
			
			break;

		default:
			
			break;
		}
	}
	return 0;
}

int GameData::Run()
{
	//game loop
	do
	{
		Input();
		Draw();
	}while(!mDone);
	return 0;
}
