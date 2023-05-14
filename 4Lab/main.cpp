#include <iostream>
#include <fstream>
#include <string>
#include "repairWorks.h"
#include "arrayRepairWorks.h"

void getMenu(int &variant, int &breakP)
{

    int i = 0;
    do
    {
        i = 0;
        std::cout << "What do you want to do?" << std::endl;
        std::cout << ++i << ". Enter from keyboard" << std::endl;
        std::cout << ++i << ". Print on display" << std::endl;
        std::cout << ++i << ". Check" << std::endl;
        std::cout << ++i << ". Selections" << std::endl;
        std::cout << ++i << ". Print to file" << std::endl;
        std::cout << ++i << ". Enter from file" << std::endl;
        std::cout << ++i << ". Exit" << std::endl;
        std::cout << ">";
        std::cin >> variant;
    } while (variant <= 0 || variant > i);
    breakP = i;
}

void getMenu2(int& variant, int& breakP)
{

    int i = 0;
    do
    {
        i = 0;
        std::cout << "What do you want to do?" << std::endl;
        std::cout << ++i << ". Enter from file" << std::endl;
        std::cout << ++i << ". Print to file" << std::endl;
        std::cout << ++i << ". Selections" << std::endl;
        std::cout << ++i << ". Exit" << std::endl;
        std::cout << ">";
        std::cin >> variant;
    } while (variant <= 0 || variant > i);
    breakP = i;
}

int main()
{
    int breakPoint;
    int variant;

    /*
    int size;
    RepairWorks *repairWorks = nullptr;

    do
    {
        getMenu(variant, breakPoint);

        switch (variant)
        {
        case 1:
        {
            if (repairWorks != nullptr)
            {
                delete[] repairWorks;
                size = 0;
            }
            std::cout << "Write number of works: " << std::endl;
            std::cin >> size;
            repairWorks = new RepairWorks[size];
            for (int i = 0; i < size; i++)
            {
                std::cout << "Write work number " << i + 1 << ": " << std::endl;
                repairWorks[i].scan(std::cin);
            }
            break;
        }
        case 2:
        {
            for (int i = 0; i < size; i++)
            {
                repairWorks[i].print(std::cout);
            }
            break;
        }
        case 3:
        {
            int serviceNumber;
            std::cout << "Which service do you want to check out: " << std::endl;
            for (int i = 0; i < size; i++)
            {
                std::cout << i + 1 << ". ";
                repairWorks[i].print(std::cout);
            }
            std::cin >> serviceNumber;

            int variant;
            std::cout << "What you need to check?" << std::endl
                      << "1. Does the service have the specified type of work" << std::endl
                      << "2. Does the performance of the service exceed the specified number of hours" << std::endl
                      << "3. Is the ratio (cost/due date) in the specified interval" << std::endl;
            std::cin >> variant;

            switch (variant)
            {
            case 1:
            {
                std::string type;
                std::cout << "What type of availability do you want to check: " << std::endl;
                std::cin >> type;
                if (repairWorks[--serviceNumber].checkWorkType(type))
                    std::cout << "She has this type" << std::endl;
                else
                    std::cout << "She doesn't have this type" << std::endl;

                break;
            }
            case 2:
            {
                double hours;
                std::cout << "What number of hours should the service not exceed: " << std::endl;
                std::cin >> hours;
                if (repairWorks[--serviceNumber].checkWorkPeriod(hours))
                    std::cout << " Does not exceed" << std::endl;
                else
                    std::cout << " Exceeds" << std::endl;

                break;
            }
            case 3:
            {
                double startP;
                double endP;
                std::cout << "Enter the beginning and end of the interval: " << std::endl;
                std::cin >> startP;
                std::cin >> endP;
                if (repairWorks[--serviceNumber].checkWorkPriceHours(startP, endP))
                    std::cout << " Does not exceed" << std::endl;
                else
                    std::cout << " Exceeds" << std::endl;

                break;
            }
            }
            break;
        }
        case 4:
        {
            int variant;
            std::cout << "What you need to selections: " << std::endl
                      << "1. List of services of the specified type of work" << std::endl
                      << "2. The list of services whose execution does not exceed the specified" << std::endl
                      << "3. Price/hours in interval" << std::endl;
            std::cin >> variant;
            switch (variant)
            {
            case 1:
            {
                int sizeT;
                RepairWorks *repairWT = RepairWorks::SelectionsType(repairWorks, size, sizeT);
                for (int i = 0; i < sizeT; i++)
                {
                    repairWT[i].print(std::cout);
                }
                delete[] repairWT;
                break;
            }
            case 2:
            {
                int sizeT;
                RepairWorks *repairWP = RepairWorks::SelectionsPeriod(repairWorks, size, sizeT);
                for (int i = 0; i < sizeT; i++)
                {
                    repairWP[i].print(std::cout);
                }
                delete[] repairWP;
                break;
            }
            case 3:
            {
                int sizeT;
                RepairWorks *repairWPH = RepairWorks::SelectionsPriceHours(repairWorks, size, sizeT);
                for (int i = 0; i < sizeT; i++)
                {
                    repairWPH[i].print(std::cout);
                }
                delete[] repairWPH;
                break;
            }
            }
            break;
        }
        case 5:
        {
            std::string path = "o.txt";
            std::ofstream out(path);
            for (int i = 0; i < size; i++)
            {
                repairWorks[i].print(out);
            }
        }
        case 6:
        {
            if (repairWorks != nullptr)
            {
                delete[] repairWorks;
                size = 0;
            }
            std::string path = "t.txt";
            std::ifstream fin(path);
            fin >> size;
            repairWorks = new RepairWorks[size];
            for (int i = 0; i < size; i++)
            {
                repairWorks[i].scan(fin);
            }
        }
        }

    } while (variant != breakPoint);

    delete[] repairWorks;
    */
    

    ArrayRepairWorks works;
    do
    {
        getMenu2(variant, breakPoint);

        switch (variant)
        {
        case 1:
        {
            std::string path;
            std::cout << "Write name of file: " << std::endl;
            std::cin >> path;
            std::ifstream fin(path);
            works.scan(fin);
            break;
        }
        case 2:
        {
            std::string path;
            std::cout << "Write name of file: " << std::endl;
            std::cin >> path;
            std::ofstream out(path);
            works.print(out);
            break;

        }
        case 3:
        {
            int variant;
            std::cout << "What selections you need: " << std::endl
                << "1. List works specified type" << std::endl
                << "2. List works that do not exceed the specified value" << std::endl
                << "3. List of works that are in the range price/hours" << std::endl;
            std::cin >> variant;
            switch (variant)
            {
            case 1:
            {
                std::string type;
                std::cout << "Write type: " << std::endl;
                std::cin >> type;
                ArrayRepairWorks newWorks = works.ArraySelectionsType(type);
                newWorks.print(std::cout);
                break;
            }
            case 2:
            {
                int hour;
                std::cout << "Write count of hours: " << std::endl;
                std::cin >> hour;
                ArrayRepairWorks newWorks = works.ArraySelectionsPeriod(hour);
                newWorks.print(std::cout);
                break;

            }
            case 3:
            {
                double startP, endP; 
                std::cout << "Write start and end of range: " << std::endl;
                std::cin >> startP >> endP;
                ArrayRepairWorks newWorks = works.ArraySelectionsPriceHours(startP, endP);
                newWorks.print(std::cout);
                break;

            }
            }
            break;

        }

        }

    } while (variant != breakPoint);

    return 0;
}