#include "odte/domain/percentage.hpp"

namespace odte::domain {

Percentage::Percentage(std::uint32_t hundredths) : hundredths_(hundredths) {
  valid_ = hundredths_ >= 1 && hundredths_ <= kMaxHundredths;

  ODTE_ENSURES(valid_ ==
               (hundredths_ >= 1 && hundredths_ <= kMaxHundredths));
  invariant();
}

std::uint32_t Percentage::hundredths() const { return hundredths_; }

bool Percentage::is_valid() const { return valid_; }

}  // namespace odte::domain
