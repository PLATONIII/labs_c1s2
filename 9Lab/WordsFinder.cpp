#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <limits>
#include <string>
#include "WordsFinder.h"

void WordsFinder::addWord(const std::string& word) {
    words.push_back(word);
}

void WordsFinder::readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string word;
    while (file >> word) {
        addWord(word);
    }
    file.close();
}

void WordsFinder::writeToFile(const std::string& filename) {
    std::ofstream file(filename);
    std::vector<std::string> result = findWordsBetweenMinMax();
    for (const auto word : result) {
        file << word << " ";
    }
    file.close();
}

int getDigitalForm(const std::string& _word){
    int _val = 0;
    for (const char letter : _word) 
        if (isalpha(letter)) 
            _val += std::tolower(letter) - 'a' + 1;
    return _val;
}

std::vector<std::string> WordsFinder::findWordsBetweenMinMax() {

    int min_val = std::numeric_limits<int>::max();
    int max_val = std::numeric_limits<int>::min();
    for (auto word : words) {
        int val = getDigitalForm(word);
        min_val = std::min(min_val, val);
        max_val = std::max(max_val, val);
    }
    std::vector<std::string> result;
    auto min_iter = std::find_if(words.begin(), words.end(), [min_val](const std::string& word) {
        int val = getDigitalForm(word);
        return val == min_val;
    });

    auto max_iter = std::find_if(words.begin(), words.end(), [max_val](const std::string& word) {
        int val = getDigitalForm(word);
        return val == max_val;
    });

    if (min_iter < max_iter) {
        result = std::vector<std::string>(min_iter + 1, max_iter);
    } else if (min_iter > max_iter) {
       result = std::vector<std::string>(max_iter + 1, min_iter);
    }
    return result;
}