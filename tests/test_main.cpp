#include <gtest/gtest.h>

#include "odte/version.hpp"

TEST(VersionTest, GetVersionReturnsExpectedValue) {
    auto v = odte::get_version();
    EXPECT_EQ(v, "0.0.0");
}
