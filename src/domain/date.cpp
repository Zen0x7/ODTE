#include "odte/domain/date.hpp"

#include <array>

namespace odte::domain {

namespace {

constexpr std::array<std::uint8_t, 13> kDaysInMonth = {0, 31, 28, 31, 30, 31,
                                                       30, 31, 31, 30, 31,
                                                       30, 31};

constexpr bool is_leap_year(std::uint16_t year) {
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

constexpr std::uint8_t max_day(std::uint16_t year, std::uint8_t month) {
  if (month == 2 && is_leap_year(year)) return 29;
  return kDaysInMonth[month];
}

}  // namespace

Date::Date(std::uint32_t value) : value_(value) {
  const auto y = static_cast<std::uint16_t>(value / 10000);
  const auto m = static_cast<std::uint8_t>((value % 10000) / 100);
  const auto d = static_cast<std::uint8_t>(value % 100);

  valid_ = (y >= 2000 && y <= 2050) && (m >= 1 && m <= 12) &&
           (d >= 1 && d <= 31);

  if (!valid_) return;

  valid_ = (d <= max_day(y, m));

  ODTE_ENSURES(value_ >= 20000101);
  ODTE_ENSURES(value_ <= 20501231);
  invariant();
}

Date Date::from_components(std::uint16_t year, std::uint8_t month,
                           std::uint8_t day) {
  ODTE_EXPECTS(year >= 2000);
  ODTE_EXPECTS(year <= 2050);
  ODTE_EXPECTS(month >= 1);
  ODTE_EXPECTS(month <= 12);
  ODTE_EXPECTS(day >= 1);
  ODTE_EXPECTS(day <= max_day(year, month));

  const std::uint32_t val =
      static_cast<std::uint32_t>(year) * 10000 +
      static_cast<std::uint32_t>(month) * 100 +
      static_cast<std::uint32_t>(day);
  return Date(val);
}

std::uint32_t Date::value() const { return value_; }

bool Date::is_valid() const { return valid_; }

std::uint16_t Date::year() const {
  ODTE_EXPECTS(valid_);
  return static_cast<std::uint16_t>(value_ / 10000);
}

std::uint8_t Date::month() const {
  ODTE_EXPECTS(valid_);
  return static_cast<std::uint8_t>((value_ % 10000) / 100);
}

std::uint8_t Date::day() const {
  ODTE_EXPECTS(valid_);
  return static_cast<std::uint8_t>(value_ % 100);
}

}  // namespace odte::domain
