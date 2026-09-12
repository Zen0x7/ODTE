#pragma once

#include <array>
#include <cstddef>

#include "odte/contract.hpp"
#include "odte/domain/amount.hpp"
#include "odte/domain/percentage.hpp"
#include "odte/domain/tax_code.hpp"

namespace odte::domain {

struct WithheldTax {
  TaxCode code{TaxCode::COMMERCIAL_MARGIN_VAT};
  Percentage rate;
  Amount amount{0};
};

struct TotalAmounts {
  static constexpr std::size_t kMaxWithheldTaxes = 20;

  Amount net_amount{0};
  Amount exempt_amount{0};
  Percentage vat_rate;
  Amount vat_amount{0};
  Amount total_amount{0};
  std::array<WithheldTax, kMaxWithheldTaxes> withheld_taxes{};
  std::size_t withheld_tax_count{0};

  bool add_withheld_tax(const WithheldTax& tax) {
    if (withheld_tax_count >= kMaxWithheldTaxes) {
      return false;
    }
    withheld_taxes[withheld_tax_count] = tax;
    ++withheld_tax_count;

    ODTE_ENSURES(withheld_tax_count <= kMaxWithheldTaxes);
    invariant();
    return true;
  }

  void invariant() const {
    ODTE_INVARIANT(withheld_tax_count <= kMaxWithheldTaxes);
  }
};

}  // namespace odte::domain
