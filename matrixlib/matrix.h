#pragma once
#include <vector>
#include <iostream>

namespace math
{
    #ifdef MATH_DOUBLE_PRECISION_DEFINE
        typedef double real;
    #else
        typedef float real;
    #endif

    class Matrix
    {
    protected:

        int cols_;
        int rows_;
        std::vector<real> mvec_;
    public:
        // конструктор по умолчанию
        Matrix(){};

        // конструктор с параметрами
        Matrix(int rows, int cols) : cols_(cols), rows_(rows), mvec_(std::vector<real>(rows * cols)) {};

        // mvec вектор элементов матрицы
        void getVec(std::vector<real>& mvec) const;

        int rows() const;
        int cols() const;

        // оператор доступа к элементам матрицы
        real& operator()(int row, int col);

        // константная версия operator()
        real operator()(int row, int col) const;

        // перегрузка оператора вывода для печати элементов матрицы в консоль
        friend std::ostream& operator<< (std::ostream &out, const Matrix &matrix);

        friend Matrix operator+(const Matrix& A, const Matrix& B);

        friend Matrix operator-(const Matrix& A, const Matrix& B);

        friend Matrix operator*(const Matrix& A, const Matrix& B);
    };
} // namespace math
