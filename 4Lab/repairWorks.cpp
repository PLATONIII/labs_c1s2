#include "repairWorks.h"
#include <fstream>
#include <cmath>
#include <algorithm>

RepairWorks::RepairWorks(std::string _name, std::string _typeW, double _price, int _period)
{
    name = _name;
    typeW = _typeW;
    price = _price;
    period = _period;
}

RepairWorks::RepairWorks(const RepairWorks& t)
{
    name = t.name;
    typeW = t.typeW;
    price = t.price;
    period = t.period;
}

void RepairWorks::print(std::ostream &out) const
{
    out << "Name: " << name << " Type: " << typeW
        << " Price: " << price << " Period: "
        << period << "\n";
}

void RepairWorks::scan(std::istream &in)
{

    in >> name >> typeW >> price >> period;
}

bool RepairWorks::checkWorkType(std::string type)
{
    return(typeW == type);
}

bool RepairWorks::checkWorkPeriod(int hours)
{
    return(period <= hours);
}

bool RepairWorks::checkWorkPriceHours(double startp, double endp)
{
    return (startp < (price / period) && endp >(price / period));
}

RepairWorks *RepairWorks::SelectionsType(RepairWorks *arr, int size, int &newSize)
{
    newSize = 0;
    std::string type;
    std::cout << "Write type for selection: \n";
    std::cin >> type;
    for (int i = 0; i < size; i++)
        if (arr[i].checkWorkType(type))
            newSize++;

    RepairWorks *arrA = new RepairWorks[newSize];
    int k = 0;
    for (int j = 0; j < size; j++)
        if (arr[j].checkWorkType(type))
        {
            arrA[k] = arr[j];
            k++;
        }

    return arrA;
}

RepairWorks *RepairWorks::SelectionsPeriod(RepairWorks *arr, int size, int &newSize)
{
    newSize = 0;
    double hour;
    std::cout << "Write count of hours: \n";
    std::cin >> hour;
    for (int i = 0; i < size; i++)
        if (arr[i].checkWorkPeriod(hour))
            newSize++;

    RepairWorks *arrA = new RepairWorks[newSize];
    int k = 0;
    for (int j = 0; j < size; j++)
        if (arr[j].checkWorkPeriod(hour))
        {
            arrA[k] = arr[j];
            k++;
        }

    return arrA;
}

RepairWorks *RepairWorks::SelectionsPriceHours(RepairWorks *arr, int size, int &newSize)
{
    newSize = 0;
    double price;
    int hour;
    std::cout << "Write price and count of hource: \n";
    std::cin >> price >> hour;
    for (int i = 0; i < size; i++)
        if (arr[i].checkWorkPriceHours(price, hour))
            newSize++;

    RepairWorks *arrA = new RepairWorks[newSize];
    int k = 0;
    for (int j = 0; j < size; j++)
        if (arr[j].checkWorkPriceHours(price, hour))
        {
            arrA[k] = arr[j];
            k++;
        }

    return arrA;
}
