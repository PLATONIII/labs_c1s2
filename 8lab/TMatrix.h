#pragma once
#include<fstream>
#include"Exception.h"

template<typename Type>
class TMatrix {

    size_t strCount;

    size_t columnCount;

    Type** matr;

public:

    TMatrix(size_t _strCount = 0, size_t _columnCount = 0) : strCount(_strCount), columnCount(_columnCount), matr(nullptr) {
        AllocateMemory();
    }
/*
    TMatrix(const TMatrix& other) : strCount(other.strCount), columnCount(other.columnCount), matr(nullptr) {
        matr = new Type * [strCount];
        for (size_t i = 0; i < strCount; ++i) {
            matr[i] = new Type[columnCount];
            for (size_t j = 0; j < columnCount; ++j) {
                matr[i][j] = other.matr[i][j];
            }
        }
    }
    
    TMatrix(TMatrix&& other) : strCount(other.strCount), columnCount(other.columnCount), matr(other.matr) {
        other.matr = nullptr;
        other.strCount = 0;
        other.columnCount = 0;
    }

    TMatrix& operator=(const TMatrix& other) {
        if (matr != nullptr) {
            for (size_t i = 0; i < strCount; ++i) {
                delete[] matr[i];
            }
            delete[] matr;
        }
        strCount = other.strCount;
        columnCount = other.columnCount;
        matr = new Type * [strCount];
        for (size_t i = 0; i < strCount; ++i) {
            matr[i] = new Type[columnCount];
            for (size_t j = 0; j < columnCount; ++j) {
                matr[i][j] = other.matr[i][j];
            }
        }
        return *this;
    }
    
    TMatrix& operator=(TMatrix&& other) {
        if (matr != nullptr) {
            for (size_t i = 0; i < strCount; ++i) {
                delete[] matr[i];
            }
            delete[] matr;
        }
        strCount = other.strCount;
        columnCount = other.columnCount;
        matr = other.matr;
        other.matr = nullptr;
        other.strCount = 0;
        other.columnCount = 0;
        return *this;
    }
*/
    ~TMatrix() {
        ClearMemory();
    }

    void generateRandomValues(size_t sizeStartP, size_t sizeEndP, Type valueStartP, Type valueEndP) {
        if (matr != nullptr)
            ClearMemory();
        strCount = sizeStartP + rand() % (sizeEndP - sizeStartP + 1);
        columnCount = sizeStartP + rand() % (sizeEndP - sizeStartP + 1);
        AllocateMemory();
        for (size_t i = 0; i < strCount; i++)
            for(size_t j = 0; j < columnCount; j++)
                matr[i][j] = (valueEndP - valueStartP) * (rand() / (double)RAND_MAX) + valueStartP;

    }

    Type getAverageLeftHalf() {
        Type average = 0;
        double count = 0;
        for (size_t i = 0; i < strCount; i++)
            for (size_t j = 0; j < columnCount / 2; j++)
            {
                average = average + matr[i][j];
                count++;
            }
        return average / count;
    }

    Type getSumBelowAverageLeftHalf() {
        Type sum = 0, averageLeftHalf = getAverageLeftHalf();
        
        for (size_t i = 0; i < strCount; i++)
            for(size_t j = 0; j < columnCount; j++)
                if(matr[i][j] < averageLeftHalf)
                    sum = sum + matr[i][j];
        return sum;
    }

    Type getMaxInMin() {
        Type* minArr = new Type[strCount];
        Type currentMin;

        for (size_t i = 0; i < strCount; i++) {
            currentMin = matr[i][0];
            for (size_t j = 1; j < columnCount; j++)
                if (matr[i][j] < currentMin)
                    currentMin = matr[i][j];

            minArr[i] = currentMin;
        }

        
        Type minValue = minArr[0];
        for (size_t i = 1; i < strCount; i++) {
            if (minValue > minArr[i])
                minValue = minArr[i];
        }
        delete[] minArr;
        return minValue;
    }

    friend std::ostream& operator<<(std::ostream& out, const TMatrix& mat) {
        for (size_t i = 0; i < mat.strCount; i++) {
            for (size_t j = 0; j < mat.columnCount; j++) {
                out << mat.matr[i][j] << "\t";
            }
            out << std::endl;
        }
        return out;
    }

    friend std::istream& operator>>(std::istream& in, TMatrix& mat) {
        if (&in == &std::cin) {
            std::cout << "Write count of string and columns, write matrix:" << std::endl;
        }
        in >> mat.strCount >> mat.columnCount;
        mat.AllocateMemory();
        for (size_t i = 0; i < mat.strCount; i++) {
            for (size_t j = 0; j < mat.columnCount; j++) {
                Type element;
                if (!(in >> element)) {
                        throw InvalidInputException("InvalidInputException");
                }
                mat.matr[i][j] = element;
            }
        }
        return in;
    }
    
    Type* operator[](int index) {
        if (index < 0 || index >= strCount) {
            throw IndexOutOfRange("IndexOutOfRange");
        }
        return matr[index];
    }

    void AllocateMemory() {
        bool done = true;
        if(strCount != columnCount)
            done = false;
        while (!done) {
            try {
                if (strCount != columnCount) {
                    throw StrCountNotEquelColumnCount("StrCountNotEquelColumnCount");
                }
                done = true;
            }
            catch (const StrCountNotEquelColumnCount& e) {
                std::cout << "Write against: " << std::endl;
                std::cin >> strCount >> columnCount;
            }
        }
        matr = new Type * [strCount];
        for (size_t i = 0; i < strCount; i++) {
            matr[i] = new Type[columnCount];
        }
    }

    void ClearMemory() {
        for (size_t i = 0; i < strCount; i++) {
            delete[] matr[i];
        }
        delete[] matr;
    }
};