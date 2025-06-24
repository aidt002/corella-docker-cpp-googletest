#include <iostream>
#include "Calculator.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Calculator calc;
    std::cout << "2 + 2 = " << calc.add(2, 2) << std::endl;
    return 0;
}