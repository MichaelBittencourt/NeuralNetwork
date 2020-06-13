#ifndef NEURON_H
#define NEURON_H

#include <map>
#include <vector>

class Neuron {

    private:

        std::map<unsigned int, double *> dendrites;
        std::map<unsigned int, double> weights;
        long int qtdDendrites;
        static const double h;
        static double UNCONNECTED_DENDRITE;
        double output;
        double dOutput;
        double lastAccumulated;
        double accumulator();
        static double sigmoid(double x);
        static double dsigmoid(double x);
        double genericDerivative();
        double (*actFunc)(double);
        double (*dActFunc)(double);

    public:

        Neuron();
        Neuron(double (*activationFunction)(double));
        Neuron(double (*activationFunction)(double), double (*derivativeActivationFunction)(double));
        void setActivationFunction(double (*activationFunction)(double));
        void setDerivativeActivationFunction(double (*derivativeActivationFunction)(double));
        void unSetDerivativeActivationFunction();
        void createDendrite();
        void createDendrite(double & dendrite);
        void createDendrite(double & dendrite, double weight);
        void setDendrite(long int index, double & dendrite);
        void setWeight(long int index, double weight);
        std::vector<double> getWeights();
        void think();
        double & getOutput();
        double & getDerivativeOutput();
        ~Neuron();

};


#endif
