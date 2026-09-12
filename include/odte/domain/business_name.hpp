#pragma once

#include <array>
#include <boost/contract.hpp>
#include <cstddef>
#include <cstdint>

namespace odte::domain {

class BusinessName
    : private boost::contract::constructor_precondition<BusinessName> {
 public:
  static constexpr std::size_t kMaxSize = 100;
  using Storage = std::array<char, kMaxSize + 1>;

  BusinessName() = default;
  explicit BusinessName(const char* value);

  const char* value() const;
  bool is_valid() const;

  friend bool operator==(const BusinessName& lhs, const BusinessName& rhs) {
    return lhs.valid_ && rhs.valid_ &&
           std::strcmp(lhs.data_.data(), rhs.data_.data()) == 0;
  }

  friend bool operator!=(const BusinessName& lhs, const BusinessName& rhs) {
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
