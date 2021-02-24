/**
 * @author Maximillian Moundas (maximillian.r.moundas@vanderbilt.edu)
 * @date   02/24/2021
 * @brief  This program takes a number (value >= 0) given by the user and shows the
 *         representation of the value in the decimal, binary and hexadecimal number systems
 *         (excluding the number system the value was given in).
 * @todo   Add comments, add two's complement conversion for binary numbers, add functionality
 *         for negative numbers, add UI, implement into a web application
 */

#include "NumberConverter.h"

int main() {
    NumberConverter numCon;

    numCon.runConverter();

    return 0;
}
