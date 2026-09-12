#pragma once

#include <array>
#include <cstdint>

#include "odte/domain/date.hpp"
#include "odte/domain/folio_reference.hpp"
#include "odte/domain/tax_number.hpp"

namespace odte::domain {

enum class ReferenceCode : std::uint8_t {
  CANCELS = 1,
  CORRECTS_TEXT = 2,
  CORRECTS_AMOUNTS = 3,
};

struct Reference {
  std::uint32_t sequence_number{0};
  std::array<char, 4> document_type{};
  bool global{false};
  FolioReference folio;
  TaxNumber other_tax_number;
  Date date;
  ReferenceCode code{ReferenceCode::CANCELS};
  std::array<char, 91> reason{};
};

}  // namespace odte::domain
