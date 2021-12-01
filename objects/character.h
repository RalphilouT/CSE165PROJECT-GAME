//CSE165 oHNO3 game
//Tyler Armstrong, Ralphilou Tatoy, Sy Loc, Vedaant Vyas
//Nov 17, 2021
#ifndef CHARACTER_FILE_H
#define CHARACTER_FILE_H
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
//#include "imageloader.cpp"
#include <SDL.h>
#include <SDL_image.h>
//#include "sdlcreatewindow.cpp"
//#include <createSDLWIN.h>
//#include "LTexture.h"
//LTexture gDotTexture;
class character
{
    public:
        //The dimensions of the dot
        static const int DOT_WIDTH = 100;
        static const int DOT_HEIGHT = 100;

        //Maximum axis velocity of the dot
        static const int DOT_VEL = 10;

        //Initializes the variables
        character();

        //Takes key presses and adjusts the dot's velocity
        void handleEvent(SDL_Event&e);
		int defaultX;
        //Moves the dot
        void move();
		//friend BadCloud;
        //Shows the dot on the screen
        void render();
		//Get the position of character in x direction
		int getXPOSC();
		//Get the position of character in y direction
		int getYPOSC();
		//void detectingCLOUDATTACK(BadCloud&ref);
    private:
        //The X and Y offsets of the dot
        int mPosX, mPosY;

        //The velocity of the dot
        int mVelX, mVelY;
};
int character::getYPOSC()
{
	return mPosY;
}
int character::getXPOSC()
{
	return mPosX;
}
character::character()
{
	//Initialize the offsets
	mPosX = 300;
	mPosY = 311;
	defaultX = mPosX;
	//Initialize the velocity
	mVelX = 0;
	mVelY = 0;
}
//void character::render()
//{
//	//Show the dot
//	gDotTexture.render(mPosX, mPosY);
//}
void character::handleEvent(SDL_Event& e)
{
	//If a key was pressed
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: mVelY -= DOT_VEL; break;
		case SDLK_DOWN: mVelY += DOT_VEL; break;
		case SDLK_LEFT: mVelX -= DOT_VEL; break;
		case SDLK_RIGHT: mVelX += DOT_VEL; break;
		}
	}
	//If a key was released
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: mVelY += DOT_VEL; break;
		case SDLK_DOWN: mVelY -= DOT_VEL; break;
		case SDLK_LEFT: mVelX += DOT_VEL; break;
		case SDLK_RIGHT: mVelX -= DOT_VEL; break;
		}

	}
}
void character::move()
{
	//Move the dot left or right
	mPosX += mVelX;

	//If the dot went too far to the left or right
	if ((mPosX < 0) || (mPosX + DOT_WIDTH > SCREEN_WIDTH))
	{
		//Move back
		mPosX -= mVelX;
	}

	//Move the dot up or down
	mPosY += mVelY;

	//If the dot went too far up or down
	if ((mPosY < 0) || (mPosY + DOT_HEIGHT > SCREEN_HEIGHT))
	{
		//Move back
		mPosY -= mVelY;
	}
}
//void character::render()
//{
//	//Show the dot
//	gDotTexture.render(mPosX, mPosY);
//}
#endif