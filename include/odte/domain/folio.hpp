#pragma once

#include <boost/contract.hpp>
#include <cstdint>

namespace odte::domain {

class Folio {
 public:
  static constexpr std::int64_t kMaxValue = 9999999999LL;  // 10 digits

  Folio() = default;
  explicit Folio(std::int64_t value);

  std::int64_t value() const;
  bool is_valid() const;

  bool operator==(const Folio& other) const;
  bool operator!=(const Folio& other) const;
  bool operator<(const Folio& other) const;
  bool operator<=(const Folio& other) const;
  bool operator>(const Folio& other) const;
  bool operator>=(const Folio& other) const;

  void invariant() const {
    if (valid_) {
      BOOST_CONTRACT_ASSERT(value_ > 0);
      BOOST_CONTRACT_ASSERT(value_ <= kMaxValue);
    }
  }

 private:
  std::int64_t value_{0};
  bool valid_{false};
};

}  // namespace odte::domain
