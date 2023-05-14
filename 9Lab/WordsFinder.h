#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

class WordsFinder {
private:

    std::vector<std::string> words;

public:

    WordsFinder() {}

    WordsFinder(const std::vector<std::string>& wordsVec) { 
        words = wordsVec;
    }

    WordsFinder(const std::string& filename) {
        readFromFile(filename);
    }

    WordsFinder(const WordsFinder& other) {
        words = other.words;
    }

    WordsFinder(WordsFinder&& other) noexcept { 
        words = std::move(other.words);
    }

    WordsFinder& operator=(const WordsFinder& other) { 
        if (this != &other) {
            words = other.words;
        }
        return *this;
    }

    WordsFinder& operator=(WordsFinder&& other) noexcept { 
        if (this != &other) {
            words = std::move(other.words);
        }
        return *this;
    }
 
    ~WordsFinder() {}
    
    void addWord(const std::string& word);
    void readFromFile(const std::string& filename);
    void writeToFile(const std::string& filename);
    std::vector<std::string> findWordsBetweenMinMax();
};

