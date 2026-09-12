#pragma once

#include <array>
#include <cstddef>
#include <cstdint>

#include "odte/domain/business_name.hpp"
#include "odte/domain/tax_number.hpp"

namespace odte::domain {

struct Issuer {
  TaxNumber tax_number;
  BusinessName business_name;
  std::array<char, 81> activity_type{};
  std::array<char, 21> phone{};
  std::array<char, 81> email{};
  std::array<char, 71> origin_address{};
  std::array<char, 21> origin_commune{};
  std::array<char, 21> origin_city{};
  std::array<char, 21> branch{};
  std::array<char, 61> seller_code{};
  std::array<char, 21> additional_id{};
  std::array<std::uint32_t, 4> economic_activities{};
  std::size_t economic_activity_count{0};
};

}  // namespace odte::domain
