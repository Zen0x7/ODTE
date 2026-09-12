#pragma once

#include <cstdint>

#include "odte/contract.hpp"

namespace odte::domain {

class Folio {
 public:
  static constexpr std::int64_t kMaxValue = 9999999999LL;  // 10 digits

  Folio() = default;
  explicit Folio(std::int64_t value);

  std::int64_t value() const;
  bool is_valid() const;

  friend bool operator==(const Folio& lhs, const Folio& rhs) {
    return lhs.value_ == rhs.value_;
  }

  friend bool operator!=(const Folio& lhs, const Folio& rhs) {
    return lhs.value_ != rhs.value_;
  }

  friend bool operator<(const Folio& lhs, const Folio& rhs) {
    return lhs.value_ < rhs.value_;
  }

  friend bool operator<=(const Folio& lhs, const Folio& rhs) {
    return lhs.value_ <= rhs.value_;
  }

  friend bool operator>(const Folio& lhs, const Folio& rhs) {
    return lhs.value_ > rhs.value_;
  }

  friend bool operator>=(const Folio& lhs, const Folio& rhs) {
    return lhs.value_ >= rhs.value_;
  }

  void invariant() const {
    if (valid_) {
      ODTE_INVARIANT(value_ > 0);
      ODTE_INVARIANT(value_ <= kMaxValue);
    }
  }

 private:
  std::int64_t value_{0};
  bool valid_{false};
};

}  // namespace odte::domain
