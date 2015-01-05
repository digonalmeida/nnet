#include "NNet.h"
#include <cmath>
NNet::NNet(int n_input, int n_ouput, int layers, int neuronsPerLayer)
{
	this->n_input = n_input;
	this->n_output = n_output;
	this->n_layers = layers;
	this->neuronsPerLayer = neuronsPerLayer;
	init();
}

NNet::~NNet()
{
	
}

void
NNet::init()
{
	int totalLayerNeurons = n_layers*neuronsPerLayer;
	n_neurons = n_input + n_output + totalLayerNeurons;
	neurons = new Neuron*[n_neurons];
}

bool NNet::calculate(vector<double> input, vector<double> weights)
{
	int arrayPos = 0;
	for(int i=0; i< n_neurons; i++)
	{
		if(i<n_input)
		{
			neurons[i].inputValues.push_back( input[arrayPos]);
			neurons[i].inputWeights.push_back(weights[arrayPos++]);
		}
		else
		{
			int layerId = floor((double)(i-n_input) /(double) neuronsPerLayer);
			if(layerId == 0)
			{
				for(int j=0; j< n_input; j++)
				{
					neurons[i].inputValues.push_back(neurons[j].output);
					neurons[i].inputWeights.push_back(weights[arrayPos++]);
				}
			}
			else
			{
				for(int j=n_input+((layerId-1)*neuronsPerLayer); j< n_input+ (layerId * neuronsPerLayer); j++)
				{
					neurons[i].inputValues.push_back(neurons[j].output);
					neurons[i].inputWeights.push_back(weights[arrayPos++]);
				}
			}
		}
		neurons[i].calculate();
		
		
	}
}
