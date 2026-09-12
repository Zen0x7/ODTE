#include <gtest/gtest.h>

#include <string>

#include "odte/contract.hpp"
#include "odte/domain/folio_reference.hpp"

using namespace odte::domain;

TEST(FolioReferenceTest, Valid) {
    FolioReference folio("ABC-123");
    EXPECT_TRUE(folio.is_valid());
    EXPECT_STREQ(folio.value(), "ABC-123");
}

TEST(FolioReferenceTest, Empty) {
    FolioReference folio("");
    EXPECT_FALSE(folio.is_valid());
}

TEST(FolioReferenceTest, TooLong) {
    std::string value(19, 'A');
    FolioReference folio(value.c_str());
    EXPECT_FALSE(folio.is_valid());
}

TEST(FolioReferenceTest, Null) {
    EXPECT_THROW(FolioReference(nullptr), odte::contract::violation);
}

TEST(FolioReferenceTest, Equality) {
    FolioReference a("ABC-123");
    FolioReference b("ABC-123");
    FolioReference c("XYZ-999");
    EXPECT_EQ(a, b);
    EXPECT_NE(a, c);
}

TEST(FolioReferenceTest, EqualityWithInvalid) {
    FolioReference valid("ABC-123");
    FolioReference invalid("");
    EXPECT_FALSE(valid == invalid);
    EXPECT_FALSE(invalid == valid);
    EXPECT_TRUE(valid != invalid);
    EXPECT_TRUE(invalid != valid);
}
