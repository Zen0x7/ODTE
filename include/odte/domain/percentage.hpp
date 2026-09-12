#pragma once

#include <cstdint>

#include "odte/contract.hpp"

namespace odte::domain {

class Percentage {
 public:
  static constexpr std::uint32_t kMaxHundredths = 99999;  // 999.99%

  Percentage() = default;
  explicit Percentage(std::uint32_t hundredths);

  std::uint32_t hundredths() const;
  bool is_valid() const;

  friend bool operator==(const Percentage& lhs, const Percentage& rhs) {
    return lhs.hundredths_ == rhs.hundredths_;
  }

  friend bool operator!=(const Percentage& lhs, const Percentage& rhs) {
    return lhs.hundredths_ != rhs.hundredths_;
  }

  friend bool operator<(const Percentage& lhs, const Percentage& rhs) {
    return lhs.hundredths_ < rhs.hundredths_;
  }

  friend bool operator<=(const Percentage& lhs, const Percentage& rhs) {
    return lhs.hundredths_ <= rhs.hundredths_;
  }

  friend bool operator>(const Percentage& lhs, const Percentage& rhs) {
    return lhs.hundredths_ > rhs.hundredths_;
  }

  friend bool operator>=(const Percentage& lhs, const Percentage& rhs) {
    return lhs.hundredths_ >= rhs.hundredths_;
  }

  void invariant() const {
    if (valid_) {
      ODTE_INVARIANT(hundredths_ >= 1);
      ODTE_INVARIANT(hundredths_ <= kMaxHundredths);
    }
  }

 private:
  std::uint32_t hundredths_{0};
  bool valid_{false};
};

}  // namespace odte::domain
