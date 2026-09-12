#include <gtest/gtest.h>

#include <array>

#include "odte/domain/currency.hpp"

using namespace odte::domain;

TEST(CurrencyTest, ToString) {
    EXPECT_STREQ(to_string(Currency::CHILEAN_PESO), "PESO CL");
    EXPECT_STREQ(to_string(Currency::US_DOLLAR), "DOLAR USA");
    EXPECT_STREQ(to_string(Currency::EURO), "EURO");
}

TEST(CurrencyTest, ToStringCoversAll) {
    struct Case {
        Currency currency;
        const char* text;
    };
    const std::array<Case, 40> cases = {{
        {.currency = Currency::BOLIVAR, .text = "BOLIVAR"},
        {.currency = Currency::BOLIVIANO, .text = "BOLIVIANO"},
        {.currency = Currency::SHILLING, .text = "CHELIN"},
        {.currency = Currency::DANISH_KRONE, .text = "CORONA DIN"},
        {.currency = Currency::NORWEGIAN_KRONE, .text = "CORONA NOR"},
        {.currency = Currency::SWEDISH_KRONE, .text = "CORONA SC"},
        {.currency = Currency::CRUZEIRO_REAL, .text = "CRUZEIRO REAL"},
        {.currency = Currency::DIRHAM, .text = "DIRHAM"},
        {.currency = Currency::AUSTRALIAN_DOLLAR, .text = "DOLAR AUST"},
        {.currency = Currency::CANADIAN_DOLLAR, .text = "DOLAR CAN"},
        {.currency = Currency::HONG_KONG_DOLLAR, .text = "DOLAR HK"},
        {.currency = Currency::NEW_ZEALAND_DOLLAR, .text = "DOLAR NZ"},
        {.currency = Currency::SINGAPORE_DOLLAR, .text = "DOLAR SIN"},
        {.currency = Currency::TAIWAN_DOLLAR, .text = "DOLAR TAI"},
        {.currency = Currency::US_DOLLAR, .text = "DOLAR USA"},
        {.currency = Currency::DRACHMA, .text = "DRACMA"},
        {.currency = Currency::ESCUDO, .text = "ESCUDO"},
        {.currency = Currency::EURO, .text = "EURO"},
        {.currency = Currency::FLORIN, .text = "FLORIN"},
        {.currency = Currency::BELGIAN_FRANC, .text = "FRANCO BEL"},
        {.currency = Currency::FRENCH_FRANC, .text = "FRANCO FR"},
        {.currency = Currency::SWISS_FRANC, .text = "FRANCO SZ"},
        {.currency = Currency::GUARANI, .text = "GUARANI"},
        {.currency = Currency::POUND_STERLING, .text = "LIBRA EST"},
        {.currency = Currency::LIRA, .text = "LIRA"},
        {.currency = Currency::GERMAN_MARK, .text = "MARCO AL"},
        {.currency = Currency::FINNISH_MARK, .text = "MARCO FIN"},
        {.currency = Currency::NUEVO_SOL, .text = "NUEVO SOL"},
        {.currency = Currency::OTHER_CURRENCIES, .text = "OTRAS MONEDAS"},
        {.currency = Currency::PESETA, .text = "PESETA"},
        {.currency = Currency::PESO, .text = "PESO"},
        {.currency = Currency::CHILEAN_PESO, .text = "PESO CL"},
        {.currency = Currency::COLOMBIAN_PESO, .text = "PESO COL"},
        {.currency = Currency::MEXICAN_PESO, .text = "PESO MEX"},
        {.currency = Currency::URUGUAYAN_PESO, .text = "PESO URUG"},
        {.currency = Currency::RAND, .text = "RAND"},
        {.currency = Currency::RENMINBI, .text = "RENMINBI"},
        {.currency = Currency::RUPEE, .text = "RUPIA"},
        {.currency = Currency::SUCRE, .text = "SUCRE"},
        {.currency = Currency::YEN, .text = "YEN"},
    }};
    for (const Case& item : cases) {
        EXPECT_STREQ(to_string(item.currency), item.text);
    }
}

TEST(CurrencyTest, UnknownFallsBack) {
    EXPECT_STREQ(to_string(static_cast<Currency>(255)), "OTRAS MONEDAS");
}
