#pragma once

#include <array>

#include "odte/domain/business_name.hpp"
#include "odte/domain/tax_number.hpp"

namespace odte::domain {

struct Recipient {
  TaxNumber tax_number;
  BusinessName business_name;
  std::array<char, 41> activity_type{};
  std::array<char, 81> contact{};
  std::array<char, 81> email{};
  std::array<char, 71> address{};
  std::array<char, 21> commune{};
  std::array<char, 21> city{};
  std::array<char, 71> postal_address{};
  std::array<char, 21> postal_commune{};
  std::array<char, 21> postal_city{};
};

}  // namespace odte::domain
