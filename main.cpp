#include <iostream>
#include <string>
#include <iomanip>
#include "interest.h"
using namespace std;

int main() {
    // Declares calculator as an object of the InterestCalculator class
    InterestCalculator calculator;

    // Displays input to get data from user
    calculator.DisplayDataInput();
    // Displays interest output for user
    calculator.OutputWithoutDeposit();
    calculator.OutputWithDeposit();

    return 0;
}
