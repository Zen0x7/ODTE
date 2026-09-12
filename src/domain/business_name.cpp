#include "odte/domain/business_name.hpp"

#include <cstring>

namespace odte::domain {

BusinessName::BusinessName(const char* value) {
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

const char* BusinessName::value() const { return data_.data(); }

bool BusinessName::is_valid() const { return valid_; }

}  // namespace odte::domain
