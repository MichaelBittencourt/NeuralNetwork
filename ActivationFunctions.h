#ifndef ACTIVATION_FUNCTIONS_H
#define ACTIVATION_FUNCTIONS_H

#include <vector>
#include <string>

using std::string;

class ActivationFunctions {

    private:

        static double sum(std::vector<double> vect);
        static const double h;

    public:

        static const string SIGMOID;

        static double sigmoid(double x);

        static double d_sigmoid(double x);

        static double elu(double x);

        static double d_elu(double x);
        
        static double relu(double x);

        static double d_relu(double x);

        static double genericDerivative(double x, double (*activationFunction)(double));

        static double sigmoid(std::vector<double> vect);
        
        static double d_sigmoid(std::vector<double> vect);

        static double elu(std::vector<double> vect);

        static double d_elu(std::vector<double> vect);
        
        static double relu(std::vector<double> vect);

        static double d_relu(std::vector<double> vect);

        static double genericDerivative(std::vector<double> vect, double (*activationFunction)(double));

};

#endif
