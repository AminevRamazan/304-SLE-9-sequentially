#ifndef MATRIX_IO_H
#define MATRIX_IO_H

#include <vector>
#include <string>


int readMatrixFromFile(const std::string& filename, std::vector<std::vector<double>>& A, int n);
void printMatrix(const std::vector<std::vector<double>>& A, int m);
void printVector(const std::vector<double>& vec, int m);
double f(int k, int n, int i, int j);
void initializeMatrix(std::vector<std::vector<double>>& A, int k, int n);

#endif
