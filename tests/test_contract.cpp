#include <gtest/gtest.h>

#include <string>

#include "odte/contract.hpp"

using odte::contract::Severity;
using odte::contract::violation;

TEST(ContractTest, VerifyPasses) {
    EXPECT_NO_THROW(odte::contract::verify(true, Severity::PRECONDITION, "cond", __FILE__, __LINE__));
    EXPECT_NO_THROW(odte::contract::verify(true, Severity::POSTCONDITION, "cond", __FILE__, __LINE__));
    EXPECT_NO_THROW(odte::contract::verify(true, Severity::INVARIANT, "cond", __FILE__, __LINE__));
}

TEST(ContractTest, PreconditionViolation) {
    try {
        odte::contract::verify(false, Severity::PRECONDITION, "x > 0", __FILE__, __LINE__);
        FAIL();
    } catch (const violation& error) {
        EXPECT_EQ(error.severity(), Severity::PRECONDITION);
        EXPECT_NE(std::string(error.what()).find("precondition"), std::string::npos);
    }
}

TEST(ContractTest, PostconditionViolation) {
    try {
        odte::contract::verify(false, Severity::POSTCONDITION, "x > 0", __FILE__, __LINE__);
        FAIL();
    } catch (const violation& error) {
        EXPECT_EQ(error.severity(), Severity::POSTCONDITION);
        EXPECT_NE(std::string(error.what()).find("postcondition"), std::string::npos);
    }
}

TEST(ContractTest, InvariantViolation) {
    try {
        odte::contract::verify(false, Severity::INVARIANT, "x > 0", __FILE__, __LINE__);
        FAIL();
    } catch (const violation& error) {
        EXPECT_EQ(error.severity(), Severity::INVARIANT);
        EXPECT_NE(std::string(error.what()).find("invariant"), std::string::npos);
    }
}

TEST(ContractTest, MacroPasses) {
    EXPECT_NO_THROW(ODTE_EXPECTS(true));
    EXPECT_NO_THROW(ODTE_ENSURES(true));
    EXPECT_NO_THROW(ODTE_INVARIANT(true));
}

TEST(ContractTest, MacroViolationsThrow) {
    EXPECT_THROW(ODTE_EXPECTS(false), violation);
    EXPECT_THROW(ODTE_ENSURES(false), violation);
    EXPECT_THROW(ODTE_INVARIANT(false), violation);
}

TEST(ContractTest, UnknownSeverityFallsBack) {
    violation error(static_cast<Severity>(99), "x > 0", __FILE__, __LINE__);
    EXPECT_NE(std::string(error.what()).find("contract"), std::string::npos);
}
