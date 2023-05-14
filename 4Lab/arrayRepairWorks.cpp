#include<iostream>
#include"arrayRepairWorks.h"

ArrayRepairWorks::ArrayRepairWorks()
{
    repairWorks = nullptr;
    size = 0;
}

ArrayRepairWorks::ArrayRepairWorks(RepairWorks* repairWorksPtr, int arraySize)
{
    size = arraySize;
    repairWorks = new RepairWorks[arraySize];
    for (int i = 0; i < arraySize; i++)
    {
        repairWorks[i] = repairWorksPtr[i];
    }
}

ArrayRepairWorks::ArrayRepairWorks(const ArrayRepairWorks& other)
{
    size = other.size;
    repairWorks = new RepairWorks[size];
    for (int i = 0; i < size; i++)
    {
        repairWorks[i] = other.repairWorks[i];
    }
}

ArrayRepairWorks::ArrayRepairWorks(ArrayRepairWorks&& other) noexcept
{
    size = other.size;
    repairWorks = other.repairWorks;
    other.size = 0;
    other.repairWorks = nullptr;
}

ArrayRepairWorks& ArrayRepairWorks::operator=(const ArrayRepairWorks& other)
{
    if (this != &other)
    {
        size = other.size;
        delete[] repairWorks;
        repairWorks = new RepairWorks[size];
        for (int i = 0; i < size; i++)
        {
            repairWorks[i] = other.repairWorks[i];
        }
    }
    return *this;
}

void ArrayRepairWorks::print(std::ostream& out) const
{
    out << size << std::endl;
    for (int i = 0; i < size; i++)
        repairWorks[i].print(out);
}

void ArrayRepairWorks::scan(std::istream& in)
{
    if (repairWorks != nullptr)
    {
        delete[] repairWorks;
        size = 0;
    }
    if (&in == &std::cin)
        std::cout << "Write count of works: " << std::endl;
    in >> size;
    repairWorks = new RepairWorks[size];
    for (int i = 0; i < size; i++)
        repairWorks[i].scan(in);
}

ArrayRepairWorks ArrayRepairWorks::ArraySelectionsType(std::string type)
{
    int newSize = 0;
    for (int i = 0; i < size; i++)
        if (repairWorks[i].checkWorkType(type))
            newSize++;

    RepairWorks* newRepairWorks = new RepairWorks[newSize];

    int k = 0;
    for (int j = 0; j < size; j++)
        if (repairWorks[j].checkWorkType(type))
            newRepairWorks[k++] = repairWorks[j];
        
    return ArrayRepairWorks(newRepairWorks, newSize);
}

ArrayRepairWorks ArrayRepairWorks::ArraySelectionsPeriod(int hour)
{
    int newSize = 0;
    for (int i = 0; i < size; i++)
        if (repairWorks[i].checkWorkPeriod(hour))
            newSize++;

    RepairWorks* newRepairWorks = new RepairWorks[newSize];

    int k = 0;
    for (int j = 0; j < size; j++)
        if (repairWorks[j].checkWorkPeriod(hour))
            newRepairWorks[k++] = repairWorks[j];

    return ArrayRepairWorks(newRepairWorks, newSize);
}

ArrayRepairWorks ArrayRepairWorks::ArraySelectionsPriceHours(double startP, double endP)
{
    int newSize = 0;
    for (int i = 0; i < size; i++)
        if (repairWorks[i].checkWorkPriceHours(startP, endP))
            newSize++;

    RepairWorks* newRepairWorks = new RepairWorks[newSize];

    int k = 0;
    for (int j = 0; j < size; j++)
        if (repairWorks[j].checkWorkPriceHours(startP, endP))
            newRepairWorks[k++] = repairWorks[j];

    return ArrayRepairWorks(newRepairWorks, newSize);
}
