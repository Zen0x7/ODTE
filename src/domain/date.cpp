#include "odte/domain/date.hpp"

namespace odte::domain {

namespace {

constexpr std::uint8_t kDaysInMonth[] = {0, 31, 28, 31, 30, 31, 30,
                                         31, 31, 30, 31, 30, 31};

constexpr bool is_leap_year(std::uint16_t year) {
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

constexpr std::uint8_t max_day(std::uint16_t year, std::uint8_t month) {
  if (month == 2 && is_leap_year(year)) return 29;
  return kDaysInMonth[month];
}

}  // namespace

Date::Date(std::uint32_t value) : value_(value) {
  boost::contract::check c = boost::contract::constructor(this);

  const std::uint16_t y = static_cast<std::uint16_t>(value / 10000);
  const std::uint8_t m = static_cast<std::uint8_t>((value % 10000) / 100);
  const std::uint8_t d = static_cast<std::uint8_t>(value % 100);

  valid_ = (y >= 2000 && y <= 2050) && (m >= 1 && m <= 12) && (d >= 1 && d <= 31);

  if (!valid_) return;

  valid_ = (d <= max_day(y, m));

  boost::contract::check post = boost::contract::constructor(this)
      .postcondition([&] {
        BOOST_CONTRACT_ASSERT(valid_ ? (value_ >= 20000101 && value_ <= 20501231) : true);
      });
}

Date Date::from_components(std::uint16_t year, std::uint8_t month,
                           std::uint8_t day) {
  boost::contract::check c = boost::contract::function()
      .precondition([&] {
        BOOST_CONTRACT_ASSERT(year >= 2000 && year <= 2050);
        BOOST_CONTRACT_ASSERT(month >= 1 && month <= 12);
        BOOST_CONTRACT_ASSERT(day >= 1 && day <= max_day(year, month));
      });

  const std::uint32_t value =
      static_cast<std::uint32_t>(year) * 10000 +
      static_cast<std::uint32_t>(month) * 100 +
      static_cast<std::uint32_t>(day);
  return Date(value);
}

std::uint32_t Date::value() const {
  boost::contract::check c = boost::contract::function();
  return value_;
}

bool Date::is_valid() const {
  boost::contract::check c = boost::contract::function();
  return valid_;
}

std::uint16_t Date::year() const {
  boost::contract::check c = boost::contract::function()
      .precondition([&] {
        BOOST_CONTRACT_ASSERT(valid_);
      });
  return static_cast<std::uint16_t>(value_ / 10000);
}

std::uint8_t Date::month() const {
  boost::contract::check c = boost::contract::function()
      .precondition([&] {
        BOOST_CONTRACT_ASSERT(valid_);
      });
  return static_cast<std::uint8_t>((value_ % 10000) / 100);
}

std::uint8_t Date::day() const {
  boost::contract::check c = boost::contract::function()
      .precondition([&] {
        BOOST_CONTRACT_ASSERT(valid_);
      });
  return static_cast<std::uint8_t>(value_ % 100);
}

bool Date::operator==(const Date& other) const {
  boost::contract::check c = boost::contract::function()
      .precondition([&] {
        BOOST_CONTRACT_ASSERT(valid_);
        BOOST_CONTRACT_ASSERT(other.valid_);
      });
  return value_ == other.value_;
}

bool Date::operator!=(const Date& other) const {
  boost::contract::check c = boost::contract::function()
      .precondition([&] {
        BOOST_CONTRACT_ASSERT(valid_);
        BOOST_CONTRACT_ASSERT(other.valid_);
      });
  return value_ != other.value_;
}

bool Date::operator<(const Date& other) const {
  boost::contract::check c = boost::contract::function()
      .precondition([&] {
        BOOST_CONTRACT_ASSERT(valid_);
        BOOST_CONTRACT_ASSERT(other.valid_);
      });
  return value_ < other.value_;
}

bool Date::operator<=(const Date& other) const {
  boost::contract::check c = boost::contract::function()
      .precondition([&] {
        BOOST_CONTRACT_ASSERT(valid_);
        BOOST_CONTRACT_ASSERT(other.valid_);
      });
  return value_ <= other.value_;
}

bool Date::operator>(const Date& other) const {
  boost::contract::check c = boost::contract::function()
      .precondition([&] {
        BOOST_CONTRACT_ASSERT(valid_);
        BOOST_CONTRACT_ASSERT(other.valid_);
      });
  return value_ > other.value_;
}

bool Date::operator>=(const Date& other) const {
  boost::contract::check c = boost::contract::function()
      .precondition([&] {
        BOOST_CONTRACT_ASSERT(valid_);
        BOOST_CONTRACT_ASSERT(other.valid_);
      });
  return value_ >= other.value_;
}

}  // namespace odte::domain
