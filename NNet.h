#ifndef NNET_H
#define NNET_H

#include <iostream>
#include <cmath>
#include "Neuron.h"

using namespace std;
class NNet
{
public:
	NNet(int input, int ouput, int layers, int neuronsPerLayer);
	~NNet();
	bool calculate(vector<double> input, vector<double> weights);
private:
	void init();
	int n_input;
	int n_output;
	int n_layers;
	int neuronsPerLayer;
	int n_neurons;
	//double *input;
	vector<double> *output;
	//double *weights;
	Neuron* neurons;
	
};
#endif
