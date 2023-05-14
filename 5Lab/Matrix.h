#pragma once
#ifndef MATR
#define MATR

#include <iostream>
#include <fstream>

class Matrix
{
    int size;
    int *matr;

public:
    Matrix()
    {
        size = 0;
        matr = nullptr;
    }

    Matrix(int *_matr, int _size)
    {
        size = _size;
        matr = new int[size * size];
        for (int i = 0; i < size * size; i++)
            matr[i] = _matr[i];
    }

    Matrix(const Matrix &m)
        : Matrix(m.matr, m.size)
    {
    }

    Matrix &operator=(Matrix other)
    {
        std::swap(size, other.size);
        std::swap(matr, other.matr);

        return *this;
    }

    ~Matrix()
    {
        delete[] matr;
    }

    Matrix &GenerateValue(int min, int max, int _size);

    double GetAverage() const;
    /*
        {
            double average = 0;
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    average += *(matr + i * size + j);

            average /= size;
            return average;
        }
    */
    std::ostream &print(std::ostream &stream) const;
    std::istream &scan(std::istream &stream);

    friend std::ostream &operator<<(std::ostream &stream, const Matrix &obj);

    friend std::istream &operator>>(std::istream &stream, Matrix &obj);

    friend Matrix operator+(const Matrix &first, const Matrix &second);

    friend Matrix operator-(const Matrix &first, const Matrix &second);

    friend Matrix operator*(const Matrix &first, const Matrix &second);

    bool operator>(const Matrix &mt2) const;
    bool operator<(const Matrix &mt2) const;
};

#endif