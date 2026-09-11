#include "odte/domain/payment_method.hpp"

namespace odte::domain {

const char* to_string(PaymentMethod method) {
  switch (method) {
    case PaymentMethod::CHECK:
      return "Check";
    case PaymentMethod::PROMISSORY_NOTE:
      return "Promissory Note";
    case PaymentMethod::CASH:
      return "Cash";
    case PaymentMethod::ACCOUNT_RECEIVABLE:
      return "Account Receivable";
    case PaymentMethod::CREDIT_CARD:
      return "Credit Card";
    case PaymentMethod::POST_DATED_CHECK:
      return "Post-Dated Check";
    case PaymentMethod::OTHER:
      return "Other";
  }
  return "Other";
}

}  // namespace odte::domain
