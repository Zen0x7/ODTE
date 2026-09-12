#pragma once

#include <cstdint>

#include "odte/contract.hpp"
#include "odte/domain/date.hpp"

namespace odte::domain {

class DateTime {
 public:
  DateTime() = default;
  DateTime(const Date& date, std::uint8_t hour, std::uint8_t minute,
           std::uint8_t second);

  const Date& date() const;
  std::uint8_t hour() const;
  std::uint8_t minute() const;
  std::uint8_t second() const;
  bool is_valid() const;

  friend bool operator==(const DateTime& lhs, const DateTime& rhs) {
    return lhs.date_ == rhs.date_ && lhs.hour_ == rhs.hour_ &&
           lhs.minute_ == rhs.minute_ && lhs.second_ == rhs.second_;
  }

  friend bool operator!=(const DateTime& lhs, const DateTime& rhs) {
    return !(lhs == rhs);
  }

  friend bool operator<(const DateTime& lhs, const DateTime& rhs) {
    if (lhs.date_ != rhs.date_) {
      return lhs.date_ < rhs.date_;
    }
    if (lhs.hour_ != rhs.hour_) {
      return lhs.hour_ < rhs.hour_;
    }
    if (lhs.minute_ != rhs.minute_) {
      return lhs.minute_ < rhs.minute_;
    }
    return lhs.second_ < rhs.second_;
  }

  void invariant() const {
    if (valid_) {
      ODTE_INVARIANT(date_.is_valid());
      ODTE_INVARIANT(hour_ < 24);
      ODTE_INVARIANT(minute_ < 60);
      ODTE_INVARIANT(second_ < 60);
    }
  }

 private:
  Date date_;
  std::uint8_t hour_{0};
  std::uint8_t minute_{0};
  std::uint8_t second_{0};
  bool valid_{false};
};

}  // namespace odte::domain
