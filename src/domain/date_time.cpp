#include "odte/domain/date_time.hpp"

namespace odte::domain {

DateTime::DateTime(const Date& date, std::uint8_t hour, std::uint8_t minute,
                   std::uint8_t second)
    : date_(date), hour_(hour), minute_(minute), second_(second) {
  valid_ = date_.is_valid() && hour_ < 24 && minute_ < 60 && second_ < 60;

  boost::contract::check c = boost::contract::constructor(this)
      .postcondition([date = &date_, hour = hour_, minute = minute_,
                      second = second_, valid = &valid_] {
        BOOST_CONTRACT_ASSERT(*valid == ((*date).is_valid() && hour < 24 &&
                                         minute < 60 && second < 60));
      });
}

const Date& DateTime::date() const {
  boost::contract::check c = boost::contract::function();
  return date_;
}

std::uint8_t DateTime::hour() const {
  boost::contract::check c = boost::contract::function();
  return hour_;
}

std::uint8_t DateTime::minute() const {
  boost::contract::check c = boost::contract::function();
  return minute_;
}

std::uint8_t DateTime::second() const {
  boost::contract::check c = boost::contract::function();
  return second_;
}

bool DateTime::is_valid() const {
  boost::contract::check c = boost::contract::function();
  return valid_;
}

}  // namespace odte::domain
