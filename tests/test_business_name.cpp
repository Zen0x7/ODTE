#include <gtest/gtest.h>

#include <boost/contract.hpp>

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

TEST(BusinessNameTest, Null) {
    EXPECT_THROW(BusinessName(nullptr), boost::contract::assertion_failure);
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
