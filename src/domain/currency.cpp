#include "odte/domain/currency.hpp"

namespace odte::domain {

const char* to_string(Currency currency) {
  switch (currency) {
    case Currency::BOLIVAR:
      return "BOLIVAR";
    case Currency::BOLIVIANO:
      return "BOLIVIANO";
    case Currency::SHILLING:
      return "CHELIN";
    case Currency::DANISH_KRONE:
      return "CORONA DIN";
    case Currency::NORWEGIAN_KRONE:
      return "CORONA NOR";
    case Currency::SWEDISH_KRONE:
      return "CORONA SC";
    case Currency::CRUZEIRO_REAL:
      return "CRUZEIRO REAL";
    case Currency::DIRHAM:
      return "DIRHAM";
    case Currency::AUSTRALIAN_DOLLAR:
      return "DOLAR AUST";
    case Currency::CANADIAN_DOLLAR:
      return "DOLAR CAN";
    case Currency::HONG_KONG_DOLLAR:
      return "DOLAR HK";
    case Currency::NEW_ZEALAND_DOLLAR:
      return "DOLAR NZ";
    case Currency::SINGAPORE_DOLLAR:
      return "DOLAR SIN";
    case Currency::TAIWAN_DOLLAR:
      return "DOLAR TAI";
    case Currency::US_DOLLAR:
      return "DOLAR USA";
    case Currency::DRACHMA:
      return "DRACMA";
    case Currency::ESCUDO:
      return "ESCUDO";
    case Currency::EURO:
      return "EURO";
    case Currency::FLORIN:
      return "FLORIN";
    case Currency::BELGIAN_FRANC:
      return "FRANCO BEL";
    case Currency::FRENCH_FRANC:
      return "FRANCO FR";
    case Currency::SWISS_FRANC:
      return "FRANCO SZ";
    case Currency::GUARANI:
      return "GUARANI";
    case Currency::POUND_STERLING:
      return "LIBRA EST";
    case Currency::LIRA:
      return "LIRA";
    case Currency::GERMAN_MARK:
      return "MARCO AL";
    case Currency::FINNISH_MARK:
      return "MARCO FIN";
    case Currency::NUEVO_SOL:
      return "NUEVO SOL";
    case Currency::OTHER_CURRENCIES:
      return "OTRAS MONEDAS";
    case Currency::PESETA:
      return "PESETA";
    case Currency::PESO:
      return "PESO";
    case Currency::CHILEAN_PESO:
      return "PESO CL";
    case Currency::COLOMBIAN_PESO:
      return "PESO COL";
    case Currency::MEXICAN_PESO:
      return "PESO MEX";
    case Currency::URUGUAYAN_PESO:
      return "PESO URUG";
    case Currency::RAND:
      return "RAND";
    case Currency::RENMINBI:
      return "RENMINBI";
    case Currency::RUPEE:
      return "RUPIA";
    case Currency::SUCRE:
      return "SUCRE";
    case Currency::YEN:
      return "YEN";
  }
  return "OTRAS MONEDAS";
}

}  // namespace odte::domain
