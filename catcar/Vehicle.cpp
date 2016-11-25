/********************************************************************************************************/
/*
* File: Vehicle.cpp
* Author: Daniel Santander
* NetID: dsantand
* Date:
*
* Description: The  Vehicle keeps its own state, receives a control input, and updates its state
*
*/
/********************************************************************************************************/

#include "Vehicle.h"

// constructs a new Vehicle object with the default State value
Vehicle::Vehicle()
{
	// Initial State values:
	this->_state.setXPos = 0.0;
	this->_state.setYPos = 0.0;
	this->_state.setTireAngle = 0.0;
	this->_state.setHeading = 0.0;
}

// executes the Vehicle for the duration specified
// this method does not do any correctness checking on values in u
void Vehicle::stateUpdate(Input u, double duration)
{
	// Updating state
	this->_state.setXPos(_state.getXPos + duration * u.getVelocity * cos(this->_state.getTireAngle) * cos(this->_state.getHeading));
	this->_state.setYPos(_state.getYPos + duration * u.getVelocity * cos(this->_state.getTireAngle) * sin(this->_state.getHeading));
	this->_state.setTireAngle(_state.getTireAngle + duration * u.getTireAngleRate);
	this->_state.setHeading(_state.getHeading + duration * u.getVelocity * (1 / L) * sin(this->_state.getTireAngle));
	this->_state.setTimeStamp(_state.getTimeStamp + duration);
}

// Returns value for _state
State Vehicle::getState() const
{
	return _state;
}