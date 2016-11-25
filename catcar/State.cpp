/********************************************************************************************************/
/*
* File: State.cpp
* Author: Daniel Santander
* NetID: dsantand
* Date:
*
* Description: The  State class is similar to Input.
*				However, it does ensure that tire angle values and heading values stay within the
*				designated ranges if the setters for the class are called.
*
*/
/********************************************************************************************************/
#include "State.h"

// constructs an empty State object
State::State(double x1, double x2, double x3, double x4, double timestamp)
{
	this->_xpos = x1;
	this->_ypos = x2;
	this->_tire_angle = x3;
	this->_heading = x4;
	this->_timestamp = timestamp;
}

// Default Constructor:
State::State()
{

}

// Returns _xpos
double State::getXPos() const
{
	return _xpos;
}

// Sets _xpos
void State::setXPos(double xpos)
{
	this->_xpos = xpos;
}

// Returns _ypos
double State::getYPos() const
{
	return _ypos;
}

// Sets _ypos
void State::setYPos(double ypos)
{
	this->_ypos = ypos;
}

// Returns _tire_angle
double State::getTireAngle() const
{
	return _tire_angle;
}

// Sets _tire_angle
void State::setTireAngle(double angle)
{
	this->_tire_angle = angle;
}

// Returns _heading
double State::getHeading() const
{
	return _heading;
}

// Sets _heading
void State::setHeading(double heading)
{
	this->_heading = heading;
}

// Returns _timestamp
double State::getTimeStamp() const
{
	return _timestamp;
}

// Sets _timestamp
void State::setTimeStamp(double timestamp)
{
	this->_timestamp = timestamp;
}