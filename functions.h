#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>

void Product(const std::vector<std::vector<double>>& A, const std::vector<double>& x, std::vector<double>& Ax, const int n);
void Difference(const std::vector<double>& a, const std::vector<double>& b, std::vector<double>& c, const int n);
double Norm(const std::vector<double>& a, const int n);
double calculateResidualNorm(const std::vector<std::vector<double>>& A, const std::vector<double>& x, const std::vector<double>& b, const int n);
double calculateNormError(const std::vector<double>& x, const int n);

#endif
