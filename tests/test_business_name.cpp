#include <gtest/gtest.h>

#include <string>

#include "odte/contract.hpp"
#include "odte/domain/business_name.hpp"

using namespace odte::domain;

TEST(BusinessNameTest, Valid) {
    BusinessName name("Acme Corp");
    EXPECT_TRUE(name.is_valid());
    EXPECT_STREQ(name.value(), "Acme Corp");
}

TEST(BusinessNameTest, Empty) {
    BusinessName name("");
    EXPECT_FALSE(name.is_valid());
}

TEST(BusinessNameTest, TooLong) {
    std::string value(101, 'A');
    BusinessName name(value.c_str());
    EXPECT_FALSE(name.is_valid());
}

TEST(BusinessNameTest, Null) {
    EXPECT_THROW(BusinessName(nullptr), odte::contract::violation);
}

TEST(BusinessNameTest, Equality) {
    BusinessName a("Acme Corp");
    BusinessName b("Acme Corp");
    BusinessName c("Other Corp");
    EXPECT_TRUE(a == b);
    EXPECT_TRUE(a != c);
    EXPECT_FALSE(a == c);
    EXPECT_FALSE(a != b);
}

TEST(BusinessNameTest, EqualityWithInvalid) {
    BusinessName valid("Acme Corp");
    BusinessName invalid("");
    EXPECT_FALSE(valid == invalid);
    EXPECT_FALSE(invalid == valid);
    EXPECT_TRUE(valid != invalid);
    EXPECT_TRUE(invalid != valid);
}
