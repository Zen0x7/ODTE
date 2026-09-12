#include "odte/domain/folio.hpp"

namespace odte::domain {

Folio::Folio(std::int64_t value)
    : value_(value), valid_(value > 0 && value <= kMaxValue) {
  ODTE_ENSURES(valid_ == (value > 0 && value <= kMaxValue));
  invariant();
}

std::int64_t Folio::value() const { return value_; }

bool Folio::is_valid() const { return valid_; }

}  // namespace odte::domain
