#include "Matrix.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

std::ostream &Matrix::print(std::ostream &stream) const
{

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            stream << std::setw(8) << *(matr + i * size + j);
        }
        stream << "\n";
    }

    return stream;
}

std::istream &Matrix::scan(std::istream &stream)
{
    if (matr != nullptr)
    {
        delete[] matr;
        size = 0;
    }
    if (&stream == &std::cin)
    {
        std::cout << "Write size and elements of matrix: ";
    }
    stream >> size;
    matr = new int[size * size];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            stream >> *(matr + i * size + j);
        }
    }

    return stream;
}

Matrix &Matrix::GenerateValue(int min, int max, int _size)
{
    if (matr != nullptr)
    {
        delete[] matr;
        size = 0;
    }
    size = _size;
    matr = new int[size * size];
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            *(matr + i * size + j) = min + rand() % max;

    return *this;
}
double Matrix::GetAverage() const
{
    double average = 0;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            average += *(matr + i * size + j);

    average /= size * size;
    return average;
}

std::ostream &operator<<(std::ostream &stream, const Matrix &m)
{
    return m.print(stream);
}

std::istream &operator>>(std::istream &stream, Matrix &m)
{
    return m.scan(stream);
}

Matrix operator+(const Matrix &first, const Matrix &second)
{
    Matrix ans;
    ans.size = first.size;
    ans.matr = new int[ans.size * ans.size];
    for (int i = 0; i < ans.size; i++)
    {
        for (int j = 0; j < ans.size; j++)
        {
            *(ans.matr + i * ans.size + j) = *(first.matr + i * ans.size + j) + *(second.matr + i * ans.size + j);
        }
    }
    return ans;
}

Matrix operator-(const Matrix &first, const Matrix &second)
{
    Matrix ans;
    ans.size = first.size;
    ans.matr = new int[ans.size * ans.size];
    for (int i = 0; i < ans.size; i++)
    {
        for (int j = 0; j < ans.size; j++)
        {
            *(ans.matr + i * ans.size + j) = *(first.matr + i * ans.size + j) + (*(second.matr + i * ans.size + j) * (-1));
        }
    }
    return ans;
}

Matrix operator*(const Matrix &first, const Matrix &second)
{
    Matrix ans;
    ans.size = first.size;
    ans.matr = new int[ans.size * ans.size];
    for (int i = 0; i < ans.size; i++)
    {
        for (int j = 0; j < ans.size; j++)
        {
            *(ans.matr + i * ans.size + j) = 0;

            for (int k = 0; k < ans.size; k++)
            {
                *(ans.matr + i * ans.size + j) += *(first.matr + i * ans.size + k) * (*(second.matr + k * ans.size + j));
            }
        }
    }
    return ans;
}

bool Matrix::operator>(const Matrix& mt2) const
{
    return this->GetAverage() > mt2.GetAverage();
}

bool Matrix::operator<(const Matrix& mt2) const
{
    return mt2 > (*this);
}
/*
bool Matrix::operator>(const Matrix &m) const
{
    double average1 = GetAverage();
    double average2 = m.GetAverage();

    return average1 > average2;
}
*/