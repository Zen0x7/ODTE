#include "odte/domain/document_type.hpp"

namespace odte::domain {

const char* to_string(DocumentType type) {
  switch (type) {
    case DocumentType::INVOICE:
      return "Invoice";
    case DocumentType::EXEMPT_INVOICE:
      return "Exempt Invoice";
    case DocumentType::PURCHASE_INVOICE:
      return "Purchase Invoice";
    case DocumentType::DISPATCH_GUIDE:
      return "Dispatch Guide";
    case DocumentType::DEBIT_NOTE:
      return "Debit Note";
    case DocumentType::CREDIT_NOTE:
      return "Credit Note";
  }
  return "Unknown";
}

}  // namespace odte::domain
