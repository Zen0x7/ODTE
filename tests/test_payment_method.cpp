#include <gtest/gtest.h>

#include "odte/domain/payment_method.hpp"

using namespace odte::domain;

TEST(PaymentMethodTest, ToString) {
    EXPECT_STREQ(to_string(PaymentMethod::CHECK), "Check");
    EXPECT_STREQ(to_string(PaymentMethod::PROMISSORY_NOTE), "Promissory Note");
    EXPECT_STREQ(to_string(PaymentMethod::CASH), "Cash");
    EXPECT_STREQ(to_string(PaymentMethod::ACCOUNT_RECEIVABLE), "Account Receivable");
    EXPECT_STREQ(to_string(PaymentMethod::CREDIT_CARD), "Credit Card");
    EXPECT_STREQ(to_string(PaymentMethod::POST_DATED_CHECK), "Post-Dated Check");
    EXPECT_STREQ(to_string(PaymentMethod::OTHER), "Other");
}

TEST(PaymentMethodTest, UnknownFallsBack) {
    EXPECT_STREQ(to_string(static_cast<PaymentMethod>(200)), "Other");
}
