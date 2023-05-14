#pragma once
#include "Footwear.h"

class Boots :
    public Footwear
{
protected:
    int anyAttributeB;

public:

    Boots() : anyAttributeB(0) {}

    Boots(std::string _name, int _sizeFW, float _price, int _anyAttributeB) 
        : Footwear(_name, _sizeFW ,_price), anyAttributeB(_anyAttributeB) {}

    Boots(const Boots& obj)
    {
        anyAttributeB = obj.anyAttributeB;
    }

	void print(std::ostream&) const override;
	void scan(std::istream&) override;    
    
    Footwear* getCopy() const override;

	std::string myName() const override;

};