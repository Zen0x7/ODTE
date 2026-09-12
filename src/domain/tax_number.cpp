#include "odte/domain/tax_number.hpp"

#include <cctype>
#include <cstring>

namespace odte::domain {

TaxNumber::TaxNumber(const char* value) {
  ODTE_EXPECTS(value != nullptr);

  const auto len = strnlen(value, kMaxSize + 1);
  if (len < 3 || len > kMaxSize) {
    valid_ = false;
    return;
  }

  std::size_t i = 0;
  while (i < len && std::isdigit(static_cast<unsigned char>(value[i]))) {
    ++i;
  }

  if (i == 0 || i >= len) {
    valid_ = false;
    return;
  }

  if (value[i] != '-') {
    valid_ = false;
    return;
  }

  ++i;
  if (i != len - 1) {
    valid_ = false;
    return;
  }

  if (const char last = value[len - 1];
      !std::isdigit(static_cast<unsigned char>(last)) && last != 'K' &&
      last != 'k') {
    valid_ = false;
    return;
  }

  std::memcpy(data_.data(), value, len);
  data_[len] = '\0';
  valid_ = true;

  ODTE_ENSURES(std::strlen(data_.data()) >= 3);
  invariant();
}

const char* TaxNumber::value() const { return data_.data(); }

bool TaxNumber::is_valid() const { return valid_; }

}  // namespace odte::domain
