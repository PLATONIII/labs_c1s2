#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>

class BaseException : public std::exception {
public:
    BaseException(const std::string& message1) : message_(message1) {
        message();
    }
    virtual ~BaseException() {}

    void message() const {
        std::ofstream logFile("errors_log.txt", std::ios::app);
        logFile << "Error: " << message_ << std::endl;
        logFile.close();
        std::cerr << "\nError: " << message_ << std::endl;
    }

private:
    std::string message_;
};

class InvalidInputException : public BaseException {
public:
    InvalidInputException(const std::string& message) : BaseException(message) {}
};

class IndexOutOfRange : public BaseException {
public:
    IndexOutOfRange(const std::string& message) : BaseException(message) {}
};

class StrCountNotEquelColumnCount : public BaseException {
public:
    StrCountNotEquelColumnCount(const std::string& message) : BaseException(message) {}
};

class DenominatorEqualZero : public BaseException {
public:
    DenominatorEqualZero(const std::string& message) : BaseException(message) {}
};

class FileException : public BaseException {
public:
    FileException(const std::string& message) : BaseException(message) {}
    virtual ~FileException() {}
};

class FileNotFoundException : public FileException {
public:
    FileNotFoundException(const std::string& message) : FileException(message) {}
};

class FileReadException : public FileException {
public: 
    FileReadException(const std::string& message) : FileException(message) {}
};