#include <iostream>
#include "rtsClass.h"

// default constructor
rtsClass::rtsClass() {
    this->useStringFunctions = true;
}

// constructor with flag for whether or not to use std::string functions
rtsClass::rtsClass(bool useStringFunctions_) {
    useStringFunctions = useStringFunctions_;
}

// aboveBelow
// - accepts two arguments:
//     - An unsorted collection of integers (the list)
//     - an integer (the comparison value)
//     - returns a hash/object/map/etc. with the keys "above" and "below" with the corresponding count of integers from the list that are above or below the comparison value
// - Example usage:
//     - input: [1, 5, 2, 1, 10], 6
//     - output: { "above": 1, "below": 4 }
std::map<std::string, int> rtsClass::aboveBelow(std::vector<int> integerCollection, int comparisonValue) {

    this->comparisonMap["above"] = 0;
    this->comparisonMap["below"] = 0;

    for (auto& num : integerCollection) {
        if (num > comparisonValue)
            comparisonMap["above"]++;
        if (num < comparisonValue)
            comparisonMap["below"]++;
    }

    return this->comparisonMap;
}

// stringRotation
// - accepts two arguments
//     - a string (the original string)
//     - a positive integer (the rotation amount)
// - returns a new string, rotating the characters in the original string to the right by the rotation amount and have the overflow appear at the beginning
// - Example usage:
//     - input: "MyString", 2
//     - output: "ngMyStri"
std::string rtsClass::stringRotation(std::string stringToRotate, int numberOfRotations) {

    // Check if numberOfRotations is a positive int
    // Another version of this might use negative ints for rotations to the left as the convention.
    if (numberOfRotations < 1)
        throw std::invalid_argument("numberOfRotations should be a positive integer.");

    // Get string length
    this->stringLength = sizeof(stringToRotate.data());

    // If numberOfRotations > stringLength, we can skip rotations that would
    // give us the original string back
    numberOfRotations = numberOfRotations % this->stringLength;


    this->rotatedString = stringToRotate;
    while(numberOfRotations-- > 0)
        this->rotateString();

    return this->rotatedString;
}

// rotateString
// - rotates string to the right by one position
void rtsClass::rotateString() {

    if (this->useStringFunctions) {
        // Asuming we can use std::string functions
        this->rotatedString = this->rotatedString.back() +
            this->rotatedString.substr(0, rotatedString.length()-1);

    } else {
        // If you prefer a solution not using any standard library functions, the
        // block below will accomplish the same thing, treating rotatedString more
        // like an array of chars than a std::string.

        // keep the last char so we can insert it at the beginning
        char lastChar = this->rotatedString[this->stringLength-1];
        // bump each char to the right by one index
        for (int n=this->stringLength-1; n>=0; n--) {
             this->rotatedString[n+1] = this->rotatedString[n];
        }
        this->rotatedString[0] = lastChar;
    }
}
