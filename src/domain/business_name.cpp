#include "odte/domain/business_name.hpp"

#include <cstring>

namespace odte::domain {

BusinessName::BusinessName(const char* value)
    : boost::contract::constructor_precondition<BusinessName>([&] {
        BOOST_CONTRACT_ASSERT(value != nullptr);
      }) {
  const auto len = std::strlen(value);
  if (len == 0 || len > kMaxSize) {
    valid_ = false;
    return;
  }

  std::memcpy(data_.data(), value, len);
  data_[len] = '\0';
  valid_ = true;

  boost::contract::check post = boost::contract::constructor(this)
      .postcondition([valid_ = &valid_, data_ = &data_] {
        BOOST_CONTRACT_ASSERT(
            *valid_ == (std::strlen(data_->data()) <= kMaxSize));
      });
}

const char* BusinessName::value() const {
  boost::contract::check c = boost::contract::function();
  return data_.data();
}

bool BusinessName::is_valid() const {
  boost::contract::check c = boost::contract::function();
  return valid_;
}

}  // namespace odte::domain
