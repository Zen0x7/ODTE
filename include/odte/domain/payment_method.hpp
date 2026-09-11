#pragma once

#include <cstdint>

namespace odte::domain {

enum class PaymentMethod : std::uint8_t {
  CHECK = 0,
  PROMISSORY_NOTE = 1,
  CASH = 2,
  ACCOUNT_RECEIVABLE = 3,
  CREDIT_CARD = 4,
  POST_DATED_CHECK = 5,
  OTHER = 6,
};

const char* to_string(PaymentMethod method);

}  // namespace odte::domain
