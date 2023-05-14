#include "Footwear.h"

void Footwear::print(std::ostream& out) const
{
	out << "Name: "<< name << "\t" << "Size: " << sizeFW << "\t" << "Price: " << price;
}

void Footwear::scan(std::istream& in)
{
	if (&in == &std::cin)
		std::cout << "Write name, size, price\n";
	in >> name >> sizeFW >> price;
}

std::string Footwear::myName() const
{
	return "Footwear";
}

bool Footwear::checkSize(int _sizeFW) const
{
	if(sizeFW == _sizeFW)
		return true;
	return false;
}

bool Footwear::checkPriceRange(float startP, float endP) const
{
	if((startP <= price) && (price <= endP))
		return true;
	return false;
}

std::ostream& operator<<(std::ostream& out, const Footwear& obj)
{
	obj.print(out);
	return out;
}

std::istream& operator>>(std::istream& in, Footwear& obj)
{
	obj.scan(in);
	return in;
}