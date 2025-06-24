#include <gtest/gtest.h>
#include "Calculator.h"

TEST(CalculatorTest, AddTwoPositive) {
    Calculator calc;
    EXPECT_EQ(calc.add(2, 3), 5);
}

TEST(CalculatorTest, AddNegative) {
    Calculator calc;
    EXPECT_EQ(calc.add(-1, -1), -2);
}

TEST(CalculatorTest, AddMixed) {
    Calculator calc;
    EXPECT_EQ(calc.add(-1, 1), 0);
}