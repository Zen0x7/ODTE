#include <gtest/gtest.h>

#include <array>

#include "odte/domain/tax_code.hpp"

using namespace odte::domain;

TEST(TaxCodeTest, ToStringCoversAll) {
    struct Case {
        TaxCode code;
        const char* text;
    };
    const std::array<Case, 44> cases = {{
        {.code = TaxCode::COMMERCIAL_MARGIN_VAT, .text = "14"},
        {.code = TaxCode::TOTAL_WITHHELD_VAT, .text = "15"},
        {.code = TaxCode::PARTIAL_WITHHELD_VAT, .text = "16"},
        {.code = TaxCode::MEAT_SLAUGHTER_ADVANCE_VAT, .text = "17"},
        {.code = TaxCode::MEAT_ADVANCE_VAT, .text = "18"},
        {.code = TaxCode::FLOUR_ADVANCE_VAT, .text = "19"},
        {.code = TaxCode::GOLD_JEWELRY_FURS_ADDITIONAL_TAX, .text = "23"},
        {.code = TaxCode::LIQUORS_DISTILLED_ADDITIONAL_TAX, .text = "24"},
        {.code = TaxCode::WINE_ADDITIONAL_TAX, .text = "25"},
        {.code = TaxCode::BEER_ADDITIONAL_TAX, .text = "26"},
        {.code = TaxCode::SOFT_DRINKS_MINERAL_WATER_ADDITIONAL_TAX, .text = "27"},
        {.code = TaxCode::DIESEL_SPECIFIC_TAX, .text = "28"},
        {.code = TaxCode::LEGUMES_WITHHELD_VAT, .text = "30"},
        {.code = TaxCode::WILD_PRODUCTS_WITHHELD_VAT, .text = "31"},
        {.code = TaxCode::CATTLE_WITHHELD_VAT, .text = "32"},
        {.code = TaxCode::WOOD_WITHHELD_VAT, .text = "33"},
        {.code = TaxCode::WHEAT_WITHHELD_VAT, .text = "34"},
        {.code = TaxCode::GASOLINE_SPECIFIC_TAX, .text = "35"},
        {.code = TaxCode::RICE_WITHHELD_VAT, .text = "36"},
        {.code = TaxCode::HYDROBIOLOGICAL_WITHHELD_VAT, .text = "37"},
        {.code = TaxCode::SCRAP_WITHHELD_VAT, .text = "38"},
        {.code = TaxCode::PPA_WITHHELD_VAT, .text = "39"},
        {.code = TaxCode::OPTIONAL_WITHHELD_VAT, .text = "40"},
        {.code = TaxCode::CONSTRUCTION_WITHHELD_VAT, .text = "41"},
        {.code = TaxCode::CARPETS_CAVIAR_WEAPONS_ADDITIONAL_TAX, .text = "44"},
        {.code = TaxCode::PYROTECHNICS_ADDITIONAL_TAX, .text = "45"},
        {.code = TaxCode::RESERVED_46, .text = "46"},
        {.code = TaxCode::RESERVED_47, .text = "47"},
        {.code = TaxCode::RESERVED_48, .text = "48"},
        {.code = TaxCode::RESERVED_49, .text = "49"},
        {.code = TaxCode::RESERVED_50, .text = "50"},
        {.code = TaxCode::RESERVED_51, .text = "51"},
        {.code = TaxCode::RESERVED_52, .text = "52"},
        {.code = TaxCode::RESERVED_53, .text = "53"},
        {.code = TaxCode::RESERVED_54, .text = "54"},
        {.code = TaxCode::RESERVED_55, .text = "55"},
        {.code = TaxCode::SUGARY_DRINKS_ADDITIONAL_TAX, .text = "271"},
        {.code = TaxCode::RESERVED_301, .text = "301"},
        {.code = TaxCode::RESERVED_321, .text = "321"},
        {.code = TaxCode::RESERVED_331, .text = "331"},
        {.code = TaxCode::RESERVED_341, .text = "341"},
        {.code = TaxCode::RESERVED_361, .text = "361"},
        {.code = TaxCode::RESERVED_371, .text = "371"},
        {.code = TaxCode::RESERVED_481, .text = "481"},
    }};
    for (const Case& item : cases) {
        EXPECT_STREQ(to_string(item.code), item.text);
    }
}

TEST(TaxCodeTest, UnknownFallsBack) {
    EXPECT_STREQ(to_string(static_cast<TaxCode>(0)), "0");
}
