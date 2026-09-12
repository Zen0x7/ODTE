#include "odte/domain/folio_reference.hpp"

#include <cstring>

namespace odte::domain {

FolioReference::FolioReference(const char* value) {
  ODTE_EXPECTS(value != nullptr);

  const auto len = strnlen(value, kMaxSize + 1);
  if (len == 0 || len > kMaxSize) {
    valid_ = false;
    return;
  }

  std::memcpy(data_.data(), value, len);
  data_[len] = '\0';
  valid_ = true;

  ODTE_ENSURES(std::strlen(data_.data()) <= kMaxSize);
  invariant();
}

const char* FolioReference::value() const { return data_.data(); }

bool FolioReference::is_valid() const { return valid_; }

}  // namespace odte::domain
