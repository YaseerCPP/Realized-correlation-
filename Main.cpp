#include <iostream>
#include <vector>
#include <cmath>

// Function to calculate the mean of a vector
double mean(const std::vector<double>& data) {
    double sum = 0.0;
    for (double value : data) {
        sum += value;
    }
    return sum / data.size();
}

// Function to calculate the covariance of two vectors
double covariance(const std::vector<double>& data1, const std::vector<double>& data2, double mean1, double mean2) {
    double cov = 0.0;
    for (size_t i = 0; i < data1.size(); ++i) {
        cov += (data1[i] - mean1) * (data2[i] - mean2);
    }
    return cov / (data1.size() - 1); // Sample covariance
}

// Function to calculate the variance of a vector
double variance(const std::vector<double>& data, double mean) {
    double var = 0.0;
    for (double value : data) {
        var += (value - mean) * (value - mean);
    }
    return var / (data.size() - 1); // Sample variance
}

// Function to calculate the realized correlation between two assets
double realizedCorrelation(const std::vector<double>& returns1, const std::vector<double>& returns2) {
    if (returns1.size() != returns2.size() || returns1.size() < 2) {
        std::cerr << "Error: Vectors must be of the same size and contain at least two elements." << std::endl;
        return 0.0;
    }
    
    double mean1 = mean(returns1);
    double mean2 = mean(returns2);
    
    double cov = covariance(returns1, returns2, mean1, mean2);
    double var1 = variance(returns1, mean1);
    double var2 = variance(returns2, mean2);
    
    return cov / (std::sqrt(var1) * std::sqrt(var2));
}

int main() {
    // Example data: returns of two assets
    std::vector<double> returns1 = {0.01, 0.02, -0.01, 0.03, 0.02};
    std::vector<double> returns2 = {0.02, 0.01, 0.00, 0.04, 0.01};
    
    double correlation = realizedCorrelation(returns1, returns2);
    
    std::cout << "Realized Correlation: " << correlation << std::endl;
    
    return 0;
}
