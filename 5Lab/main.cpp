#include <iostream>
#include "Matrix.h"
#include <algorithm>
#include <stdlib.h>
#include <time.h>

void getMenu(int &variant, int &breakP)
{

    int i = 0;
    do
    {
        i = 0;
        std::cout << "What do you want to do?\n";
        std::cout << ++i << ". Enter from keyboard\n";
        std::cout << ++i << ". Random matrices\n";
        std::cout << ++i << ". Print on display\n";
        std::cout << ++i << ". Actions on matrices\n";
        std::cout << ++i << ". Get average\n";
        std::cout << ++i << ". Sort by average\n";
        std::cout << ++i << ". Exit\n";
        std::cout << ">";
        std::cin >> variant;
    } while (variant <= 0 || variant > i);
    breakP = i;
}

int main()
{
    srand(time(NULL));
    int variant, breakPoint;
    int size;
    Matrix *matrices = nullptr;

    do
    {
        getMenu(variant, breakPoint);
        switch (variant)
        {
        case 1:
        {
            if (matrices != nullptr)
            {
                delete[] matrices;
                size = 0;
            }
            std::cout << "Write number of matrices: ";
            std::cin >> size;
            std::cout << "\n";
            matrices = new Matrix[size];
            for (int i = 0; i < size; i++)
            {
                std::cout << "Write matrix number " << i + 1 << "... \n";
                std::cin >> matrices[i];
                std::cout << "\n";
            }
            break;
        }
        case 2:
        {
            if (matrices != nullptr)
            {
                delete[] matrices;
                size = 0;
            }
            int min, max, sizeMatrix;
            std::cout << "Write number of matrices: \n";
            std::cin >> size;
            matrices = new Matrix[size];
            std::cout << "Their size: \n";
            std::cin >> sizeMatrix;
            std::cout << "Write min and max of numbers: \n";
            std::cin >> min;
            std::cin >> max;
            for (int i = 0; i < size; i++)
            {
                matrices[i].GenerateValue(min, max, sizeMatrix);
            }
            break;
        }
        case 3:
        {
            for (int i = 0; i < size; i++)
            {
                std::cout << "Matrix number " << i + 1 << "\n";
                std::cout << matrices[i] << "\n";
            }
            break;
        }
        case 4:
        {
            Matrix resultAction;
            int firstMatr, secondMatr, variantActions;
            std::cout << "Chose actions: "
                      << "\n 1. +"
                      << "\n 2. -"
                      << "\n 3. * \n";
            std::cin >> variantActions;
            std::cout << "Chose 2 matrices: "
                      << "\n";
            for (int i = 0; i < size; i++)
            {
                std::cout << "Matrix number " << i + 1 << "\n";
                std::cout << matrices[i] << "\n";
            }
            std::cout << "First: ";
            std::cin >> firstMatr;
            std::cout << "Second: ";
            std::cin >> secondMatr;
            std::cout << "Result...\n";
            switch (variantActions)
            {
            case 1:
            {
                resultAction = matrices[--firstMatr] + matrices[--secondMatr];
                std::cout << resultAction;
                break;
            }
            case 2:
            {
                resultAction = matrices[--firstMatr] - matrices[--secondMatr];
                std::cout << resultAction;
                break;
            }
            case 3:
            {
                resultAction = matrices[--firstMatr] * matrices[--secondMatr];
                std::cout << resultAction;
                break;
            }
            }
            break;
        }
        case 5:
        {
            int variant;
            std::cout << "Chose matrix: \n";
            for (int i = 0; i < size; i++)
            {
                std::cout << "Matrix number " << i + 1 << "\n";
                std::cout << matrices[i] << "\n";
            }
            std::cin >> variant;
            double average = matrices[--variant].GetAverage();
            std::cout << "Average: " << average << "\n";
            break;
        }
        case 6:
        {

            std::sort(matrices, matrices + size);
            break;
        }
        }

    } while (variant != breakPoint);

    delete[] matrices;

    system("pause");
    return 0;
}