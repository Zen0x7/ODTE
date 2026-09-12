#include "odte/domain/amount.hpp"

#include <limits>

namespace odte::domain {

Amount::Amount(std::int64_t value) : value_(value), valid_(value >= 0) {
  boost::contract::check c = boost::contract::constructor(this)
      .postcondition([valid_ = &valid_, value = value_] {
        BOOST_CONTRACT_ASSERT(*valid_ == (value >= 0));
      });
}

std::int64_t Amount::value() const {
  boost::contract::check c = boost::contract::function();
  return value_;
}

bool Amount::is_valid() const {
  boost::contract::check c = boost::contract::function();
  return valid_;
}

bool Amount::add(const Amount& other, Amount& result) const {
  boost::contract::check c = boost::contract::function()
      .precondition([valid_ = &valid_, other_valid_ = &other.valid_] {
        BOOST_CONTRACT_ASSERT(*valid_);
        BOOST_CONTRACT_ASSERT(*other_valid_);
      });

  if (value_ > 0 && other.value_ > 0 &&
      value_ > std::numeric_limits<std::int64_t>::max() - other.value_) {
    return false;
  }
  result = Amount(value_ + other.value_);
  return true;
}

}  // namespace odte::domain
