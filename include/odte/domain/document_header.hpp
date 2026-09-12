#pragma once

#include <cstdint>

#include "odte/domain/date.hpp"
#include "odte/domain/document_type.hpp"
#include "odte/domain/folio.hpp"
#include "odte/domain/payment_form.hpp"
#include "odte/domain/payment_method.hpp"

namespace odte::domain {

struct DocumentHeader {
  DocumentType document_type{DocumentType::INVOICE};
  Folio folio;
  Date issuance_date;
  PaymentForm payment_form{PaymentForm::CASH};
  PaymentMethod payment_method{PaymentMethod::OTHER};
  Date due_date;
  Date period_start;
  Date period_end;
  bool gross_amounts{false};
  std::uint16_t payment_due_days{0};
};

}  // namespace odte::domain
