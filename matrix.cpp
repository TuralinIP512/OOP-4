#include "matrix.h"
#include <iostream>
#include <random>
#include <stdexcept>

// Конструктор по умолчанию
matrix::matrix() : rows_(0), cols_(0), data_(nullptr) {}

// Конструктор квадратной матрицы (единичная матрица)
matrix::matrix(int x) : rows_(x), cols_(x), data_(nullptr) {
    if (x < 0) {
        throw std::invalid_argument("Размер матрицы не может быть отрицательным");
    }
    if (x == 0) return;

    // Выделяем память под массив указателей на строки
    data_ = new int*[x];
    for (int i = 0; i < x; ++i) {
        // Выделяем память под каждую строку и сразу обнуляем её (скобки () в конце)
        data_[i] = new int[x](); 
        data_[i][i] = 1; // Делаем матрицу единичной
    }
}

// Конструктор прямоугольной матрицы
matrix::matrix(int x, int y) : rows_(x), cols_(y), data_(nullptr) {
    if (x < 0 || y < 0) {
        throw std::invalid_argument("Размер матрицы не может быть отрицательным");
    }
    if (x == 0 || y == 0) {
        return;
    }

    data_ = new int*[x];
    for (int i = 0; i < x; ++i) {
        data_[i] = new int[y](); // Обнуляем память
    }
}

// Деструктор: ОСВОБОЖДАЕМ ПАМЯТЬ!
matrix::~matrix() {
    for (int i = 0; i < rows_; ++i) {
        delete[] data_[i];
    }
    delete[] data_;
}

int matrix::getRows() const { return rows_; }
int matrix::getCols() const { return cols_; }

int matrix::get(int x, int y) const {
    if (x < 0 || x >= rows_ || y < 0 || y >= cols_) {
        throw std::out_of_range("Индексы вне диапазона матрицы");
    }
    return data_[x][y];
}

void matrix::set(int x, int y, int value) {
    if (x < 0 || x >= rows_ || y < 0 || y >= cols_) {
        throw std::out_of_range("Индексы вне диапазона матрицы");
    }
    data_[x][y] = value;
}

void matrix::inputFromKeyboard() {
    std::cout << "Введите " << rows_ * cols_ << " чисел для матрицы " << rows_ << "x" << cols_ << ":\n";
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            std::cin >> data_[i][j];
        }
    }
}

void matrix::fillRandom() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 99);

    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            data_[i][j] = distrib(gen);
        }
    }
}

void matrix::print() const {
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            std::cout << data_[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int matrix::sum() const {
    int total = 0;
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            total += data_[i][j];
        }
    }
    return total;
}