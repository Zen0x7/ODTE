#pragma once

#include <array>
#include <cstddef>

#include "odte/contract.hpp"
#include "odte/domain/adjustment.hpp"
#include "odte/domain/document_header.hpp"
#include "odte/domain/issuer.hpp"
#include "odte/domain/line_item.hpp"
#include "odte/domain/recipient.hpp"
#include "odte/domain/reference.hpp"
#include "odte/domain/subtotal_summary.hpp"
#include "odte/domain/total_amounts.hpp"

namespace odte::domain {

static constexpr std::size_t kMaxLineItems = 60;
static constexpr std::size_t kMaxReferences = 40;
static constexpr std::size_t kMaxAdjustments = 20;
static constexpr std::size_t kMaxSubtotalSummaries = 20;

struct ElectronicDocument {
  DocumentHeader header;
  Issuer issuer;
  Recipient recipient;
  TotalAmounts totals;
  std::array<LineItem, kMaxLineItems> line_items{};
  std::size_t line_item_count{0};
  std::array<Reference, kMaxReferences> references{};
  std::size_t reference_count{0};
  std::array<Adjustment, kMaxAdjustments> adjustments{};
  std::size_t adjustment_count{0};
  std::array<SubtotalSummary, kMaxSubtotalSummaries> subtotal_summaries{};
  std::size_t subtotal_summary_count{0};

  bool add_line_item(const LineItem& item) {
    if (line_item_count >= kMaxLineItems) {
      return false;
    }
    line_items[line_item_count] = item;
    ++line_item_count;

    ODTE_ENSURES(line_item_count <= kMaxLineItems);
    invariant();
    return true;
  }

  bool add_reference(const Reference& reference) {
    if (reference_count >= kMaxReferences) {
      return false;
    }
    references[reference_count] = reference;
    ++reference_count;

    ODTE_ENSURES(reference_count <= kMaxReferences);
    invariant();
    return true;
  }

  bool add_adjustment(const Adjustment& adjustment) {
    if (adjustment_count >= kMaxAdjustments) {
      return false;
    }
    adjustments[adjustment_count] = adjustment;
    ++adjustment_count;

    ODTE_ENSURES(adjustment_count <= kMaxAdjustments);
    invariant();
    return true;
  }

  bool add_subtotal_summary(const SubtotalSummary& summary) {
    if (subtotal_summary_count >= kMaxSubtotalSummaries) {
      return false;
    }
    subtotal_summaries[subtotal_summary_count] = summary;
    ++subtotal_summary_count;

    ODTE_ENSURES(subtotal_summary_count <= kMaxSubtotalSummaries);
    invariant();
    return true;
  }

  void invariant() const {
    ODTE_INVARIANT(line_item_count <= kMaxLineItems);
    ODTE_INVARIANT(reference_count <= kMaxReferences);
    ODTE_INVARIANT(adjustment_count <= kMaxAdjustments);
    ODTE_INVARIANT(subtotal_summary_count <= kMaxSubtotalSummaries);
  }
};

}  // namespace odte::domain
