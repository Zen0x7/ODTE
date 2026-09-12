#pragma once

#include <cstdint>

namespace odte::domain {

enum class Currency : std::uint8_t {
  BOLIVAR = 0,
  BOLIVIANO = 1,
  SHILLING = 2,
  DANISH_KRONE = 3,
  NORWEGIAN_KRONE = 4,
  SWEDISH_KRONE = 5,
  CRUZEIRO_REAL = 6,
  DIRHAM = 7,
  AUSTRALIAN_DOLLAR = 8,
  CANADIAN_DOLLAR = 9,
  HONG_KONG_DOLLAR = 10,
  NEW_ZEALAND_DOLLAR = 11,
  SINGAPORE_DOLLAR = 12,
  TAIWAN_DOLLAR = 13,
  US_DOLLAR = 14,
  DRACHMA = 15,
  ESCUDO = 16,
  EURO = 17,
  FLORIN = 18,
  BELGIAN_FRANC = 19,
  FRENCH_FRANC = 20,
  SWISS_FRANC = 21,
  GUARANI = 22,
  POUND_STERLING = 23,
  LIRA = 24,
  GERMAN_MARK = 25,
  FINNISH_MARK = 26,
  NUEVO_SOL = 27,
  OTHER_CURRENCIES = 28,
  PESETA = 29,
  PESO = 30,
  CHILEAN_PESO = 31,
  COLOMBIAN_PESO = 32,
  MEXICAN_PESO = 33,
  URUGUAYAN_PESO = 34,
  RAND = 35,
  RENMINBI = 36,
  RUPEE = 37,
  SUCRE = 38,
  YEN = 39,
};

const char* to_string(Currency currency);

}  // namespace odte::domain
