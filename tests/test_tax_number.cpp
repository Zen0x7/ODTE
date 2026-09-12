#include <gtest/gtest.h>

#include "odte/contract.hpp"
#include "odte/domain/tax_number.hpp"

using namespace odte::domain;

TEST(TaxNumberTest, ValidTaxNumber) {
    TaxNumber tax_number("12345678-5");
    EXPECT_TRUE(tax_number.is_valid());
    EXPECT_STREQ(tax_number.value(), "12345678-5");
}

TEST(TaxNumberTest, InvalidTaxNumber) {
    TaxNumber tax_number("12345");
    EXPECT_FALSE(tax_number.is_valid());
}

TEST(TaxNumberTest, EmptyTaxNumber) {
    TaxNumber tax_number("");
    EXPECT_FALSE(tax_number.is_valid());
}

TEST(TaxNumberTest, NullTaxNumber) {
    EXPECT_THROW(TaxNumber(nullptr), odte::contract::violation);
}

TEST(TaxNumberTest, Equality) {
    TaxNumber a("12345678-5");
    TaxNumber b("12345678-5");
    TaxNumber c("87654321-K");
    EXPECT_EQ(a, b);
    EXPECT_NE(a, c);
}

TEST(TaxNumberTest, EqualityWithInvalid) {
    TaxNumber valid("12345678-5");
    TaxNumber invalid("12345");
    EXPECT_FALSE(valid == invalid);
    EXPECT_FALSE(invalid == valid);
    EXPECT_TRUE(valid != invalid);
    EXPECT_TRUE(invalid != valid);
}

TEST(TaxNumberTest, LowercaseK) {
    TaxNumber tax_number("12345678-k");
    EXPECT_TRUE(tax_number.is_valid());
}

TEST(TaxNumberTest, TooLong) {
    TaxNumber tax_number("1234567890-1");
    EXPECT_FALSE(tax_number.is_valid());
}

TEST(TaxNumberTest, NoHyphen) {
    TaxNumber tax_number("123456785");
    EXPECT_FALSE(tax_number.is_valid());
}

TEST(TaxNumberTest, StartsHyphen) {
    TaxNumber tax_number("-12345678");
    EXPECT_FALSE(tax_number.is_valid());
}

TEST(TaxNumberTest, EndsHyphen) {
    TaxNumber tax_number("12345678-");
    EXPECT_FALSE(tax_number.is_valid());
}

TEST(TaxNumberTest, InvalidCheckDigit) {
    TaxNumber tax_number("12345678-X");
    EXPECT_FALSE(tax_number.is_valid());
}

TEST(TaxNumberTest, NonDigitBeforeHyphen) {
    TaxNumber tax_number("12A-5");
    EXPECT_FALSE(tax_number.is_valid());
}
