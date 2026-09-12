#pragma once

#include <array>
#include <cstddef>
#include <cstdint>

#include "odte/domain/amount.hpp"
#include "odte/domain/percentage.hpp"
#include "odte/domain/tax_code.hpp"

namespace odte::domain {

struct ItemCode {
  std::array<char, 11> type{};
  std::array<char, 36> value{};
};

struct LineItem {
  std::uint32_t sequence_number{0};
  std::array<ItemCode, 5> codes{};
  std::size_t code_count{0};
  std::array<char, 81> description{};
  std::array<char, 1001> extended_description{};
  std::uint32_t quantity{0};
  std::array<char, 5> unit{};
  Amount unit_price{0};
  Percentage discount_percentage;
  Amount discount_amount{0};
  Percentage surcharge_percentage;
  Amount surcharge_amount{0};
  std::array<TaxCode, 2> tax_codes{};
  std::size_t tax_code_count{0};
  Amount line_total{0};
};

}  // namespace odte::domain
