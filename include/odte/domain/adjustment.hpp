#pragma once

#include <array>
#include <cstdint>

#include "odte/domain/amount.hpp"
#include "odte/domain/percentage.hpp"

namespace odte::domain {

enum class AdjustmentMovement : std::uint8_t {
  DISCOUNT = 0,
  SURCHARGE = 1,
};

enum class AdjustmentValueType : std::uint8_t {
  PERCENTAGE = 0,
  AMOUNT = 1,
};

struct Adjustment {
  std::uint32_t sequence_number{0};
  AdjustmentMovement movement{AdjustmentMovement::DISCOUNT};
  std::array<char, 46> description{};
  AdjustmentValueType value_type{AdjustmentValueType::AMOUNT};
  Percentage percentage;
  Amount amount{0};
  bool exempt{false};
};

}  // namespace odte::domain
