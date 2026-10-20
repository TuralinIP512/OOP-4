#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

class matrix {

    private:
        int rows_;
        int cols_;
        int **data_;

    public:
        matrix();

        explicit matrix(int x);

        matrix(int x, int y);

        ~matrix();

        int getRows() const;
        int getCols() const;

        int get(int x, int y) const;
        void set(int x, int y, int value);

        void print() const;
        int sum() const;

        void inputFromKeyboard();
        void fillRandom();
};

#endif