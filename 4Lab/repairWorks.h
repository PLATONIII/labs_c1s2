#pragma once
#include<iostream>
#include<string>
#include<fstream>

class RepairWorks
{
    std::string name;

    std::string typeW;

    double price;

    int period;

public:
    RepairWorks() : name(""), typeW(""), price(0), period(0) {}

    RepairWorks(std::string _name, std::string _typeW, double _price, int _period);

    RepairWorks(const RepairWorks &t);

    ~RepairWorks(){}

    void print(std::ostream &out) const;

    void scan(std::istream &in);

    bool checkWorkType(std::string type);

    bool checkWorkPeriod(int hours);

    bool checkWorkPriceHours(double startp, double endp);

    static RepairWorks *SelectionsType(RepairWorks *arr, int size, int &newSize);

    static RepairWorks *SelectionsPeriod(RepairWorks *arr, int size, int &newSize);

    static RepairWorks *SelectionsPriceHours(RepairWorks *arr, int size, int &newSize);
};

