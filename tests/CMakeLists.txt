# ── Tests ─────────────────────────────────────────────────────
add_executable(odte_tests
  test_main.cpp
)

target_link_libraries(odte_tests
  PRIVATE
    odte
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(odte_tests)
