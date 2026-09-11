#include <gtest/gtest.h>

#include <boost/contract.hpp>
#include <limits>

#include "odte/domain/amount.hpp"
#include "odte/domain/business_name.hpp"
#include "odte/domain/date.hpp"
#include "odte/domain/document_type.hpp"
#include "odte/domain/electronic_document.hpp"
#include "odte/domain/folio.hpp"
#include "odte/domain/payment_method.hpp"
#include "odte/domain/tax_number.hpp"

using namespace odte::domain;

struct ContractEnvironment : ::testing::Environment {
    void SetUp() override {
        boost::contract::set_precondition_failure([](boost::contract::from) {
            throw boost::contract::assertion_failure(__FILE__, __LINE__, "precondition");
        });
        boost::contract::set_postcondition_failure([](boost::contract::from) {
            throw boost::contract::assertion_failure(__FILE__, __LINE__, "postcondition");
        });
        boost::contract::set_invariant_failure(
            [](boost::contract::from) { throw boost::contract::assertion_failure(__FILE__, __LINE__, "invariant"); });
    }
};

::testing::Environment* const env = ::testing::AddGlobalTestEnvironment(new ContractEnvironment);

// ── TaxNumber ──────────────────────────────────────────────

TEST(TaxNumberTest, ValidTaxNumber) {
    TaxNumber tax_number("12345678-5");
    EXPECT_TRUE(tax_number.is_valid());
    EXPECT_STREQ(tax_number.value(), "12345678-5");
}

TEST(TaxNumberTest, InvalidTaxNumber) {
    TaxNumber tax_number("12345");
    EXPECT_FALSE(tax_number.is_valid());
}

TEST(TaxNumberTest, EmptyTaxNumber) {
    TaxNumber tax_number("");
    EXPECT_FALSE(tax_number.is_valid());
}

TEST(TaxNumberTest, NullTaxNumber) {
    EXPECT_THROW(TaxNumber(nullptr), boost::contract::assertion_failure);
}

TEST(TaxNumberTest, Equality) {
    TaxNumber a("12345678-5");
    TaxNumber b("12345678-5");
    TaxNumber c("87654321-K");
    EXPECT_EQ(a, b);
    EXPECT_NE(a, c);
}

TEST(TaxNumberTest, LowercaseK) {
    TaxNumber tax_number("12345678-k");
    EXPECT_TRUE(tax_number.is_valid());
}

TEST(TaxNumberTest, TooLong) {
    TaxNumber tax_number("1234567890-1");
    EXPECT_FALSE(tax_number.is_valid());
}

TEST(TaxNumberTest, NoHyphen) {
    TaxNumber tax_number("123456785");
    EXPECT_FALSE(tax_number.is_valid());
}

TEST(TaxNumberTest, StartsHyphen) {
    TaxNumber tax_number("-12345678");
    EXPECT_FALSE(tax_number.is_valid());
}

TEST(TaxNumberTest, EndsHyphen) {
    TaxNumber tax_number("12345678-");
    EXPECT_FALSE(tax_number.is_valid());
}

TEST(TaxNumberTest, InvalidCheckDigit) {
    TaxNumber tax_number("12345678-X");
    EXPECT_FALSE(tax_number.is_valid());
}

TEST(TaxNumberTest, NonDigitBeforeHyphen) {
    TaxNumber tax_number("12A-5");
    EXPECT_FALSE(tax_number.is_valid());
}

// ── DocumentType ───────────────────────────────────────────

TEST(DocumentTypeTest, ValidTypes) {
    EXPECT_STREQ(to_string(DocumentType::INVOICE), "Invoice");
    EXPECT_STREQ(to_string(DocumentType::EXEMPT_INVOICE), "Exempt Invoice");
    EXPECT_STREQ(to_string(DocumentType::PURCHASE_INVOICE), "Purchase Invoice");
    EXPECT_STREQ(to_string(DocumentType::DISPATCH_GUIDE), "Dispatch Guide");
    EXPECT_STREQ(to_string(DocumentType::DEBIT_NOTE), "Debit Note");
    EXPECT_STREQ(to_string(DocumentType::CREDIT_NOTE), "Credit Note");
}

// ── Date ───────────────────────────────────────────────────

TEST(DateTest, ValidDate) {
    Date date(20240115);
    EXPECT_TRUE(date.is_valid());
    EXPECT_EQ(date.value(), 20240115u);
}

TEST(DateTest, InvalidDate) {
    Date date(20241301);
    EXPECT_FALSE(date.is_valid());
}

TEST(DateTest, LeapYear) {
    Date date(20240229);
    EXPECT_TRUE(date.is_valid());
}

TEST(DateTest, NonLeapYear) {
    Date date(20230229);
    EXPECT_FALSE(date.is_valid());
}

TEST(DateTest, April30) {
    Date date(20240430);
    EXPECT_TRUE(date.is_valid());
}

TEST(DateTest, April31) {
    Date date(20240431);
    EXPECT_FALSE(date.is_valid());
}

TEST(DateTest, FromComponents) {
    Date date = Date::from_components(2024, 1, 15);
    EXPECT_TRUE(date.is_valid());
    EXPECT_EQ(date.year(), 2024);
    EXPECT_EQ(date.month(), 1);
    EXPECT_EQ(date.day(), 15);
}

TEST(DateTest, FromComponentsInvalidDay) {
    EXPECT_THROW(Date::from_components(2024, 4, 31), boost::contract::assertion_failure);
}

TEST(DateTest, Equality) {
    Date a(20240115);
    Date b(20240115);
    Date c(20241225);
    EXPECT_EQ(a, b);
    EXPECT_NE(a, c);
}

TEST(DateTest, Comparison) {
    Date a(20240115);
    Date b(20241225);
    EXPECT_TRUE(a < b);
    EXPECT_TRUE(a <= b);
    EXPECT_TRUE(b > a);
    EXPECT_TRUE(b >= a);
}

// ── Amount ─────────────────────────────────────────────────

TEST(AmountTest, ValidAmount) {
    Amount amount(1000000);
    EXPECT_TRUE(amount.is_valid());
    EXPECT_EQ(amount.value(), 1000000);
}

TEST(AmountTest, ZeroAmount) {
    Amount amount(0);
    EXPECT_TRUE(amount.is_valid());
    EXPECT_EQ(amount.value(), 0);
}

TEST(AmountTest, NegativeAmount) {
    Amount amount(-100);
    EXPECT_FALSE(amount.is_valid());
}

TEST(AmountTest, Addition) {
    Amount a(100);
    Amount b(200);
    Amount c = a + b;
    EXPECT_EQ(c.value(), 300);
}

TEST(AmountTest, OverflowThrows) {
    Amount a(std::numeric_limits<std::int64_t>::max());
    Amount b(1);
    EXPECT_THROW(a + b, std::overflow_error);
}

TEST(AmountTest, OverflowAddReturnsFalse) {
    Amount a(std::numeric_limits<std::int64_t>::max());
    Amount b(1);
    Amount result;
    EXPECT_FALSE(a.add(b, result));
}

TEST(AmountTest, Comparison) {
    Amount a(100);
    Amount b(200);
    EXPECT_TRUE(a < b);
    EXPECT_TRUE(a <= b);
    EXPECT_TRUE(b > a);
    EXPECT_TRUE(b >= a);
    EXPECT_TRUE(a == Amount(100));
    EXPECT_TRUE(a >= Amount(100));
    EXPECT_TRUE(a <= Amount(100));
    EXPECT_TRUE(a != Amount(200));
    EXPECT_FALSE(a != Amount(100));
}

// ── Folio ──────────────────────────────────────────────────

TEST(FolioTest, ValidFolio) {
    Folio folio(1);
    EXPECT_TRUE(folio.is_valid());
    EXPECT_EQ(folio.value(), 1);
}

TEST(FolioTest, InvalidFolio) {
    Folio folio(0);
    EXPECT_FALSE(folio.is_valid());
}

TEST(FolioTest, MaxFolio) {
    Folio folio(9999999999LL);
    EXPECT_TRUE(folio.is_valid());
}

TEST(FolioTest, OverMaxFolio) {
    Folio folio(10000000000LL);
    EXPECT_FALSE(folio.is_valid());
}

TEST(FolioTest, Comparison) {
    Folio a(1);
    Folio b(2);
    EXPECT_TRUE(a < b);
    EXPECT_TRUE(a <= b);
    EXPECT_TRUE(b > a);
    EXPECT_TRUE(b >= a);
    EXPECT_TRUE(a == Folio(1));
    EXPECT_TRUE(a != Folio(2));
    EXPECT_FALSE(a == Folio(2));
    EXPECT_FALSE(a != Folio(1));
}

// ── BusinessName ───────────────────────────────────────────

TEST(BusinessNameTest, Valid) {
    BusinessName name("Acme Corp");
    EXPECT_TRUE(name.is_valid());
    EXPECT_STREQ(name.value(), "Acme Corp");
}

TEST(BusinessNameTest, Empty) {
    BusinessName name("");
    EXPECT_FALSE(name.is_valid());
}

TEST(BusinessNameTest, Null) {
    EXPECT_THROW(BusinessName(nullptr), boost::contract::assertion_failure);
}

TEST(BusinessNameTest, Equality) {
    BusinessName a("Acme Corp");
    BusinessName b("Acme Corp");
    BusinessName c("Other Corp");
    EXPECT_TRUE(a == b);
    EXPECT_TRUE(a != c);
    EXPECT_FALSE(a == c);
    EXPECT_FALSE(a != b);
}

// ── PaymentMethod ──────────────────────────────────────────

TEST(PaymentMethodTest, ToString) {
    EXPECT_STREQ(to_string(PaymentMethod::CHECK), "Check");
    EXPECT_STREQ(to_string(PaymentMethod::PROMISSORY_NOTE), "Promissory Note");
    EXPECT_STREQ(to_string(PaymentMethod::CASH), "Cash");
    EXPECT_STREQ(to_string(PaymentMethod::ACCOUNT_RECEIVABLE), "Account Receivable");
    EXPECT_STREQ(to_string(PaymentMethod::CREDIT_CARD), "Credit Card");
    EXPECT_STREQ(to_string(PaymentMethod::POST_DATED_CHECK), "Post-Dated Check");
    EXPECT_STREQ(to_string(PaymentMethod::OTHER), "Other");
}

// ── ElectronicDocument ─────────────────────────────────────

TEST(ElectronicDocumentTest, AddLineItem) {
    ElectronicDocument doc;
    LineItem item;
    item.sequence_number = 1;
    item.quantity = 10;
    item.unit_price = Amount(1000);
    EXPECT_TRUE(doc.add_line_item(item));
    EXPECT_EQ(doc.line_item_count, 1u);
}

TEST(ElectronicDocumentTest, AddLineItemOverflow) {
    ElectronicDocument doc;
    doc.line_item_count = kMaxLineItems;
    LineItem item;
    EXPECT_FALSE(doc.add_line_item(item));
}
