#include "Boots.h"

void Boots::print(std::ostream& out) const
{
	Footwear::print(out);
	out << "\t" << "AttributeB: " << anyAttributeB;
}

void Boots::scan(std::istream& in)
{
	Footwear::scan(in);
	if (&in == &std::cin)
		std::cout << "Write attribute\n";
	in >> anyAttributeB;
}

Footwear* Boots::getCopy() const
{
	return new Boots(name, sizeFW, price, anyAttributeB);
}

std::string Boots::myName() const
{
	return "Boots";
}