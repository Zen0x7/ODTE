#include <gtest/gtest.h>

#include "odte/domain/electronic_document.hpp"

using namespace odte::domain;

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

TEST(ElectronicDocumentTest, AddReference) {
    ElectronicDocument doc;
    EXPECT_TRUE(doc.add_reference(Reference{}));
    EXPECT_EQ(doc.reference_count, 1u);
}

TEST(ElectronicDocumentTest, AddAdjustment) {
    ElectronicDocument doc;
    EXPECT_TRUE(doc.add_adjustment(Adjustment{}));
    EXPECT_EQ(doc.adjustment_count, 1u);
}

TEST(ElectronicDocumentTest, AddSubtotalSummary) {
    ElectronicDocument doc;
    EXPECT_TRUE(doc.add_subtotal_summary(SubtotalSummary{}));
    EXPECT_EQ(doc.subtotal_summary_count, 1u);
}
