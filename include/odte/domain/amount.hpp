#pragma once

#include <boost/contract.hpp>
#include <cstdint>

namespace odte::domain {

class Amount {
 public:
  Amount() = default;
  explicit Amount(std::int64_t value);

  std::int64_t value() const;
  bool is_valid() const;

  bool operator==(const Amount& other) const;
  bool operator!=(const Amount& other) const;
  bool operator<(const Amount& other) const;
  bool operator<=(const Amount& other) const;
  bool operator>(const Amount& other) const;
  bool operator>=(const Amount& other) const;

  bool add(const Amount& other, Amount& result) const;

  void invariant() const {
    BOOST_CONTRACT_ASSERT(valid_ ? value_ >= 0 : true);
  }

 private:
  std::int64_t value_{0};
  bool valid_{false};
};

Amount operator+(const Amount& a, const Amount& b);

}  // namespace odte::domain
