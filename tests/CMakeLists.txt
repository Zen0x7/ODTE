# ── Tests ─────────────────────────────────────────────────────
add_executable(odte_tests
  test_main.cpp
  test_domain.cpp
)

target_link_libraries(odte_tests
  PRIVATE
    odte
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(odte_tests)
