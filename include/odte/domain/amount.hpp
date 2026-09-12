#pragma once

#include <boost/contract.hpp>
#include <cstdint>
#include <stdexcept>

namespace odte::domain {

class Amount {
 public:
  Amount() = default;
  explicit Amount(std::int64_t value);

  std::int64_t value() const;
  bool is_valid() const;

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

  friend Amount operator+(const Amount& a, const Amount& b) {
    Amount result;
    if (!a.add(b, result)) {
      throw std::overflow_error("Amount addition overflow");
    }
    return result;
  }

  bool add(const Amount& other, Amount& result) const;

  void invariant() const {
    BOOST_CONTRACT_ASSERT(valid_ ? value_ >= 0 : true);
  }

 private:
  std::int64_t value_{0};
  bool valid_{false};
};

}  // namespace odte::domain
