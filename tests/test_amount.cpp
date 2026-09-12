#include <gtest/gtest.h>

#include <limits>

#include "odte/domain/amount.hpp"

using namespace odte::domain;

TEST(AmountTest, ValidAmount) {
    Amount amount(1000000);
    EXPECT_TRUE(amount.is_valid());
    EXPECT_EQ(amount.value(), 1000000);
}

TEST(AmountTest, ZeroAmount) {
    Amount amount(0);
    EXPECT_TRUE(amount.is_valid());
    EXPECT_EQ(amount.value(), 0);
}

TEST(AmountTest, NegativeAmount) {
    Amount amount(-100);
    EXPECT_FALSE(amount.is_valid());
}

TEST(AmountTest, Addition) {
    Amount a(100);
    Amount b(200);
    Amount c = a + b;
    EXPECT_EQ(c.value(), 300);
}

TEST(AmountTest, OverflowThrows) {
    Amount a(std::numeric_limits<std::int64_t>::max());
    Amount b(1);
    EXPECT_THROW(a + b, std::overflow_error);
}

TEST(AmountTest, OverflowAddReturnsFalse) {
    Amount a(std::numeric_limits<std::int64_t>::max());
    Amount b(1);
    Amount result;
    EXPECT_FALSE(a.add(b, result));
}

TEST(AmountTest, Comparison) {
    Amount a(100);
    Amount b(200);
    EXPECT_TRUE(a < b);
    EXPECT_TRUE(a <= b);
    EXPECT_TRUE(b > a);
    EXPECT_TRUE(b >= a);
    EXPECT_TRUE(a == Amount(100));
    EXPECT_TRUE(a >= Amount(100));
    EXPECT_TRUE(a <= Amount(100));
    EXPECT_TRUE(a != Amount(200));
    EXPECT_FALSE(a != Amount(100));
}
