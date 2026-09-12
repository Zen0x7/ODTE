#include <gtest/gtest.h>

#include "odte/contract.hpp"
#include "odte/domain/amount.hpp"

using namespace odte::domain;

TEST(AmountTest, ValidAmount) {
    Amount amount(1000000);
    EXPECT_EQ(amount.value(), 1000000);
}

TEST(AmountTest, ZeroAmount) {
    Amount amount(0);
    EXPECT_EQ(amount.value(), 0);
}

TEST(AmountTest, NegativeAmountThrows) {
    EXPECT_THROW(Amount(-100), odte::contract::violation);
}

TEST(AmountTest, AboveSchemaMaxThrows) {
    EXPECT_THROW(Amount(Amount::kMaxValue + 1), odte::contract::violation);
}

TEST(AmountTest, CreateValid) {
    auto amount = Amount::create(1000);
    ASSERT_TRUE(amount.has_value());
    EXPECT_EQ(amount->value(), 1000);
}

TEST(AmountTest, CreateNegative) {
    auto amount = Amount::create(-1);
    ASSERT_FALSE(amount.has_value());
    EXPECT_EQ(amount.error(), AmountError::NEGATIVE);
}

TEST(AmountTest, CreateAboveSchemaMax) {
    auto amount = Amount::create(Amount::kMaxValue + 1);
    ASSERT_FALSE(amount.has_value());
    EXPECT_EQ(amount.error(), AmountError::EXCEEDS_SCHEMA_MAX);
}

TEST(AmountTest, Addition) {
    auto sum = Amount(100) + Amount(200);
    ASSERT_TRUE(sum.has_value());
    EXPECT_EQ(sum->value(), 300);
}

TEST(AmountTest, AdditionWithZero) {
    auto sum = Amount(0) + Amount(100);
    ASSERT_TRUE(sum.has_value());
    EXPECT_EQ(sum->value(), 100);

    sum = Amount(100) + Amount(0);
    ASSERT_TRUE(sum.has_value());
    EXPECT_EQ(sum->value(), 100);
}

TEST(AmountTest, AdditionAtSchemaMax) {
    auto sum = Amount(Amount::kMaxValue - 1) + Amount(1);
    ASSERT_TRUE(sum.has_value());
    EXPECT_EQ(sum->value(), Amount::kMaxValue);
}

TEST(AmountTest, AdditionExceedsSchemaMax) {
    auto sum = Amount(Amount::kMaxValue) + Amount(1);
    ASSERT_FALSE(sum.has_value());
    EXPECT_EQ(sum.error(), AmountError::EXCEEDS_SCHEMA_MAX);
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

TEST(AmountErrorTest, ToString) {
    EXPECT_STREQ(to_string(AmountError::NEGATIVE), "Negative");
    EXPECT_STREQ(to_string(AmountError::EXCEEDS_SCHEMA_MAX), "Exceeds schema max");
    EXPECT_STREQ(to_string(static_cast<AmountError>(99)), "Unknown");
}
