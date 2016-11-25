/********************************************************************************************************/
/*
* File: Vehicle.h
* Author: Daniel Santander
* NetID: dsantand
* Date:
*
* Description: The  Vehicle keeps its own state, receives a control input, and updates its state
*
*/
/********************************************************************************************************/



#ifndef VEHICLE_H
#define VEHICLE_H

#include "State.h"
#include "Input.h"

// wheelbase length in meters
#define L 2.6187

class Vehicle {
private:
	State _state;				// the current state of the vehicle
	void setState(State x);		// sets the value for _state

public:
	// constructs a new Vehicle object with the default State value
	Vehicle();
	
	// executes the Vehicle for the duration specified
	// this method does not do any correctness checking on values in u
	void stateUpdate(Input u, double duration);

	State getState() const; // gets the value for _state
};

#endif // VEHICLE_H
