#pragma once
#include<fstream>

template<typename Type>
class TMatrix {

    size_t strCount;

    size_t columnCount;

    Type** matr;

public:

    TMatrix(size_t _strCount = 0, size_t _columnCount = 0) : strCount(_strCount), columnCount(_columnCount), matr(nullptr) {
        AllocateMemory();
    }

    TMatrix(const TMatrix& other) : TMatrix(other.strCount, other.columnCount) {
        for(size_t i = 0; i < strCount; i++)
            for (size_t j = 0; j < columnCount; j++) 
                matr[i][j] = other.matr[i][j];
    }
    
    TMatrix(TMatrix&& other) {
        std::swap(matr, other.matr);
        std::swap(strCount, other.strCount);
        std::swap(columnCount, other.columnCount);
    }

    TMatrix& operator=(TMatrix other) {
        std::swap(matr, other.matr);
        std::swap(strCount, other.strCount);
        std::swap(columnCount, other.columnCount);
        return *this;
    }

    ~TMatrix() { ClearMemory(); }

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
                in >> mat.matr[i][j];
            }
        }
        return in;
    }
    
    Type* operator[](int index) {
        return matr[index];
    }

    void AllocateMemory() {
        matr = new Type * [strCount];
        for (size_t i = 0; i < strCount; i++) 
            matr[i] = new Type[columnCount];
        
    }

    void ClearMemory() {
        for (size_t i = 0; i < strCount; i++) 
            delete[] matr[i];
        
        delete[] matr;
    }
};