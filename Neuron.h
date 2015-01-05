#ifndef NEURON_H
#define NEURON_H

#include <iostream>
#include <vector>
using namespace std;

class Neuron
{
public:
	Neuron();
	~Neuron();
	vector<double> inputValues;
	vector<double> inputWeights;
	double output;
	void calculate();	
	 
};

#endif
