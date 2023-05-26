#include <string>
#include <vector>
#include <map>
class rtsClass {
    public:
        std::map<std::string, int> aboveBelow(std::vector<int> integerCollection, int comparisonValue);
        std::string stringRotation(std::string stringToRotate, int numberOfRotations);
        rtsClass();
        rtsClass(bool useStringFunctions_);
    private:
        std::map<std::string, int> comparisonMap;
        std::string rotatedString;
        int stringLength;
        void rotateString();
        bool useStringFunctions;
};
