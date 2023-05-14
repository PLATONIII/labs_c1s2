#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"repairWorks.h"

class ArrayRepairWorks
{
	RepairWorks* repairWorks;

	int size;

public:

	ArrayRepairWorks();

	ArrayRepairWorks(RepairWorks* repairWorksPtr, int arraySize);

	ArrayRepairWorks(const ArrayRepairWorks& other);

	ArrayRepairWorks(ArrayRepairWorks&& other) noexcept;

	ArrayRepairWorks& operator=(const ArrayRepairWorks& other);

	~ArrayRepairWorks() { delete[] repairWorks; }

	void print(std::ostream& out) const;

	void scan(std::istream& in);

	ArrayRepairWorks ArraySelectionsType(std::string type);

	ArrayRepairWorks ArraySelectionsPeriod(int hour);

	ArrayRepairWorks ArraySelectionsPriceHours(double startP, double endP);
};