#include "odte/domain/tax_number.hpp"

#include <cctype>
#include <cstring>

namespace odte::domain {

TaxNumber::TaxNumber(const char* value)
    : boost::contract::constructor_precondition<TaxNumber>([&value] {
        BOOST_CONTRACT_ASSERT(value != nullptr);
      }) {
  const auto len = strnlen(value, kMaxSize + 1);
  if (len < 3 || len > kMaxSize) {
    valid_ = false;
    return;
  }

  std::size_t i = 0;
  while (i < len && std::isdigit(static_cast<unsigned char>(value[i]))) {
    ++i;
  }

  if (i == 0 || i >= len) {
    valid_ = false;
    return;
  }

  if (value[i] != '-') {
    valid_ = false;
    return;
  }

  ++i;
  if (i != len - 1) {
    valid_ = false;
    return;
  }

  if (const char last = value[len - 1];
      !std::isdigit(static_cast<unsigned char>(last)) && last != 'K' &&
      last != 'k') {
    valid_ = false;
    return;
  }

  std::memcpy(data_.data(), value, len);
  data_[len] = '\0';
  valid_ = true;

  boost::contract::check post = boost::contract::constructor(this)
      .postcondition([valid_ = &valid_, data_ = &data_] {
        BOOST_CONTRACT_ASSERT(
            *valid_ == (std::strlen(data_->data()) >= 3));
      });
}

const char* TaxNumber::value() const {
  boost::contract::check c = boost::contract::function();
  return data_.data();
}

bool TaxNumber::is_valid() const {
  boost::contract::check c = boost::contract::function();
  return valid_;
}

}  // namespace odte::domain
