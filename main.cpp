#include<iostream>
#include<vector>
#include"Neuron.h"
#define QTD_NEURONS 5000

int main(void) {

    double input[] = {1, 3, 5, 3, 2};
    Neuron neuron[QTD_NEURONS];
    Neuron neuronFinal;
    std::cout << "neurons created! " << std::endl;
    for(int i = 0; i < QTD_NEURONS; i++) {
        for(int j = 0; j < 5; j++) {
            neuron[i].createDendrite(input[j]);
        }
        neuronFinal.createDendrite(neuron[i].getOutput());
        neuron[i].think();
    }
    neuronFinal.think();
    std::cout << "neuronFinal Output: " << neuronFinal.getOutput() << std::endl;
    std::vector<double> weightsFinal = neuronFinal.getWeights();
    /*std::cout << "neuronFinal Wights: " << std::endl;
    for(int i = 0; i < 500; i++) {
        std::cout << "Weight[" << i << "] = " << weights[i] << std::endl;
    }
    */
    return 0;

}


