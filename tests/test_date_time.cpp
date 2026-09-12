#include <gtest/gtest.h>

#include "odte/domain/date_time.hpp"

using namespace odte::domain;

TEST(DateTimeTest, Valid) {
    DateTime timestamp(Date(20240115), 12, 30, 45);
    EXPECT_TRUE(timestamp.is_valid());
    EXPECT_EQ(timestamp.date(), Date(20240115));
    EXPECT_EQ(timestamp.hour(), 12);
    EXPECT_EQ(timestamp.minute(), 30);
    EXPECT_EQ(timestamp.second(), 45);
}

TEST(DateTimeTest, InvalidHour) {
    DateTime timestamp(Date(20240115), 24, 0, 0);
    EXPECT_FALSE(timestamp.is_valid());
}

TEST(DateTimeTest, InvalidMinute) {
    DateTime timestamp(Date(20240115), 10, 60, 0);
    EXPECT_FALSE(timestamp.is_valid());
}

TEST(DateTimeTest, InvalidSecond) {
    DateTime timestamp(Date(20240115), 10, 0, 60);
    EXPECT_FALSE(timestamp.is_valid());
}

TEST(DateTimeTest, InvalidDate) {
    DateTime timestamp(Date(20241301), 10, 0, 0);
    EXPECT_FALSE(timestamp.is_valid());
}

TEST(DateTimeTest, Equality) {
    DateTime a(Date(20240115), 10, 0, 0);
    DateTime b(Date(20240115), 10, 0, 0);
    DateTime c(Date(20240115), 11, 0, 0);
    EXPECT_EQ(a, b);
    EXPECT_NE(a, c);
    EXPECT_FALSE(a == c);
    EXPECT_FALSE(a != b);
}

TEST(DateTimeTest, EqualityBranches) {
    DateTime base(Date(20240115), 10, 0, 0);
    EXPECT_NE(base, DateTime(Date(20240116), 10, 0, 0));
    EXPECT_NE(base, DateTime(Date(20240115), 10, 1, 0));
    EXPECT_NE(base, DateTime(Date(20240115), 10, 0, 1));
}

TEST(DateTimeTest, Comparison) {
    DateTime a(Date(20240115), 10, 0, 0);
    DateTime b(Date(20240116), 10, 0, 0);
    DateTime c(Date(20240115), 11, 0, 0);
    DateTime d(Date(20240115), 10, 1, 0);
    DateTime e(Date(20240115), 10, 0, 1);
    EXPECT_TRUE(a < b);
    EXPECT_TRUE(a < c);
    EXPECT_TRUE(a < d);
    EXPECT_TRUE(a < e);
}
