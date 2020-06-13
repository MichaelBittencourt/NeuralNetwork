#include"Neuron.h"

#include <cstdlib> /* srand, rand */
#include <ctime>  /* time */
#include <cmath> /* exp */
#include <iostream>

//TODO update Activation Function to use all dendrites as a parameter
using namespace std;

double Neuron::UNCONNECTED_DENDRITE = 0;
const double Neuron::h = 0.000001;

Neuron::Neuron() : Neuron(&Neuron::sigmoid, &Neuron::dsigmoid) { } 

Neuron::Neuron(double (*activationFunction)(double)) : 
    Neuron::Neuron(activationFunction, nullptr) { }

Neuron::Neuron(double (*activationFunction)(double), double (*derivativeActivationFunction)(double)) : 
    actFunc(activationFunction),
    dActFunc(derivativeActivationFunction),
    output(0),
    dOutput(0),
    qtdDendrites(0),
    lastAccumulated(0)
{
    srand(time(nullptr));
}

void Neuron::setActivationFunction(double (*activationFunction)(double)) {
    this->actFunc = activationFunction;
}

void Neuron::setDerivativeActivationFunction(double (*derivativeActivationFunction)(double)) {
    this->dActFunc = derivativeActivationFunction;
}

void Neuron::unSetDerivativeActivationFunction() {
    this->dActFunc = nullptr;
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

//TODO Adjust Derivative Function
double Neuron::dsigmoid(double x) {
    return x * (1 - x);
}

//TODO Adjust Derivative Function
double Neuron::genericDerivative() {
    return (this->actFunc(this->lastAccumulated + h) - this->output) / h;
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
    this->lastAccumulated = this->accumulator();
#ifdef DEBUG
    std::cout << "The last accumulated: " << this->lastAccumulated << std::endl;
#endif
    this->output = this->actFunc(this->lastAccumulated);
    this->dOutput = this->dActFunc ? this->dActFunc(this->lastAccumulated) : this->genericDerivative();
}

double & Neuron::getOutput() {
    return this->output;
}

double & Neuron::getDerivativeOutput() {
    return this->dOutput;
}

Neuron::~Neuron() {

}
