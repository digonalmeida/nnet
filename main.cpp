#include <iostream>
#include "Neuron.h"

using namespace std;

int main()
{
	Neuron* n = new Neuron();
	for(int i=0;i<10;i++)
	{
		n->inputValues.push_back(1);
		n->inputWeights.push_back(1);
	}
	n->calculate();
	cout << "resultado: " << n->output;
}
