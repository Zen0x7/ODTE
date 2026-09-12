#include "odte/domain/folio.hpp"

namespace odte::domain {

Folio::Folio(std::int64_t value)
    : value_(value), valid_(value > 0 && value <= kMaxValue) {
  boost::contract::check c = boost::contract::constructor(this)
      .postcondition([valid_ = &valid_, value = value_] {
        BOOST_CONTRACT_ASSERT(*valid_ == (value > 0 && value <= kMaxValue));
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

}  // namespace odte::domain
