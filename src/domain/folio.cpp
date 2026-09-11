#include "odte/domain/folio.hpp"

namespace odte::domain {

Folio::Folio(std::int64_t value) : value_(value), valid_(value > 0 && value <= kMaxValue) {
  boost::contract::check c = boost::contract::constructor(this)
      .postcondition([&] {
        BOOST_CONTRACT_ASSERT(valid_ == (value > 0 && value <= kMaxValue));
      });
}

std::int64_t Folio::value() const {
  boost::contract::check c = boost::contract::function();
  return value_;
}

bool Folio::is_valid() const {
  boost::contract::check c = boost::contract::function();
  return valid_;
}

bool Folio::operator==(const Folio& other) const {
  boost::contract::check c = boost::contract::function()
      .precondition([&] {
        BOOST_CONTRACT_ASSERT(other.valid_);
      });
  return value_ == other.value_;
}

bool Folio::operator!=(const Folio& other) const {
  boost::contract::check c = boost::contract::function()
      .precondition([&] {
        BOOST_CONTRACT_ASSERT(other.valid_);
      });
  return value_ != other.value_;
}

bool Folio::operator<(const Folio& other) const {
  boost::contract::check c = boost::contract::function()
      .precondition([&] {
        BOOST_CONTRACT_ASSERT(other.valid_);
      });
  return value_ < other.value_;
}

bool Folio::operator<=(const Folio& other) const {
  boost::contract::check c = boost::contract::function()
      .precondition([&] {
        BOOST_CONTRACT_ASSERT(other.valid_);
      });
  return value_ <= other.value_;
}

bool Folio::operator>(const Folio& other) const {
  boost::contract::check c = boost::contract::function()
      .precondition([&] {
        BOOST_CONTRACT_ASSERT(other.valid_);
      });
  return value_ > other.value_;
}

bool Folio::operator>=(const Folio& other) const {
  boost::contract::check c = boost::contract::function()
      .precondition([&] {
        BOOST_CONTRACT_ASSERT(other.valid_);
      });
  return value_ >= other.value_;
}

}  // namespace odte::domain
