#pragma once

#include <array>
#include <boost/contract.hpp>
#include <cstddef>
#include <cstdint>

#include "odte/domain/amount.hpp"
#include "odte/domain/business_name.hpp"
#include "odte/domain/date.hpp"
#include "odte/domain/document_type.hpp"
#include "odte/domain/folio.hpp"
#include "odte/domain/payment_method.hpp"
#include "odte/domain/tax_number.hpp"

namespace odte::domain {

struct DocumentHeader {
  DocumentType document_type{DocumentType::INVOICE};
  Folio folio;
  Date issuance_date;
};

struct Issuer {
  TaxNumber tax_number;
  BusinessName business_name;
  std::array<char, 81> activity_type{};
  std::array<char, 21> phone{};
  std::array<char, 81> email{};
  std::array<std::uint32_t, 4> economic_activities{};
  std::size_t economic_activity_count{0};
};

struct Recipient {
  TaxNumber tax_number;
  BusinessName business_name;
  std::array<char, 41> activity_type{};
  std::array<char, 71> address{};
  std::array<char, 21> commune{};
  std::array<char, 21> city{};
};

struct Totals {
  Amount net_amount{0};
  Amount exempt_amount{0};
  Amount tax_amount{0};
  Amount total_amount{0};

  void invariant() const {
    if (net_amount.is_valid() && exempt_amount.is_valid() &&
        tax_amount.is_valid() && total_amount.is_valid()) {
      Amount expected;
      Amount sum1;
      Amount sum2;
      if (net_amount.add(exempt_amount, sum1) && sum1.add(tax_amount, sum2)) {
        BOOST_CONTRACT_ASSERT(total_amount == sum2);
      }
    }
  }
};

struct LineItem {
  std::uint32_t sequence_number{0};
  std::array<char, 256> description{};
  std::array<char, 36> code{};
  std::uint32_t quantity{0};
  Amount unit_price{0};
  Amount discount_amount{0};
  Amount line_total{0};

  void invariant() const {
    if (quantity > 0 && unit_price.is_valid()) {
      BOOST_CONTRACT_ASSERT(line_total.is_valid());
    }
  }
};

static constexpr std::size_t kMaxLineItems = 2000;

struct ElectronicDocument {
  DocumentHeader header;
  Issuer issuer;
  Recipient recipient;
  Totals totals;
  std::array<LineItem, kMaxLineItems> line_items{};
  std::size_t line_item_count{0};
  PaymentMethod payment_method{PaymentMethod::OTHER};

  bool add_line_item(const LineItem& item) {
    boost::contract::check c = boost::contract::public_function<ElectronicDocument>(this)
        .postcondition([&] {
          BOOST_CONTRACT_ASSERT(line_item_count <= kMaxLineItems);
        });

    if (line_item_count >= kMaxLineItems) {
      return false;
    }
    line_items[line_item_count] = item;
    ++line_item_count;
    return true;
  }

  void invariant() const {
    BOOST_CONTRACT_ASSERT(line_item_count <= kMaxLineItems);
  }
};

}  // namespace odte::domain
