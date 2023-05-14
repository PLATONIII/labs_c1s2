#include <iostream>
#include <fstream>
#include "Exhibition.h"

enum Menu
{
	scan_from_keyboard = 1,
	scan_from_file,
	print_to_display,
	print_to_file,
    sorted_by_size,
    sorted_by_price_range,
    get_info_min_max_price_of_size,
	exit_programm
};

void getMenu()
{
    std::cout << scan_from_keyboard << ". Write from keyboard\n" 
        << scan_from_file << ". Write from file\n" 
        << print_to_display << ". Print to display\n" 
        << print_to_file << ". Print to file\n" 
        << sorted_by_size << ". Sorted by size\n"
        << sorted_by_price_range << ". Sorted by price range\n"
        << get_info_min_max_price_of_size << ". Print info about min max price of size\n"
        << exit_programm << ". Exit program\n";
    
}
int main()
{
    int choise;
    Exhibition collection;

    do
    {
        getMenu();
        std::cin >> choise;
        switch(choise)
        {
        case scan_from_keyboard:
        {
            std::cin >> collection;
            break;
        }
        case scan_from_file:
        {
            std::string path;
            std::cout << "Write name of file\n";
            std::cin >> path;
            std::ifstream fin(path);
            fin >> collection;
            fin.close();
            break;
        }
        case print_to_display:
        {
            std::cout << collection;
            break;
        }
        case print_to_file:
        {
            std::string path;
            std::cout << "Write name of file\n";
            std::cin >> path;
            std::ofstream fout(path);
            fout << collection;
            fout.close();
            break;   
        }
        case sorted_by_size:
        {
            std::cout << "Write size\n";
            int sizeForSorted;
            std::cin >> sizeForSorted;
            Exhibition collectionSortedBySize = collection.getCollectionSortedBySize(sizeForSorted);
            std::cout << collectionSortedBySize;
            break;
        }
        case sorted_by_price_range:
        {
            std::cout << "Write start and end of range\n";
            float startP,endP;
            std::cin >> startP;
            std::cin >> endP;
            Exhibition collectionSortedBySize = collection.getCollectionSortedByPriceRange(startP, endP);
            std::cout << collectionSortedBySize;
            break;
        }
        case get_info_min_max_price_of_size:
        {
            collection.getInfoMinMaxPriceOfSize();
            break;
        }
        case exit_programm:
        {
            break;
        }
        }
    
    } while (choise != exit_programm);

    return 0;
    

}
