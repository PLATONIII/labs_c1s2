#pragma once
#include "Footwear.h"

class Shoes :
    public Footwear
{
protected:
    int anyAttributeS;

public:

    Shoes() : anyAttributeS(0) {}

    Shoes(std::string _name, int _sizeFW, float _price, int _anyAttributeS) 
        : Footwear(_name, _sizeFW ,_price), anyAttributeS(_anyAttributeS) {}

    Shoes(const Shoes& obj)
    {
        anyAttributeS = obj.anyAttributeS;
    }

	void print(std::ostream&) const override;
	void scan(std::istream&) override;    

    Footwear* getCopy() const override;

	std::string myName() const override;

};