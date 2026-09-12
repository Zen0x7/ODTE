#pragma once

#include <cstdint>
#include <expected>

#include "odte/contract.hpp"

namespace odte::domain {

enum class AmountError : std::uint8_t {
  NEGATIVE,
  EXCEEDS_SCHEMA_MAX,
};

const char* to_string(AmountError error);

class Amount {
 public:
  static constexpr std::int64_t kMaxValue = 999999999999999999LL;  // 18 digits

  Amount() = default;
  explicit Amount(std::int64_t value);

  [[nodiscard]] std::int64_t value() const noexcept;

  [[nodiscard]] static std::expected<Amount, AmountError> create(
      std::int64_t value);

  [[nodiscard]] std::expected<Amount, AmountError> add(
      const Amount& other) const;

  [[nodiscard]] friend std::expected<Amount, AmountError> operator+(
      const Amount& lhs, const Amount& rhs) {
    return lhs.add(rhs);
  }

  friend bool operator==(const Amount& lhs, const Amount& rhs) {
    return lhs.value_ == rhs.value_;
  }

  friend bool operator!=(const Amount& lhs, const Amount& rhs) {
    return lhs.value_ != rhs.value_;
  }

  friend bool operator<(const Amount& lhs, const Amount& rhs) {
    return lhs.value_ < rhs.value_;
  }

  friend bool operator<=(const Amount& lhs, const Amount& rhs) {
    return lhs.value_ <= rhs.value_;
  }

  friend bool operator>(const Amount& lhs, const Amount& rhs) {
    return lhs.value_ > rhs.value_;
  }

  friend bool operator>=(const Amount& lhs, const Amount& rhs) {
    return lhs.value_ >= rhs.value_;
  }

  void invariant() const {
    ODTE_INVARIANT(value_ >= 0);
    ODTE_INVARIANT(value_ <= kMaxValue);
  }

 private:
  std::int64_t value_{0};
};

}  // namespace odte::domain
