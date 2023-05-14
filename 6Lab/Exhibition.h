#pragma once
#include "Footwear.h"

class Exhibition
{
private:

    Footwear** cl;
    unsigned int size;

public:

    Exhibition(Footwear** _cl = nullptr, unsigned int _size = 0);

    Exhibition(const Exhibition& other);

    Exhibition(Exhibition&& other);

    Exhibition& operator=(Exhibition other);

    void clearMemory();
    
	void print(std::ostream& out) const;
	void scan(std::istream& in);    

    Exhibition getCollectionSortedBySize(int _sizeFW);
    Exhibition getCollectionSortedByPriceRange(float startP, float endP);

    void getInfoMinMaxPriceOfSize();


    ~Exhibition() { clearMemory(); }

};

std::istream& operator>>(std::istream& in, Exhibition& obj);
std::ostream& operator<<(std::ostream& out, const Exhibition& obj);