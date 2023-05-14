#include "Shoes.h"

void Shoes::print(std::ostream& out) const
{
	Footwear::print(out);
	out << "\t" << "AttributeS: " << anyAttributeS;
}

void Shoes::scan(std::istream& in)
{
	Footwear::scan(in);
	if (&in == &std::cin)
		std::cout << "Write attribute\n";
	in >> anyAttributeS;
}

Footwear* Shoes::getCopy() const
{
	return new Shoes(name, sizeFW, price, anyAttributeS);
}

std::string Shoes::myName() const
{
	return "Shoes";
}