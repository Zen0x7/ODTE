#pragma once

#include <array>
#include <boost/contract.hpp>
#include <cstddef>
#include <cstdint>

namespace odte::domain {

class TaxNumber
    : private boost::contract::constructor_precondition<TaxNumber> {
 public:
  static constexpr std::size_t kMaxSize = 10;  // "99999999-K"
  using Storage = std::array<char, kMaxSize + 1>;

  TaxNumber() = default;
  explicit TaxNumber(const char* value);

  const char* value() const;
  bool is_valid() const;

  friend bool operator==(const TaxNumber& lhs, const TaxNumber& rhs) {
    return lhs.valid_ && rhs.valid_ &&
           std::strcmp(lhs.data_.data(), rhs.data_.data()) == 0;
  }

  friend bool operator!=(const TaxNumber& lhs, const TaxNumber& rhs) {
    return !(lhs == rhs);
  }

  void invariant() const {
    if (valid_) {
      BOOST_CONTRACT_ASSERT(data_[0] != '\0');
    }
  }

 private:
  Storage data_{};
  bool valid_{false};
};

}  // namespace odte::domain
