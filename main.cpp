#include <SDL.h>
#include <string>
#include "game.h"
#include "car.h"

GameData game;
CarData mainCar;

int main(int argv, char *args[])
{
	if(game.Setup() < 0)
		return -1;
	game.Run();
	game.Shutdown();
	return 0;
}