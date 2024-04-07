#include <algorithm>
#include <cmath>

#include "../include/advancedCalculator.hpp"
#include "gtest/gtest.h"

bool cmp(double first, double second, double epsilon = 0.5) {
    return (fabs(first - second) < epsilon);
}

TEST(advancedCalculatorTest, ShouldAdd) {
    double result = 0;

    ASSERT_EQ(process("5 + 11", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, 16));
    ASSERT_EQ(process("43.21 + 11.54", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, 54.75));
    ASSERT_EQ(process("-54.31 + 11", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, -43.31));
    ASSERT_EQ(process("28.43 +-810.43", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, -782));
    ASSERT_EQ(process("-11.230 + -77.321", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, -88.551));
}

TEST(advancedCalculatorTest, ShouldSubstract) {
    double result = 0;

    ASSERT_EQ(process("5- 11", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, -6));
    ASSERT_EQ(process("43.21 -11.54", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, 31.67));
    ASSERT_EQ(process("-54.31-11", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, -65.31));
    ASSERT_EQ(process("28.43 - -810.43", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, 838.86));
    ASSERT_EQ(process("-11.230 --77.321", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, 66.091));
}

TEST(advancedCalculatorTest, ShouldMultiply) {
    double result = 0;

    ASSERT_EQ(process("5 * 11", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, 55));
    ASSERT_EQ(process("43.21 *11.54", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, 498.643));
    ASSERT_EQ(process("-54.31* 11", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, -597.41));
    ASSERT_EQ(process("28.43 *-810.43", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, -23040.5));
    ASSERT_EQ(process("-11.230*-77.321", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, 868.315));
}

TEST(advancedCalculatorTest, ShouldDivide) {
    double result = 0;

    ASSERT_EQ(process("5 /11", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, 0.454545));
    ASSERT_EQ(process("43.21/ 11.54", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, 3.74437));
    ASSERT_EQ(process("-54.31/11", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, -4.93727));
    ASSERT_EQ(process("28.43 /-810.43", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, -0.0350801));
    ASSERT_EQ(process("-11.230/-77.321", &result), ErrorCode::OK);
    EXPECT_TRUE(cmp(result, 0.145239));
}
