#include "pc.h"

#include <GLFW/glfw3.h>

/**
	Return health of player
*/
int PC::getHealth(void)
{
	return health;
}

/**
	Return X location
*/
float PC::getX(void)
{
	return x;
}

/**
	Return y location
*/
float PC::getY(void)
{
	return y;
}

/**
	Start tank moving forward
*/
void PC::startMoving(void)
{
	moving = true;
}

/**
	Stop tank moving forward
*/
void PC::stopMoving(void)
{
	moving = false;
}

/**
	Player's update function
*/
void PC::update()
{

}

/**
	<Insert obvious comment here>
*/
void PC::draw()
{
	glBegin(GL_QUADS);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
	glEnd();
}
