#pragma once

#include <boost/contract.hpp>
#include <cstdint>

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

  bool operator==(const Date& other) const;
  bool operator!=(const Date& other) const;
  bool operator<(const Date& other) const;
  bool operator<=(const Date& other) const;
  bool operator>(const Date& other) const;
  bool operator>=(const Date& other) const;

  void invariant() const {
    if (valid_) {
      BOOST_CONTRACT_ASSERT(value_ >= 20000101);
      BOOST_CONTRACT_ASSERT(value_ <= 20501231);
    }
  }

 private:
  std::uint32_t value_{0};
  bool valid_{false};
};

}  // namespace odte::domain
