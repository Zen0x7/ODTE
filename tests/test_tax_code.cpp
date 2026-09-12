#include <gtest/gtest.h>

#include "odte/domain/tax_code.hpp"

using namespace odte::domain;

TEST(TaxCodeTest, ToStringCoversAll) {
    struct Case {
        TaxCode code;
        const char* text;
    };
    const Case cases[] = {
        {TaxCode::COMMERCIAL_MARGIN_VAT, "14"},
        {TaxCode::TOTAL_WITHHELD_VAT, "15"},
        {TaxCode::PARTIAL_WITHHELD_VAT, "16"},
        {TaxCode::MEAT_SLAUGHTER_ADVANCE_VAT, "17"},
        {TaxCode::MEAT_ADVANCE_VAT, "18"},
        {TaxCode::FLOUR_ADVANCE_VAT, "19"},
        {TaxCode::GOLD_JEWELRY_FURS_ADDITIONAL_TAX, "23"},
        {TaxCode::LIQUORS_DISTILLED_ADDITIONAL_TAX, "24"},
        {TaxCode::WINE_ADDITIONAL_TAX, "25"},
        {TaxCode::BEER_ADDITIONAL_TAX, "26"},
        {TaxCode::SOFT_DRINKS_MINERAL_WATER_ADDITIONAL_TAX, "27"},
        {TaxCode::DIESEL_SPECIFIC_TAX, "28"},
        {TaxCode::LEGUMES_WITHHELD_VAT, "30"},
        {TaxCode::WILD_PRODUCTS_WITHHELD_VAT, "31"},
        {TaxCode::CATTLE_WITHHELD_VAT, "32"},
        {TaxCode::WOOD_WITHHELD_VAT, "33"},
        {TaxCode::WHEAT_WITHHELD_VAT, "34"},
        {TaxCode::GASOLINE_SPECIFIC_TAX, "35"},
        {TaxCode::RICE_WITHHELD_VAT, "36"},
        {TaxCode::HYDROBIOLOGICAL_WITHHELD_VAT, "37"},
        {TaxCode::SCRAP_WITHHELD_VAT, "38"},
        {TaxCode::PPA_WITHHELD_VAT, "39"},
        {TaxCode::OPTIONAL_WITHHELD_VAT, "40"},
        {TaxCode::CONSTRUCTION_WITHHELD_VAT, "41"},
        {TaxCode::CARPETS_CAVIAR_WEAPONS_ADDITIONAL_TAX, "44"},
        {TaxCode::PYROTECHNICS_ADDITIONAL_TAX, "45"},
        {TaxCode::RESERVED_46, "46"},
        {TaxCode::RESERVED_47, "47"},
        {TaxCode::RESERVED_48, "48"},
        {TaxCode::RESERVED_49, "49"},
        {TaxCode::RESERVED_50, "50"},
        {TaxCode::RESERVED_51, "51"},
        {TaxCode::RESERVED_52, "52"},
        {TaxCode::RESERVED_53, "53"},
        {TaxCode::RESERVED_54, "54"},
        {TaxCode::RESERVED_55, "55"},
        {TaxCode::SUGARY_DRINKS_ADDITIONAL_TAX, "271"},
        {TaxCode::RESERVED_301, "301"},
        {TaxCode::RESERVED_321, "321"},
        {TaxCode::RESERVED_331, "331"},
        {TaxCode::RESERVED_341, "341"},
        {TaxCode::RESERVED_361, "361"},
        {TaxCode::RESERVED_371, "371"},
        {TaxCode::RESERVED_481, "481"},
    };
    for (const Case& item : cases) {
        EXPECT_STREQ(to_string(item.code), item.text);
    }
}

TEST(TaxCodeTest, UnknownFallsBack) {
    EXPECT_STREQ(to_string(static_cast<TaxCode>(0)), "0");
}
