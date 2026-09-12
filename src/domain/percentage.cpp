#include "odte/domain/percentage.hpp"

namespace odte::domain {

Percentage::Percentage(std::uint32_t hundredths) : hundredths_(hundredths) {
  valid_ = hundredths_ >= 1 && hundredths_ <= kMaxHundredths;

  boost::contract::check c = boost::contract::constructor(this)
      .postcondition([hundredths = hundredths_, valid = &valid_] {
        BOOST_CONTRACT_ASSERT(*valid ==
                              (hundredths >= 1 && hundredths <= kMaxHundredths));
      });
}

std::uint32_t Percentage::hundredths() const {
  boost::contract::check c = boost::contract::function();
  return hundredths_;
}

bool Percentage::is_valid() const {
  boost::contract::check c = boost::contract::function();
  return valid_;
}

}  // namespace odte::domain
