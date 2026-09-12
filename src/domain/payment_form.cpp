#include "odte/domain/payment_form.hpp"

namespace odte::domain {

const char* to_string(PaymentForm form) {
  switch (form) {
    case PaymentForm::CASH:
      return "Cash";
    case PaymentForm::CREDIT:
      return "Credit";
    case PaymentForm::NO_PAYMENT:
      return "No Payment";
  }
  return "No Payment";
}

}  // namespace odte::domain
