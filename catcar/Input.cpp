/********************************************************************************************************/
/*
* File: Input.cpp
* Author: Daniel Santander
* NetID: dsantand
* Date:
*
* Description: The  Input class holds the values for the u variables used in the kinematic model.
*			   Its interface is included on Piazza as a resource for this Project.
*/
/********************************************************************************************************/


#include "Input.h"

// constructs a new Input object with these initial values
Input::Input(double vel, double tireAngleRate, double timestamp)
{
	this->_velocity = vel;
	this->_tire_angle_rate = tireAngleRate;
	this->_timestamp = timestamp;
}

// Default Constructor for class Input
Input::Input(){

}

// Returns _velocity
double Input::getVelocity() const
{
	return _velocity;
}

// Sets _velocity
void Input::setVelocity(double vel)
{
	this->_velocity = vel;
}

// Returns _tire_angle_rate
double Input::getTireAngleRate() const
{
	return _tire_angle_rate;
}

// Sets _tire_angle_rate
void Input::setTireAngleRate(double angle)
{
	this->_tire_angle_rate = angle;
}

// Gets _timestamp
double Input::getTimeStamp() const{
	return _timestamp;
}

// Sets _timestamp
void Input::setTimeStamp(double timestamp){
	this->_timestamp = timestamp;
}