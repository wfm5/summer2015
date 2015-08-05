#ifndef __CAR_H__
#define __CAR_H__
/**
*The game's class for all cars
*/
class CarData
{
	bool isMoving;
	int mSpeed;

public:
	SDL_Texture *mCarTexture;
	SDL_Rect *mCarRect;
	int SetRect(int player);
	int Accelerate();
	int DrawCar();
};

extern CarData mainCar;
#endif