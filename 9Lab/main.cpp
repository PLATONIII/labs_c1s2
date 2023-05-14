#include <iostream>

#include "WordsFinder.h"

int main(){

    WordsFinder a;
    a.readFromFile("input.txt");
    std::vector<std::string> ans = a.findWordsBetweenMinMax();

    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << " ";
    }

    a.writeToFile("output.txt");

    return 0;
}