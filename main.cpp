#include <iostream>
#include "rtsClass.h"
int main() {

    // declare an instance of rtsClass
    rtsClass* testRTS = new rtsClass();

    // test aboveBelow
    std::vector<int> integerCollection { 1, 5, 2, 1, 10 };
    int comparisonValue = 6;
    std::map<std::string, int> aboveBelowResult;
    aboveBelowResult = testRTS->aboveBelow(integerCollection, comparisonValue);

    // print test output
    std::cout << "test rtsClass::aboveBelow" << std::endl;
    std::cout << "input integer collection:";
    for (auto& num: integerCollection)
        std::cout << " " << num ;
    std::cout << std::endl;
    std::cout << "counts above and below comparisonValue = " << comparisonValue << std::endl;
    std::cout << "above: " << aboveBelowResult["above"] << std::endl;
    std::cout << "below: " << aboveBelowResult["below"] << std::endl;
    std::cout << std::endl;

    // test stringRotation
    std::string stringToRotate = "MyString";
    int numberOfRotations = 10;
    std::string rotatedString;
    rotatedString = testRTS->stringRotation(stringToRotate, numberOfRotations);

    // print test output
    std::cout << "test rtsClass::stringRotation" << std::endl;
    std::cout << "rotate \"" << stringToRotate << "\" by " << numberOfRotations << std::endl;
    std::cout << "rotated: " << rotatedString << std::endl;

    delete testRTS;

    return 0;
}
