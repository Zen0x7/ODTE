#pragma once

#include <cstdint>

namespace odte::domain {

enum class DocumentType : std::uint8_t {
  INVOICE = 33,
  EXEMPT_INVOICE = 34,
  PURCHASE_INVOICE = 46,
  DISPATCH_GUIDE = 52,
  DEBIT_NOTE = 56,
  CREDIT_NOTE = 61,
};

const char* to_string(DocumentType type);

}  // namespace odte::domain
