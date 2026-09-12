#pragma once

#include <cstdint>

namespace odte::domain {

enum class PaymentForm : std::uint8_t {
  CASH = 1,
  CREDIT = 2,
  NO_PAYMENT = 3,
};

const char* to_string(PaymentForm form);

}  // namespace odte::domain
