#include "ActivationFunctions.h"
#include <cmath> /* exp */
#include <string>

using std::string;

const double ActivationFunctions::h = 0.000001;
const string ActivationFunctions::SIGMOID = "sigmoid";

double ActivationFunctions::sum(std::vector<double> vect) {
    double sum = 0;
    for(unsigned int i = 0; i < vect.size(); i++) {
        sum += vect[i];
    }
    return sum;
}

double ActivationFunctions::sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

double ActivationFunctions::d_sigmoid(double x) {
    return x * (1 - x);
}

double ActivationFunctions::elu(double x) {
    return 0;
}

double ActivationFunctions::d_elu(double x) {
    return 0;
}
        
double ActivationFunctions::relu(double x) {
    return 0;
}

double ActivationFunctions::d_relu(double x) {
    return 0;
}

double ActivationFunctions::genericDerivative(double x, double (*activationFunction)(double)) {
    return (activationFunction(x + h) - activationFunction(x)) / h;
}

double ActivationFunctions::sigmoid(std::vector<double> vect) {
    double x = sum(vect);
    return 1 / (1 + exp(-x));
}

double ActivationFunctions::d_sigmoid(std::vector<double> vect) {
    double x = sum(vect);
    return x * (1 - x);
}

double ActivationFunctions::elu(std::vector<double> vect) {
    return 0;
}

double ActivationFunctions::d_elu(std::vector<double> vect) {
    return 0;
}

double ActivationFunctions::relu(std::vector<double> vect) {
    return 0;
}

double ActivationFunctions::d_relu(std::vector<double> vect) {
    return 0;
}

double ActivationFunctions::genericDerivative(std::vector<double> vect, double (*activationFunction)(double)) {
    double x = sum(vect);
    return (activationFunction(x + h) - activationFunction(x)) / h;
}
