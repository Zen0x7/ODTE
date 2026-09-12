#pragma once

#include <array>
#include <cstdint>

#include "odte/domain/amount.hpp"

namespace odte::domain {

struct SubtotalSummary {
  std::uint32_t sequence_number{0};
  std::array<char, 41> description{};
  std::uint32_t order{0};
  Amount net_amount{0};
  Amount vat_amount{0};
  Amount additional_amount{0};
  Amount exempt_amount{0};
  Amount total_amount{0};
};

}  // namespace odte::domain
