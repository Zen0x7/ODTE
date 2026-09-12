#pragma once

#include <cstdint>

#include "odte/contract.hpp"

namespace odte::domain {

class Date {
 public:
  Date() = default;
  explicit Date(std::uint32_t value);

  static Date from_components(std::uint16_t year, std::uint8_t month,
                              std::uint8_t day);

  std::uint32_t value() const;
  bool is_valid() const;

  std::uint16_t year() const;
  std::uint8_t month() const;
  std::uint8_t day() const;

  friend bool operator==(const Date& lhs, const Date& rhs) {
    return lhs.value_ == rhs.value_;
  }

  friend bool operator!=(const Date& lhs, const Date& rhs) {
    return lhs.value_ != rhs.value_;
  }

  friend bool operator<(const Date& lhs, const Date& rhs) {
    return lhs.value_ < rhs.value_;
  }

  friend bool operator<=(const Date& lhs, const Date& rhs) {
    return lhs.value_ <= rhs.value_;
  }

  friend bool operator>(const Date& lhs, const Date& rhs) {
    return lhs.value_ > rhs.value_;
  }

  friend bool operator>=(const Date& lhs, const Date& rhs) {
    return lhs.value_ >= rhs.value_;
  }

  void invariant() const {
    if (valid_) {
      ODTE_INVARIANT(value_ >= 20000101);
      ODTE_INVARIANT(value_ <= 20501231);
    }
  }

 private:
  std::uint32_t value_{0};
  bool valid_{false};
};

}  // namespace odte::domain
