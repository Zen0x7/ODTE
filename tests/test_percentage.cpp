#include <gtest/gtest.h>

#include "odte/domain/percentage.hpp"

using namespace odte::domain;

TEST(PercentageTest, Valid) {
    Percentage vat_rate(1900);
    EXPECT_TRUE(vat_rate.is_valid());
    EXPECT_EQ(vat_rate.hundredths(), 1900u);
}

TEST(PercentageTest, ZeroInvalid) {
    Percentage rate(0);
    EXPECT_FALSE(rate.is_valid());
}

TEST(PercentageTest, OverMaxInvalid) {
    Percentage rate(100000);
    EXPECT_FALSE(rate.is_valid());
}

TEST(PercentageTest, Comparison) {
    Percentage a(1900);
    Percentage b(500);
    EXPECT_TRUE(b < a);
    EXPECT_TRUE(a > b);
    EXPECT_EQ(a, Percentage(1900));
    EXPECT_NE(a, b);
}
