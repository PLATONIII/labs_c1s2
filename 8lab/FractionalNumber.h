#pragma once

#include<iostream>
#include<cmath>
#include<cstdlib>
#include"Exception.h"

class FractionalNumber {
    int numerator;
    int denominator;

public:

    FractionalNumber(int num = 0, int den = 1) : numerator(num), denominator(den) {
        denExcept();
    }

    ~FractionalNumber() {}

    friend std::ostream& operator<<(std::ostream& out, const FractionalNumber& f) {
        out << f.numerator << "/" << f.denominator;
        return out;
    }

    friend std::istream& operator>>(std::istream& in, FractionalNumber& f) {
        std::cout << "Enter the numerator: ";
        in >> f.numerator;

        std::cout << "Enter the denominator: ";
        if (!(in >> f.denominator)) {
            throw InvalidInputException("InvalidInputException");
        }
        f.denExcept();
        return in;
    }

    FractionalNumber operator+(const FractionalNumber& f) {
        int num = numerator * f.denominator + f.numerator * denominator;
        int den = denominator * f.denominator;
        reduce(num, den);
        return FractionalNumber(num, den);
    }

    FractionalNumber operator-(const FractionalNumber& f) {
        int num = numerator * f.denominator - f.numerator * denominator;
        int den = denominator * f.denominator;
        reduce(num, den);
        return FractionalNumber(num, den);
    }

    FractionalNumber operator*(const FractionalNumber& f) {
        int num = numerator * f.numerator;
        int den = denominator * f.denominator;
        reduce(num, den);
        return FractionalNumber(num, den);
    }

    FractionalNumber operator*(const double value) {
        int num = numerator * value;
        int den = denominator;
        reduce(num, den);
        return FractionalNumber(num, den);
    }

    FractionalNumber operator/(const FractionalNumber& f)  {
        int num = numerator * f.denominator;
        int den = denominator * f.numerator;
        reduce(num, den);
        return FractionalNumber(num, den);
    }

    bool operator==(const FractionalNumber& f) const {
        return numerator * f.denominator == f.numerator * denominator;
    }

    bool operator!=(const FractionalNumber& f) const {
        return !(*this == f);
    }

    bool operator<(const FractionalNumber& f) const {
        return numerator * f.denominator < f.numerator * denominator;
    }

    bool operator>(const FractionalNumber& f) const {
        return numerator * f.denominator > f.numerator * denominator;
    }

    bool operator<=(const FractionalNumber& f) const {
        return *this < f || *this == f;
    }

    bool operator>=(const FractionalNumber& f) const {
        return *this > f || *this == f;
    }

    FractionalNumber operator=(const int value) {
        return FractionalNumber(value, 1);
    }

    void denExcept() {
        bool done = true;
        if (denominator == 0)
            done = false;
        while (!done) {
            try {
                if (denominator == 0) {
                    throw DenominatorEqualZero("DenominatorEqualZero");
                }
                done = true;
            }
            catch (const DenominatorEqualZero& e) {
                std::cout << "Write against: " << std::endl;
                std::cin >> denominator;
            }
        }
    }
    
    void reduce(int& _num, int& _den) {
        int gcd = findGCD(_num, _den);
        _num /= gcd;
        _den /= gcd;
    }

    int findGCD(int a, int b) {
        return b == 0 ? a : findGCD(b, a % b);
    }


};