/**
 * @author Maximillian Moundas (maximillian.r.moundas@vanderbilt.edu)
 * @date   2/24/2021
 */

#include "NumberConverter.h"

NumberConverter::NumberConverter() : decimalNum(0), binaryNum(), hexNum()
{

}

NumberConverter::~NumberConverter()
{

}

void NumberConverter::printInitialUserPrompt() const
{
    std::string message = "What number system is your input from?\n";
    message += "Enter 1 for decimal\n";
    message += "Enter 2 for binary\n";
    message += "Enter 3 for hexadecimal\n";

    std::cout << message;
}

// utilizes <limits>
uint32_t NumberConverter::getConverterType() const
{
    printInitialUserPrompt();

    int userInput;

    while (!(std::cin >> userInput) || (userInput < 1 || userInput > 3)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter a valid number between 1 and 3" << std::endl;
    }

    return uint32_t(userInput);
}

void NumberConverter::getDecimalNum()
{
    std::cout << "Enter a decimal number >= 0" << std::endl;

    int input;

    while (!(std::cin >> input) || input < 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter a valid decimal number >= 0" << std::endl;
    }

    this->decimalNum = uint32_t(input);
}

void NumberConverter::getBinaryNum()
{
    std::cout << "Enter a binary number >= 0" << std::endl;

    std::string input;

    std::cin >> input;

    for (char i : input) {
        if (i != '0' && i != '1') {
            return getBinaryNum();
        }
    }

    uint32_t numLeadingZeros = input.length() % 4;
    while (numLeadingZeros < 4 && numLeadingZeros != 0) {
        binaryNum.push('0');
        ++numLeadingZeros;
    }

    for (uint32_t i = 0; i < input.length(); ++i) {
        binaryNum.push(input.at(i));
    }
}

void NumberConverter::getHexNum()
{
    std::cout << "Enter a hexadecimal number >= 0" << std::endl;
    std::string input;
    std::cin >> input;

    for (char i : input) {
        if (i != '0' && i != '1' && i != '2' && i != '3' && i != '4' && i != '5' && i != '6'
            && i != '7' && i != '8' && i != '9' && i != 'A' && i != 'B' && i != 'C' &&
            i != 'D' && i != 'E' && i != 'F') {
            return getHexNum();
        }
    }

    for (uint32_t i = 0; i < input.length(); ++i) {
        hexNum.push(input.at(i));
    }
}

void NumberConverter::printDecimalNum() const
{
    std::cout << this->decimalNum;
}

void NumberConverter::printBinaryNum() const
{
    uint32_t origSize = binaryNum.size();
    for (std::queue<char> tmp = binaryNum; !tmp.empty(); tmp.pop()) {
        if ((tmp.size() % 4 == 0) && (tmp.size() != origSize)) {
            std::cout << " ";
        }
        std::cout << tmp.front();
    }
}

void NumberConverter::printHexNum() const
{
    for (std::queue<char> tmp = hexNum; !tmp.empty(); tmp.pop()) {
        std::cout << tmp.front();
    }
}

std::queue<char> NumberConverter::decimalToBinary() const
{
    uint32_t tmpDecimalNum = decimalNum;
    std::stack<char> list;
    std::queue<char> output;

    if (tmpDecimalNum == 0) {
        list.push('0');
    }
    else {
        while (tmpDecimalNum > 0) {
            uint32_t tmp = tmpDecimalNum % 2;
            tmpDecimalNum = tmpDecimalNum / 2;

            if (tmp == 1) {
                list.push('1');
            }
            else {
                list.push('0');
            }
        }
    }

    int numLeadingZeros = list.size() % 4;
    while (numLeadingZeros < 4 && numLeadingZeros != 0) {
        list.push('0');
        ++numLeadingZeros;
    }

    while (!list.empty()) {
        output.push(list.top());
        list.pop();
    }

    /*
    for (std::queue<char> tmp = output; !tmp.empty(); tmp.pop()) {
        std::cout << tmp.front();
    }
    std::cout << std::endl;
     */

    return output;
}

// utilizes <cmath>
uint32_t NumberConverter::binaryToDecimal() const
{
    uint32_t output = 0;

    for (std::queue<char> tmp = binaryNum; !tmp.empty(); tmp.pop()) {
        if (tmp.front() == '1') {
            output += pow(2, tmp.size() - 1);
        }
    }
    //std::cout << output << std::endl;

    return output;
}

std::queue<char> NumberConverter::binaryToHex() const
{
    std::string halfByte = "";
    std::queue<char> tmp = binaryNum;
    std::queue<char> output;

    while (!tmp.empty()) {
        for (uint32_t i = 0; i < 4; ++i) {
            halfByte += tmp.front();
            tmp.pop();
        }

        if (halfByte == "0000") {
            output.push('0');
        }
        else if (halfByte == "0001") {
            output.push('1');
        }
        else if (halfByte == "0010") {
            output.push('2');
        }
        else if (halfByte == "0011") {
            output.push('3');
        }
        else if (halfByte == "0100") {
            output.push('4');
        }
        else if (halfByte == "0101") {
            output.push('5');
        }
        else if (halfByte == "0110") {
            output.push('6');
        }
        else if (halfByte == "0111") {
            output.push('7');
        }
        else if (halfByte == "1000") {
            output.push('8');
        }
        else if (halfByte == "1001") {
            output.push('9');
        }
        else if (halfByte == "1010") {
            output.push('A');
        }
        else if (halfByte == "1011") {
            output.push('B');
        }
        else if (halfByte == "1100") {
            output.push('C');
        }
        else if (halfByte == "1101") {
            output.push('D');
        }
        else if (halfByte == "1110") {
            output.push('E');
        }
        else if (halfByte == "1111") {
            output.push('F');
        }

        halfByte = "";
    }

    /*
    for (std::queue<char> tmp = output; !tmp.empty(); tmp.pop()) {
        std::cout << tmp.front();
    }
    std::cout << std::endl;
     */

    return output;
}

std::queue<char> NumberConverter::hexToBinary() const
{
    std::queue<char> tmp = hexNum;
    std::queue<char> output;

    while (!tmp.empty()) {
        switch (tmp.front()) {
            case '0':
                output.push('0');
                output.push('0');
                output.push('0');
                output.push('0');
                break;
            case '1':
                output.push('0');
                output.push('0');
                output.push('0');
                output.push('1');
                break;
            case '2':
                output.push('0');
                output.push('0');
                output.push('1');
                output.push('0');
                break;
            case '3':
                output.push('0');
                output.push('0');
                output.push('1');
                output.push('1');
                break;
            case '4':
                output.push('0');
                output.push('1');
                output.push('0');
                output.push('0');
                break;
            case '5':
                output.push('0');
                output.push('1');
                output.push('0');
                output.push('1');
                break;
            case '6':
                output.push('0');
                output.push('1');
                output.push('1');
                output.push('0');
                break;
            case '7':
                output.push('0');
                output.push('1');
                output.push('1');
                output.push('1');
                break;
            case '8':
                output.push('1');
                output.push('0');
                output.push('0');
                output.push('0');
                break;
            case '9':
                output.push('1');
                output.push('0');
                output.push('0');
                output.push('1');
                break;
            case 'A':
                output.push('1');
                output.push('0');
                output.push('1');
                output.push('0');
                break;
            case 'B':
                output.push('1');
                output.push('0');
                output.push('1');
                output.push('1');
                break;
            case 'C':
                output.push('1');
                output.push('1');
                output.push('0');
                output.push('0');
                break;
            case 'D':
                output.push('1');
                output.push('1');
                output.push('0');
                output.push('1');
                break;
            case 'E':
                output.push('1');
                output.push('1');
                output.push('1');
                output.push('0');
                break;
            case 'F':
                output.push('1');
                output.push('1');
                output.push('1');
                output.push('1');
                break;

            default:
                throw;
        }
        tmp.pop();
    }

    /*
    for (std::queue<char> tmp = output; !tmp.empty(); tmp.pop()) {
        std::cout << tmp.front();
    }
    std::cout << std::endl;
     */

    return output;
}


std::queue<char> NumberConverter::decimalToHex()
{
    binaryNum = decimalToBinary();
    return binaryToHex();
}

uint32_t NumberConverter::hexToDecimal()
{
    binaryNum = hexToBinary();
    return binaryToDecimal();
}

void NumberConverter::runConverter()
{
    uint32_t typeNumSystem = getConverterType();

    switch (typeNumSystem) {
        // decimal input
        case 1:
            getDecimalNum();

            printDecimalNum();
            std::cout << " in binary is:";
            for (std::queue<char> tmp = decimalToBinary(); !tmp.empty(); tmp.pop()) {
                if (tmp.size() % 4 == 0) {
                    std::cout << " ";
                }
                std::cout << tmp.front();
            }
            std::cout << std::endl;

            printDecimalNum();
            std::cout << " in hexadecimal is: ";
            for (std::queue<char> tmp = decimalToHex(); !tmp.empty(); tmp.pop()) {
                std::cout << tmp.front();
            }
            std::cout << std::endl;

            break;
        // binary input
        case 2:
            getBinaryNum();

            printBinaryNum();
            std::cout << " in decimal is: ";
            std::cout << binaryToDecimal() << std::endl;

            printBinaryNum();
            std::cout << " in hexadecimal is: ";
            for (std::queue<char> tmp = binaryToHex(); !tmp.empty(); tmp.pop()) {
                std::cout << tmp.front();
            }
            std::cout << std::endl;

            break;
        // hex input
        case 3:
            getHexNum();

            printHexNum();
            std::cout << " in decimal is: ";
            std::cout << hexToDecimal() << std::endl;

            printHexNum();
            std::cout << " in binary is:";
            for (std::queue<char> tmp = hexToBinary(); !tmp.empty(); tmp.pop()) {
                if (tmp.size() % 4 == 0) {
                    std::cout << " ";
                }
                std::cout << tmp.front();
            }
            std::cout << std::endl;

            break;
    }
}











