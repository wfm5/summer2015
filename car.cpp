#include <SDL.h>
#include <SDL_image.h>
#include "car.h"

/** This function sets the rect to the racer chosen
*@param player param is an int to determine which racer the user wants
*@return returns -1 if unsuccessful, 0 if successful 
*/
int CarData::SetRect(int player)
{
	
	if( player == NULL)
	{
		return -1;
	}
	if(player == 1)
	{
		mainCar.mCarRect->h = 64;
		mainCar.mCarRect->w = 64;
		mainCar.mCarRect->x = 896;
		mainCar.mCarRect->y = 64;
		return 1;
	}
	return -1;

}

int Accelerate()
{
	return 1;
}
int DrawCar()
{
	return 1;
}