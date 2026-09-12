#include <gtest/gtest.h>

#include "odte/domain/total_amounts.hpp"

using namespace odte::domain;

TEST(TotalAmountsTest, AddWithheldTax) {
    TotalAmounts totals;
    WithheldTax tax;
    tax.code = TaxCode::PARTIAL_WITHHELD_VAT;
    tax.amount = Amount(500);
    EXPECT_TRUE(totals.add_withheld_tax(tax));
    EXPECT_EQ(totals.withheld_tax_count, 1u);
}

TEST(TotalAmountsTest, AddWithheldTaxOverflow) {
    TotalAmounts totals;
    totals.withheld_tax_count = TotalAmounts::kMaxWithheldTaxes;
    EXPECT_FALSE(totals.add_withheld_tax(WithheldTax{}));
}
