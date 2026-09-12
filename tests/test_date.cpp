#include <gtest/gtest.h>

#include <boost/contract.hpp>

#include "odte/domain/date.hpp"

using namespace odte::domain;

TEST(DateTest, ValidDate) {
    Date date(20240115);
    EXPECT_TRUE(date.is_valid());
    EXPECT_EQ(date.value(), 20240115u);
}

TEST(DateTest, InvalidDate) {
    Date date(20241301);
    EXPECT_FALSE(date.is_valid());
}

TEST(DateTest, LeapYear) {
    Date date(20240229);
    EXPECT_TRUE(date.is_valid());
}

TEST(DateTest, NonLeapYear) {
    Date date(20230229);
    EXPECT_FALSE(date.is_valid());
}

TEST(DateTest, April30) {
    Date date(20240430);
    EXPECT_TRUE(date.is_valid());
}

TEST(DateTest, April31) {
    Date date(20240431);
    EXPECT_FALSE(date.is_valid());
}

TEST(DateTest, FromComponents) {
    Date date = Date::from_components(2024, 1, 15);
    EXPECT_TRUE(date.is_valid());
    EXPECT_EQ(date.year(), 2024);
    EXPECT_EQ(date.month(), 1);
    EXPECT_EQ(date.day(), 15);
}

TEST(DateTest, FromComponentsInvalidDay) {
    EXPECT_THROW(Date::from_components(2024, 4, 31), boost::contract::assertion_failure);
}

TEST(DateTest, Equality) {
    Date a(20240115);
    Date b(20240115);
    Date c(20241225);
    EXPECT_EQ(a, b);
    EXPECT_NE(a, c);
}

TEST(DateTest, Comparison) {
    Date a(20240115);
    Date b(20241225);
    EXPECT_TRUE(a < b);
    EXPECT_TRUE(a <= b);
    EXPECT_TRUE(b > a);
    EXPECT_TRUE(b >= a);
}
