/**
 * @author Maximillian Moundas (maximillian.r.moundas@vanderbilt.edu)
 * @date   2/24/2021
 */

#ifndef NUMBER_SYSTEMS_CONVERTER_NUMBERCONVERTER_H
#define NUMBER_SYSTEMS_CONVERTER_NUMBERCONVERTER_H

#include <string>
#include <iostream>
#include <limits>
#include <stack>
#include <queue>
#include <cmath>

class NumberConverter {
public:
    NumberConverter();
    NumberConverter(const NumberConverter& rhs) = delete;
    const NumberConverter& operator=(const NumberConverter& rhs) = delete;
    ~NumberConverter();

    void runConverter();

private:
    void printInitialUserPrompt() const;
    uint32_t getConverterType() const;

    void getDecimalNum();
    void getBinaryNum();
    void getHexNum();

    void printDecimalNum() const;
    void printBinaryNum() const;
    void printHexNum() const;

    std::queue<char> decimalToBinary() const;
    std::queue<char> decimalToHex();

    uint32_t binaryToDecimal() const;
    std::queue<char> binaryToHex() const;

    uint32_t hexToDecimal();
    std::queue<char> hexToBinary() const;

    // Data members
    uint32_t decimalNum;
    std::queue<char> binaryNum;
    std::queue<char> hexNum;
};

#endif //NUMBER_SYSTEMS_CONVERTER_NUMBERCONVERTER_H
