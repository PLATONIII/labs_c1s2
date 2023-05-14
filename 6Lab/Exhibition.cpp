#include <algorithm>
#include "Exhibition.h"
#include "Boots.h"
#include "Shoes.h"

Exhibition::Exhibition(Footwear** _cl, unsigned int _size)
{
    size = _size;
    if(_cl != nullptr)
    {
        cl = new Footwear*[size];
        for(unsigned int i = 0; i < size; i++)
            cl[i] = (*_cl[i]).getCopy();
        
    }
    else
        cl = _cl;
}

Exhibition::Exhibition(const Exhibition& other)
    : Exhibition(other.cl, other.size)
{}

Exhibition::Exhibition(Exhibition&& other)
{
    size = other.size;
    cl = other.cl;
    other.cl = nullptr;
    other.size = 0;

}

Exhibition& Exhibition::operator=(Exhibition other)
{
    std::swap(cl, other.cl);
    std::swap(size, other.size);
    return *this;
}

void Exhibition::print(std::ostream& out) const
{
    out << size << "\n";
    for(unsigned int i = 0; i < size; i++)
        out << (*cl[i]) << "\n";
    
}

void Exhibition::scan(std::istream& in)
{
    if(&in == &std::cin)
        std::cout << "Write size of collecntion\n";
    unsigned int sizeN;
    in >> sizeN;
    Footwear** clN = new Footwear * [sizeN];
    for(unsigned int i = 0; i < sizeN; i++)
    {
        if(&in == &std::cin)
            std::cout << "Write type of footwear(Boots/Shoes)\n";
        std::string type;
        in >> type;
        if (type == "Boots")
            clN[i] = new Boots;
        else if (type == "Shoes")
            clN[i] = new Shoes;
        in >> (*clN[i]);   
    }
    
    clearMemory();
    cl = clN;
    size = sizeN;
}

Exhibition Exhibition::getCollectionSortedBySize(int _sizeFW)
{
    unsigned int sizeN = 0;
    for(unsigned int i = 0; i < size; i++)
        if((*cl[i]).checkSize(_sizeFW))
            sizeN++;
    
    Footwear** clN = new Footwear * [sizeN];

    for(unsigned int j = 0, k = 0; j < size; j++)
        if((*cl[j]).checkSize(_sizeFW))
        {
            clN[k] = cl[j];
            k++;
        }
    
    Exhibition collectionN(clN, sizeN);
    return collectionN;        
}

Exhibition Exhibition::getCollectionSortedByPriceRange(float startP, float endP)
{
    unsigned int sizeN = 0;
    for(unsigned int i = 0; i < size; i++)
        if((*cl[i]).checkPriceRange(startP, endP))
            sizeN++;
    
    Footwear** clN = new Footwear * [sizeN];

    for(unsigned int j = 0, k = 0; j < size; j++)
        if((*cl[j]).checkPriceRange(startP, endP))
        {
            clN[k] = cl[j];
            k++;
        }
    
    Exhibition collectionN(clN, sizeN);
    return collectionN; 
}

bool inArray(int* arr, int need, int size, int point)
{
    int breakP = 0;
    for(int i = point+1; i < size; ++i)
        if(arr[i] == need)
            breakP++;

    if(breakP == 0)
        return false;

    return true;
}

int* getUniqSizeFWArr(int* sizeArr, int size, int& sizeN)
{   
    for(int i = 0; i < size; i++)
    {
        if(inArray(sizeArr, sizeArr[i],size, i))
            continue;
        sizeN++;
    }

    int* sizeArrUniq = new int[sizeN];

    for(int j = 0, k = 0; j < size; j++)
    {
        if(inArray(sizeArr, sizeArr[j],size, j))
            continue;
        sizeArrUniq[k] = sizeArr[j];
        k++;
    }

    std::sort(sizeArrUniq, sizeArrUniq + sizeN);

    return sizeArrUniq;
}

void Exhibition::getInfoMinMaxPriceOfSize()
{
    int sizeN = 0, maxPrice = 0, minPrice = 0, currentSize = 0, sizePriceArr = 0;
    int* sizeArr = new int[size];
    for(int i = 0; i < size; i++)
        sizeArr[i] = cl[i]->getSize();

    int* sizeArrUniq = getUniqSizeFWArr(sizeArr, size, sizeN);

    for(int j = 0; j < sizeN; j++)
    {
        sizePriceArr = 0;
        currentSize = sizeArrUniq[j];
        
        for(int k = 0; k < size; k++)
            if(cl[k]->getSize() == currentSize)
                sizePriceArr++;

        int* priceArr = new int[sizePriceArr];

        for(int k = 0, l = 0; k < size; k++)
            if(cl[k]->getSize() == currentSize)
            {
                priceArr[l] = cl[k]->getPrice();
                l++;
            }

        std::sort(priceArr, priceArr + sizePriceArr);
        
        if(sizePriceArr == 1)
            std::cout << "Size " << sizeArrUniq[j] << " have 1 model, price: " << priceArr[0] <<"\n";
        else
            std:: cout << "Size: " << sizeArrUniq[j] << "  Min price: " << priceArr[0] << "  Max price: " << priceArr[sizePriceArr-1] << "\n";


        delete[] priceArr;

    }
    delete[] sizeArr;
    delete[] sizeArrUniq;

}

void Exhibition::clearMemory()
{
    for(unsigned int i = 0; i < size; i++)
    {
        delete cl[i];
    }
    delete[] cl;

    cl = nullptr;
    size = 0;
}

std::istream& operator>>(std::istream& in, Exhibition& obj)
{
    obj.scan(in);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Exhibition& obj)
{
    obj.print(out);
    return out;
}