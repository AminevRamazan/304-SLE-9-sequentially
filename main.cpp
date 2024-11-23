#include <iostream>
#include <chrono>
#include "matrix_io.h"
#include "gaussian_elimination.h"
#include "functions.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 4 || argc > 5) {
        cerr << "Usage: " << argv[0] << " n m k filename" << endl;
        return EXIT_FAILURE;
    }

    int n = stoi(argv[1]);       // Размерность матрицы
    int m = stoi(argv[2]);       // Количество выводимых значений
    int k = stoi(argv[3]);       // Номер формулы или 0 для чтения из файла

    if (m > n) {
        std::cerr << "Ошибка: Количество выводимых значений больше размерности матрицы " << std::endl;
        return 0;
    }

    int err = 0;
    vector<vector<double>> A;
    vector<double> b, x;
    A.resize(n, vector<double>(n));
    b.resize(n);

    // Инициализация матрицы
    if (k == 0) {
        string filename = argv[4];   // Имя файла
        err = readMatrixFromFile(filename, A, n);
        if (!err) {
            std::cerr << "Ошибка: Не удалось открыть файл " << filename << std::endl;
            return err;
        }
    }
    else {
        initializeMatrix(A, k, n);
    }

    cout << "Исходная матрица A:" << endl;
    printMatrix(A, m);

    // Построение вектора b
    for (int i = 0; i < n; i++) {
        double sum_value = 0.0;
        for (int k = 0; (2 * k + 1) < n; k++) {
            sum_value += A[i][2 * k + 1];
        }
        b[i] = sum_value;
    }

    cout << "Правая часть b:" << endl;
    printVector(b, m);

    // Запуск таймера
    auto start = chrono::high_resolution_clock::now();

    // Решение системы методом Гаусса
    err = gaussianElimination(A, b, x, n);
    if (!err) {
        std::cerr << "Ошибка: Матрица вырождена " << std::endl;
        return err;
    }

    // Остановка таймера
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;

    // Вывод решения
    cout << "Решение x:" << endl;
    printVector(x, m);

    // Вычисление и вывод нормы невязки
    double residualNorm = calculateResidualNorm(A, x, b, n);
    cout << "Норма невязки: " << scientific << residualNorm << endl;

    // Вычисление и вывод нормы погрешности
    double NormError = calculateNormError(x, n);
    cout << "Норма погрешности: " << scientific << NormError << endl;

    // Вывод времени выполнения
    cout << "Время решения: " << elapsed.count() << " секунд" << endl;

    return 0;
}
