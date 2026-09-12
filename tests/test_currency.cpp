#include <gtest/gtest.h>

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
    const Case cases[] = {
        {Currency::BOLIVAR, "BOLIVAR"},
        {Currency::BOLIVIANO, "BOLIVIANO"},
        {Currency::SHILLING, "CHELIN"},
        {Currency::DANISH_KRONE, "CORONA DIN"},
        {Currency::NORWEGIAN_KRONE, "CORONA NOR"},
        {Currency::SWEDISH_KRONE, "CORONA SC"},
        {Currency::CRUZEIRO_REAL, "CRUZEIRO REAL"},
        {Currency::DIRHAM, "DIRHAM"},
        {Currency::AUSTRALIAN_DOLLAR, "DOLAR AUST"},
        {Currency::CANADIAN_DOLLAR, "DOLAR CAN"},
        {Currency::HONG_KONG_DOLLAR, "DOLAR HK"},
        {Currency::NEW_ZEALAND_DOLLAR, "DOLAR NZ"},
        {Currency::SINGAPORE_DOLLAR, "DOLAR SIN"},
        {Currency::TAIWAN_DOLLAR, "DOLAR TAI"},
        {Currency::US_DOLLAR, "DOLAR USA"},
        {Currency::DRACHMA, "DRACMA"},
        {Currency::ESCUDO, "ESCUDO"},
        {Currency::EURO, "EURO"},
        {Currency::FLORIN, "FLORIN"},
        {Currency::BELGIAN_FRANC, "FRANCO BEL"},
        {Currency::FRENCH_FRANC, "FRANCO FR"},
        {Currency::SWISS_FRANC, "FRANCO SZ"},
        {Currency::GUARANI, "GUARANI"},
        {Currency::POUND_STERLING, "LIBRA EST"},
        {Currency::LIRA, "LIRA"},
        {Currency::GERMAN_MARK, "MARCO AL"},
        {Currency::FINNISH_MARK, "MARCO FIN"},
        {Currency::NUEVO_SOL, "NUEVO SOL"},
        {Currency::OTHER_CURRENCIES, "OTRAS MONEDAS"},
        {Currency::PESETA, "PESETA"},
        {Currency::PESO, "PESO"},
        {Currency::CHILEAN_PESO, "PESO CL"},
        {Currency::COLOMBIAN_PESO, "PESO COL"},
        {Currency::MEXICAN_PESO, "PESO MEX"},
        {Currency::URUGUAYAN_PESO, "PESO URUG"},
        {Currency::RAND, "RAND"},
        {Currency::RENMINBI, "RENMINBI"},
        {Currency::RUPEE, "RUPIA"},
        {Currency::SUCRE, "SUCRE"},
        {Currency::YEN, "YEN"},
    };
    for (const Case& item : cases) {
        EXPECT_STREQ(to_string(item.currency), item.text);
    }
}

TEST(CurrencyTest, UnknownFallsBack) {
    EXPECT_STREQ(to_string(static_cast<Currency>(255)), "OTRAS MONEDAS");
}
