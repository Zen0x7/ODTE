#pragma once

#include <boost/contract.hpp>
#include <cstdint>

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
      BOOST_CONTRACT_ASSERT(date_.is_valid());
      BOOST_CONTRACT_ASSERT(hour_ < 24);
      BOOST_CONTRACT_ASSERT(minute_ < 60);
      BOOST_CONTRACT_ASSERT(second_ < 60);
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
