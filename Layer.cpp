#include "Layer.h"
#include "ActivationFunctions.h"

const string Layer::STD_LAYER_NAME = "layer";

Layer::Layer(const long & qtdNeurons, const string & activation, const string & name) :
    amountNeurons(qtdNeurons),
    layerName(name)
{
    if (activation == ActivationFunctions::SIGMOID) {
        this->actFunc = ActivationFunctions::sigmoid;
        this->d_actFunc = ActivationFunctions::d_sigmoid;
    }
    
    this->createNeurons(qtdNeurons, this->actFunc, this->d_actFunc);
}

Layer::Layer(const long & qtdNeurons, const string & activation) :
    Layer(qtdNeurons, activation, Layer::STD_LAYER_NAME) { }

Layer::Layer(const long & qtdNeurons, double (*activation)(double), double (*derivativeActivation)(double), const string & name) :
    amountNeurons(qtdNeurons),
    actFunc(activation),
    d_actFunc(derivativeActivation),
    layerName(name)
{
    this->createNeurons(qtdNeurons, this->actFunc, this->d_actFunc);
}

Layer::Layer(const long & qtdNeurons, double (*activation)(double), const string & name) :
    Layer(qtdNeurons, activation, nullptr, name) { }

Layer::Layer(const long & qtdNeurons, double (*activation)(double)) :
    Layer(qtdNeurons, activation, nullptr, Layer::STD_LAYER_NAME) { }

Layer::Layer(const long & qtdNeurons, double (*activation)(double), double (*derivativeActivation)(double)) :
    Layer(qtdNeurons, activation, derivativeActivation, Layer::STD_LAYER_NAME) { }

Layer::Layer(const long & qtdNeurons) :
    Layer(qtdNeurons, ActivationFunctions::sigmoid) { }

Layer::Layer() :
    Layer(0) { }


void Layer::createNeurons(long qtdNeurons) const {

}

void Layer::createNeurons(long qtdNeurons, double (*activation)(double), double (*derivativeActivation)(double)) const {

}

void Layer::createNeurons(std::vector<std::vector<double> > weights) const {

}

void Layer::createNeurons(std::vector<std::vector<double> > weights, double (*activation)(double), double (*derivativeActivation)(double)) const {

}

std::vector<double*> Layer::getOutputs() const {

}

void Layer::setInputs(std::vector<double*> inputs) const {

}

std::vector<std::vector<double> > Layer::getWeights() const {

}

void Layer::setWeights(std::vector<std::vector<double> > weights) const {

}
