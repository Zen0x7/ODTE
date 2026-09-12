#include "odte/domain/amount.hpp"

namespace odte::domain {

const char* to_string(AmountError error) {
  switch (error) {
    case AmountError::NEGATIVE:
      return "Negative";
    case AmountError::EXCEEDS_SCHEMA_MAX:
      return "Exceeds schema max";
  }
  return "Unknown";
}

Amount::Amount(std::int64_t value) : value_(value) {
  ODTE_EXPECTS(value_ >= 0);
  ODTE_EXPECTS(value_ <= kMaxValue);
  invariant();
}

std::int64_t Amount::value() const noexcept { return value_; }

std::expected<Amount, AmountError> Amount::create(std::int64_t value) {
  if (value < 0) {
    return std::unexpected(AmountError::NEGATIVE);
  }
  if (value > kMaxValue) {
    return std::unexpected(AmountError::EXCEEDS_SCHEMA_MAX);
  }
  return Amount(value);
}

std::expected<Amount, AmountError> Amount::add(const Amount& other) const {
  if (value_ > kMaxValue - other.value_) {
    return std::unexpected(AmountError::EXCEEDS_SCHEMA_MAX);
  }
  return Amount(value_ + other.value_);
}

}  // namespace odte::domain
