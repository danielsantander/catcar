/********************************************************************************************************/
/*
* File: DataSource.h
* Author: Daniel Santander
* NetID: dsantand
* Date:
*
* Description: The  DataSource class keeps a vector of  Input objects (control inputs), in order. 
*   			Likewise, the  DataSink class keeps a vector of  State  objects (state outputs), in order.
*
*/
/********************************************************************************************************/

#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Input.h"

using namespace std;


class DataSource{

private:
	vector<Input> _dataInput;    //setting vector for Input
	
public:
	//vector <Input> _dataInput;

	DataSource();    //specify constructor

	void ReadInData(char* fileName);    //reads in the values of the input

	void sort();
	int partition(int i, int k);
	void QuickSort(int i, int k);

	bool validate();

	vector<Input> getVector();

	
};


#endif /*DATASOURCE_H*/