# ── Tests ─────────────────────────────────────────────────────
add_executable(odte_tests
  test_environment.cpp
  test_main.cpp
  test_amount.cpp
  test_business_name.cpp
  test_currency.cpp
  test_date.cpp
  test_date_time.cpp
  test_document_type.cpp
  test_electronic_document.cpp
  test_folio.cpp
  test_folio_reference.cpp
  test_payment_form.cpp
  test_payment_method.cpp
  test_percentage.cpp
  test_tax_code.cpp
  test_tax_number.cpp
  test_total_amounts.cpp
)

target_link_libraries(odte_tests
  PRIVATE
    odte
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(odte_tests)
