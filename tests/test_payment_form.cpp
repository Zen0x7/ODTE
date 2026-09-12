#include <gtest/gtest.h>

#include "odte/domain/payment_form.hpp"

using namespace odte::domain;

TEST(PaymentFormTest, ToString) {
    EXPECT_STREQ(to_string(PaymentForm::CASH), "Cash");
    EXPECT_STREQ(to_string(PaymentForm::CREDIT), "Credit");
    EXPECT_STREQ(to_string(PaymentForm::NO_PAYMENT), "No Payment");
}

TEST(PaymentFormTest, UnknownFallsBack) {
    EXPECT_STREQ(to_string(static_cast<PaymentForm>(0)), "No Payment");
}
