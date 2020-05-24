#include"Neuron.h"

#include <cstdlib>     /* srand, rand */
#include <ctime>  /* time */
#include <cmath> /* exp */
#include <iostream>
using namespace std;

double Neuron::UNCONNECTED_DENDRITE = 0;

Neuron::Neuron() : Neuron(&Neuron::sigmoid) { } 

Neuron::Neuron(double (*activationFunction)(double)) : 
    actFunc(activationFunction),
    output(0),
    qtdDendrites(0) { 
    srand(time(nullptr));
}

void Neuron::setActivationFunction(double (*activationFunction)(double)) {
    this->actFunc = activationFunction;
}

double Neuron::accumulator() {

    double ret = 0;
    for(int i = 0; i < this->qtdDendrites; i++) {
        ret += *(this->dendrites[i]) * this->weights[i];
    }
    return ret;
}

double Neuron::sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

void Neuron::createDendrite() {
    this->createDendrite(Neuron::UNCONNECTED_DENDRITE);
}

void Neuron::createDendrite(double & dendrite) {
    this->createDendrite(dendrite, rand() % 1000 - 500);
}

void Neuron::createDendrite(double & dendrite, double weight) {
    this->dendrites[qtdDendrites] = &dendrite;
    this->weights[qtdDendrites++] = weight;
}

void Neuron::setDendrite(long int index, double & dendrite) {
    if (dendrites.find(index) != dendrites.end()) {
        dendrites[index] = &dendrite; 
    }
}

void Neuron::setWeight(long int index, double weight) {
    if (weights.find(index) != weights.end()) {
        weights[index] = weight; 
    }
}


std::vector<double> Neuron::getWeights() {
    std::vector<double> ret(qtdDendrites, 0);
    for(int i = 0; i < this->qtdDendrites; i++) {
        ret[i] = this->weights[i];
    }
    return ret;
}

void Neuron::think() {
    this->output = this->actFunc(this->accumulator());
}

double & Neuron::getOutput() {
    return this->output;
}

Neuron::~Neuron() {

}
