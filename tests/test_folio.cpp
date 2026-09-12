#include <gtest/gtest.h>

#include "odte/domain/folio.hpp"

using namespace odte::domain;

TEST(FolioTest, ValidFolio) {
    Folio folio(1);
    EXPECT_TRUE(folio.is_valid());
    EXPECT_EQ(folio.value(), 1);
}

TEST(FolioTest, InvalidFolio) {
    Folio folio(0);
    EXPECT_FALSE(folio.is_valid());
}

TEST(FolioTest, MaxFolio) {
    Folio folio(9999999999LL);
    EXPECT_TRUE(folio.is_valid());
}

TEST(FolioTest, OverMaxFolio) {
    Folio folio(10000000000LL);
    EXPECT_FALSE(folio.is_valid());
}

TEST(FolioTest, Comparison) {
    Folio a(1);
    Folio b(2);
    EXPECT_TRUE(a < b);
    EXPECT_TRUE(a <= b);
    EXPECT_TRUE(b > a);
    EXPECT_TRUE(b >= a);
    EXPECT_TRUE(a == Folio(1));
    EXPECT_TRUE(a != Folio(2));
    EXPECT_FALSE(a == Folio(2));
    EXPECT_FALSE(a != Folio(1));
}
