#pragma once
#include <iostream>

class Footwear
{
protected:

    std::string name;
    int sizeFW;
    double price;

public:
    Footwear() : name(""), sizeFW(0), price(0) {}
    Footwear(std::string _name, int _sizeFW, double _price) : name(_name), sizeFW(_sizeFW), price(_price) {}
    Footwear(const Footwear& other) : name(other.name), sizeFW(other.sizeFW), price(other.price) {}

	virtual void print(std::ostream& out) const;
	virtual void scan(std::istream& in);    

    virtual std::string myName() const;

    int getSize() {return sizeFW;}
    float getPrice() {return price;}

    bool checkSize(int _sizeFW) const;
    bool checkPriceRange(float startP, float endP) const;


    virtual Footwear* getCopy() const = 0;

    virtual ~Footwear() {}
};

std::ostream& operator<<(std::ostream& out, const Footwear&);
std::istream& operator>>(std::istream& in, Footwear&);