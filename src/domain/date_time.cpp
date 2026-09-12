#include "odte/domain/date_time.hpp"

namespace odte::domain {

DateTime::DateTime(const Date& date, std::uint8_t hour, std::uint8_t minute,
                   std::uint8_t second)
    : date_(date), hour_(hour), minute_(minute), second_(second) {
  valid_ = date_.is_valid() && hour_ < 24 && minute_ < 60 && second_ < 60;

  ODTE_ENSURES(valid_ ==
               (date_.is_valid() && hour_ < 24 && minute_ < 60 &&
                second_ < 60));
  invariant();
}

const Date& DateTime::date() const { return date_; }

std::uint8_t DateTime::hour() const { return hour_; }

std::uint8_t DateTime::minute() const { return minute_; }

std::uint8_t DateTime::second() const { return second_; }

bool DateTime::is_valid() const { return valid_; }

}  // namespace odte::domain
