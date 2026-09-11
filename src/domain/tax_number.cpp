#include "odte/domain/tax_number.hpp"

#include <cctype>
#include <cstring>

namespace odte::domain {

TaxNumber::TaxNumber(const char* value)
    : boost::contract::constructor_precondition<TaxNumber>([&] {
        BOOST_CONTRACT_ASSERT(value != nullptr);
      }) {
  const std::size_t len = std::strlen(value);
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

  const char last = value[len - 1];
  if (!std::isdigit(static_cast<unsigned char>(last)) && last != 'K' &&
      last != 'k') {
    valid_ = false;
    return;
  }

  std::memcpy(data_.data(), value, len);
  data_[len] = '\0';
  valid_ = true;

  boost::contract::check post = boost::contract::constructor(this)
      .postcondition([&] {
        BOOST_CONTRACT_ASSERT(valid_ == (std::strlen(data_.data()) >= 3));
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

bool TaxNumber::operator==(const TaxNumber& other) const {
  boost::contract::check c = boost::contract::function()
      .precondition([&] {
        BOOST_CONTRACT_ASSERT(other.valid_);
      });
  return valid_ && std::strcmp(data_.data(), other.data_.data()) == 0;
}

bool TaxNumber::operator!=(const TaxNumber& other) const {
  boost::contract::check c = boost::contract::function()
      .precondition([&] {
        BOOST_CONTRACT_ASSERT(other.valid_);
      });
  return !(*this == other);
}

}  // namespace odte::domain
