#pragma once

#include <boost/contract.hpp>
#include <cstdint>

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
      BOOST_CONTRACT_ASSERT(hundredths_ >= 1);
      BOOST_CONTRACT_ASSERT(hundredths_ <= kMaxHundredths);
    }
  }

 private:
  std::uint32_t hundredths_{0};
  bool valid_{false};
};

}  // namespace odte::domain
