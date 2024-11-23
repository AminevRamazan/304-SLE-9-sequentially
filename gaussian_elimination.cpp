#include "gaussian_elimination.h"
#include <cmath>
#include <algorithm>

int gaussianElimination(const std::vector<std::vector<double>>& A, const std::vector<double>& b, std::vector<double>& x, const int n) {
    x.resize(n);

    // Копирование данных
    std::vector<std::vector<double>> A_copy = A;
    std::vector<double> b_copy = b;

    for (int i = 0; i < n; ++i) {
        // Поиск главного элемента в строке
        int maxRow = i;
        for (int k = i + 1; k < n; ++k) {
            if (std::fabs(A_copy[k][i]) > std::fabs(A_copy[maxRow][i])) {
                maxRow = k;
            }
        }
        std::cout << i << " " << maxRow << std::endl;
        if (std::fabs(A_copy[maxRow][i]) < 1e-19) {
            return 0;
        }

        // Перестановка строк
        std::swap(A_copy[i], A_copy[maxRow]);
        std::swap(b_copy[i], b_copy[maxRow]);
        double factor = 1 / A_copy[i][i];
        b_copy[i] = factor * b_copy[i];
        for (int j = i; j < n; ++j) {
            A_copy[i][j] = factor * A_copy[i][j];
        }

        // Прямой ход метода Гаусса
        for (int k = i + 1; k < n; ++k) {
            double factor = A_copy[k][i] / A_copy[i][i];
            b_copy[k] -= factor * b_copy[i];
            for (int j = i; j < n; ++j) {
                A_copy[k][j] -= factor * A_copy[i][j];
            }
        }
    }

    // Обратный ход метода Гаусса
    for (int i = n - 1; i >= 0; --i) {
        x[i] = b_copy[i] / A_copy[i][i];
        for (int k = i - 1; k >= 0; --k) {
            b_copy[k] -= A_copy[k][i] * x[i];
        }
    }
    return 1;
}
