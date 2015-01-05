#include "Neuron.h"

Neuron::Neuron(){

};

Neuron::~Neuron()
{
	
}

void Neuron::calculate()
{
	double sum = 0;
	double weightSum = 0;
	for(int i=0;i<inputValues.size();i++)
	{
		sum += inputValues[i] * inputWeights[i];
		weightSum += inputWeights[i];
	}
	output += sum/weightSum;
}
