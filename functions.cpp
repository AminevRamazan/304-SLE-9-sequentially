#include "functions.h"
#include <cmath>

void Product(const std::vector<std::vector<double>>& A, const std::vector<double>& x, std::vector<double>& Ax, const int n) {
    Ax.resize(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            Ax[i] += A[i][j] * x[j];
        }
    }
}

void Difference(const std::vector<double>& a, const std::vector<double>& b, std::vector<double>& c, const int n) {
    c.resize(n);
    for (int i = 0; i < n; ++i) {
        c[i] = a[i] - b[i];
    }
}

double Norm(const std::vector<double>& a, const int n) {
    double norm = 0;
    for (int i = 0; i < n; ++i) {
        norm += a[i] * a[i];
    }
    return norm;
}

double calculateResidualNorm(const std::vector<std::vector<double>>& A, const std::vector<double>& x, const std::vector<double>& b, const int n) {
    std::vector<double> Ax(n, 0.0);
    std::vector<double> c(n, 0.0);
    double norm_b = 0.0, norm_residual = 0.0;
    Product(A, x, Ax, n);
    Difference(Ax, b, c, n);
    norm_residual = Norm(c, n);
    norm_b = Norm(b, n);
    return std::sqrt(norm_residual) / std::sqrt(norm_b);
}

double calculateNormError(const std::vector<double>& x, const int n) {
    double norm = 0.0;
    std::vector<double> c(n, 0.0);
    std::vector<double> d(n, 0.0);
    for (int k = 0; k < n; k++) {
        c[k] = k % 2;
    }
    Difference(x, c, d, n);
    norm = Norm(d, n);
    return std::sqrt(norm);
}