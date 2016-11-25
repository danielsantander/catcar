/********************************************************************************************************/
/*
* File: DataSource.cpp
* Author: Daniel Santander
* NetID: dsantand
* Date:
*
* Description: The  DataSource class keeps a vector of  Input objects (control inputs), in order.
*   			Likewise, the  DataSink class keeps a vector of  State  objects (state outputs), in order.
*
*/
/********************************************************************************************************/

#include "DataSource.h"

DataSource::DataSource()
{

}

// Reads in the value of the input
void DataSource::ReadInData(char* fileName)
{
	double time;
	double velocity;
	double angle;

	// open the input file
	ifstream inputFile;
	inputFile.open(fileName);

	// check if file is valid
	if (!inputFile.is_open())
	{
		cout << "Could not open input file." << endl;
	}

	// Read from file
	inputFile >> fileName;
	while (!inputFile.eof())
	{
		inputFile >> time;
		inputFile >> velocity;
		inputFile >> angle;

		// Stores input into a vector of type Input
		_dataInput.push_back(Input(velocity, angle, time));
	}

	// Close the input file
	inputFile.close();
}

// Calls function to sort the _dataInput vector
void DataSource::sort()
{
	// calls QuickSort function with appropriate size:
	QuickSort(0, _dataInput.size() - 1);
}

// Partitions the vector to prepare QuickSort function
int DataSource::partition(int i, int k)
{
	/*Initialize Variables*/
	int lo = 0;
	int hi = 0;
	int midpoint = 0;
	double pivot = 0.0;		// value to sort (input's timestamp)
	Input tempInput;
	bool isDone = false;

	/*Pick the middle element as midpoint*/
	midpoint = (i + (k - i)) / 2;

	pivot = _dataInput.at(midpoint).getTimeStamp();
	lo = i;
	hi = k;

	while (!isDone)
	{
		while (_dataInput.at(lo).getTimeStamp < pivot)
		{
			lo++;
		}

		while (_dataInput.at(hi).getTimeStamp > pivot)
		{
			hi++;
		}

		if (lo >= hi)
		{
			isDone = true;
			// Add case for if lo == hi ?
		}
		else
		{
			// Swap
			tempInput = _dataInput.at(lo);
			_dataInput.at(lo) = _dataInput.at(hi);
			_dataInput.at(hi) = tempInput;
			lo++;
			hi++;
		}
	}

	return hi;
}


void DataSource::QuickSort(int i, int k)
{
	int j = 0;
	if (i >= k)
	{
		/*Base Case: if there are 1 or 0 elements, partition is already sorted*/
		return;
	}

	j = partition(i, k);

	/* Recursively Call quicksort to sort left and right sides of the partition*/
	QuickSort(i, j);
	QuickSort(j + 1, k);

	return;
	
}

// Validates the sorted input data
bool DataSource::validate()
{
	// First element of array must equal 0
	if (_dataInput.at(0).getTimeStamp != 0.00)
	{
		return false;
	}

	for (int i = 0; i < _dataInput.size(); i++)
	{
		// tire angle rate must be between [-­0.5236, 0.5236] radians/sec
		if (_dataInput.at(i).getTireAngleRate() < MIN_TIRE_ANGLE_RATE || _dataInput.at(i).getTireAngleRate() > MAX_TIRE_ANGLE_RATE)
		{
			return false;
		}

		// velocity must be between [0, 30] m/s;
		if (_dataInput.at(i).getVelocity() < 0 || _dataInput.at(i).getVelocity() > 30)
		{
			return false;
		}

		// time values must be non­negative; and
		if (_dataInput.at(i).getTimeStamp() < 0.00)
		{
			return false;
		}
	}

	// Duration between sorted input objects must be between [5, 201] ms
	for (int i = 0; i < _dataInput.size() - 1; i++)
	{
		double duration = _dataInput.at(i + 1).getTimeStamp() - _dataInput.at(i).getTimeStamp();
		if (duration < 0.005 || duration > 0.201)
		{
			return false;
		}
	}

	return true;
}

// Returns the vector _dataInput
vector<Input> DataSource::getVector()
{
	return _dataInput;
}