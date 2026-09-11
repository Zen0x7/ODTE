#include "odte/domain/amount.hpp"

#include <limits>
#include <stdexcept>

namespace odte::domain {

Amount::Amount(std::int64_t value) : value_(value), valid_(value >= 0) {
  boost::contract::check c = boost::contract::constructor(this)
      .postcondition([&] {
        BOOST_CONTRACT_ASSERT(valid_ == (value >= 0));
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

bool Amount::operator==(const Amount& other) const {
  boost::contract::check c = boost::contract::function()
      .precondition([&] {
        BOOST_CONTRACT_ASSERT(valid_);
        BOOST_CONTRACT_ASSERT(other.valid_);
      });
  return value_ == other.value_;
}

bool Amount::operator!=(const Amount& other) const {
  boost::contract::check c = boost::contract::function()
      .precondition([&] {
        BOOST_CONTRACT_ASSERT(valid_);
        BOOST_CONTRACT_ASSERT(other.valid_);
      });
  return value_ != other.value_;
}

bool Amount::operator<(const Amount& other) const {
  boost::contract::check c = boost::contract::function()
      .precondition([&] {
        BOOST_CONTRACT_ASSERT(valid_);
        BOOST_CONTRACT_ASSERT(other.valid_);
      });
  return value_ < other.value_;
}

bool Amount::operator<=(const Amount& other) const {
  boost::contract::check c = boost::contract::function()
      .precondition([&] {
        BOOST_CONTRACT_ASSERT(valid_);
        BOOST_CONTRACT_ASSERT(other.valid_);
      });
  return value_ <= other.value_;
}

bool Amount::operator>(const Amount& other) const {
  boost::contract::check c = boost::contract::function()
      .precondition([&] {
        BOOST_CONTRACT_ASSERT(valid_);
        BOOST_CONTRACT_ASSERT(other.valid_);
      });
  return value_ > other.value_;
}

bool Amount::operator>=(const Amount& other) const {
  boost::contract::check c = boost::contract::function()
      .precondition([&] {
        BOOST_CONTRACT_ASSERT(valid_);
        BOOST_CONTRACT_ASSERT(other.valid_);
      });
  return value_ >= other.value_;
}

bool Amount::add(const Amount& other, Amount& result) const {
  boost::contract::check c = boost::contract::function()
      .precondition([&] {
        BOOST_CONTRACT_ASSERT(valid_);
        BOOST_CONTRACT_ASSERT(other.valid_);
      });

  if (value_ > 0 && other.value_ > 0 &&
      value_ > std::numeric_limits<std::int64_t>::max() - other.value_) {
    return false;
  }
  result = Amount(value_ + other.value_);
  return true;
}

Amount operator+(const Amount& a, const Amount& b) {
  boost::contract::check c = boost::contract::function()
      .precondition([&] {
        BOOST_CONTRACT_ASSERT(a.is_valid());
        BOOST_CONTRACT_ASSERT(b.is_valid());
      });

  Amount result;
  if (!a.add(b, result)) {
    throw std::overflow_error("Amount addition overflow");
  }
  return result;
}

}  // namespace odte::domain
