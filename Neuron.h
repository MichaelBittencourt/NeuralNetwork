#ifndef NEURON_H
#define NEURON_H

#include <map>
#include <vector>

class Neuron {

    private:

        std::map<unsigned int, double *> dendrites;
        std::map<unsigned int, double> weights;
        long int qtdDendrites;
        static double UNCONNECTED_DENDRITE;
        double output;
        double accumulator();
        static double sigmoid(double x);
        double (*actFunc)(double);

    public:

        Neuron();
        Neuron(double (*activationFunction)(double));
        void setActivationFunction(double (*activationFunction)(double));
        void createDendrite();
        void createDendrite(double & dendrite);
        void createDendrite(double & dendrite, double weight);
        void setDendrite(long int index, double & dendrite);
        void setWeight(long int index, double weight);
        std::vector<double> getWeights();
        void think();
        double & getOutput();
        ~Neuron();

};


#endif
