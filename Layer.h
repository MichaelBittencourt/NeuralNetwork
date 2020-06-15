#ifndef LAYER_H
#define LAYER_H

#include "Neuron.h"
#include <map>
#include <string>

using std::string;

class Layer {

    private:

    double (*actFunc)(double);
    double (*d_actFunc)(double);
    string layerName = "layer";
    unsigned int amountNeurons;

    public:

        std::map<unsigned int, Neuron *> neurons;
        std::map<unsigned int, double *> outputs;

        long qtdNeurons;
        static const string STD_LAYER_NAME;

        Layer(const long & qtdNeurons, const string & activation, const string & name);
        Layer(const long & qtdNeurons, const string & activation);
        Layer(const long & qtdNeurons, double (*activation)(double), double (*derivativeActivation)(double), const string & name);
        Layer(const long & qtdNeurons, double (*activation)(double), const string & name);
        Layer(const long & qtdNeurons, double (*activation)(double));
        Layer(const long & qtdNeurons, double (*activation)(double), double (*derivativeActivation)(double));
        Layer(const long & qtdNeurons);
        Layer();

        virtual void createNeurons(long qtdNeurons) const;
        virtual void createNeurons(long qtdNeurons, double (*activation)(double), double (*derivativeActivation)(double)) const;
        virtual void createNeurons(std::vector<std::vector<double> > weights) const;
        virtual void createNeurons(std::vector<std::vector<double> > weights, double (*activation)(double), double (*derivativeActivation)(double)) const;
        virtual std::vector<double*> getOutputs() const;
        virtual void setInputs(std::vector<double*> inputs) const;
        virtual std::vector<std::vector<double> > getWeights() const;
        virtual void setWeights(std::vector<std::vector<double> > weights) const;

};

#endif
