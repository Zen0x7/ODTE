#include <gtest/gtest.h>

#include "odte/domain/document_type.hpp"

using namespace odte::domain;

TEST(DocumentTypeTest, ValidTypes) {
    EXPECT_STREQ(to_string(DocumentType::INVOICE), "Invoice");
    EXPECT_STREQ(to_string(DocumentType::EXEMPT_INVOICE), "Exempt Invoice");
    EXPECT_STREQ(to_string(DocumentType::PURCHASE_INVOICE), "Purchase Invoice");
    EXPECT_STREQ(to_string(DocumentType::DISPATCH_GUIDE), "Dispatch Guide");
    EXPECT_STREQ(to_string(DocumentType::DEBIT_NOTE), "Debit Note");
    EXPECT_STREQ(to_string(DocumentType::CREDIT_NOTE), "Credit Note");
}

TEST(DocumentTypeTest, UnknownFallsBack) {
    EXPECT_STREQ(to_string(static_cast<DocumentType>(0)), "Unknown");
}
