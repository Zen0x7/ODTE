#include <gtest/gtest.h>

#include <boost/contract.hpp>

namespace {

struct ContractEnvironment : ::testing::Environment {
    void SetUp() override {
        boost::contract::set_precondition_failure([](boost::contract::from) {
            throw boost::contract::assertion_failure(__FILE__, __LINE__, "precondition");
        });
        boost::contract::set_postcondition_failure([](boost::contract::from) {
            throw boost::contract::assertion_failure(__FILE__, __LINE__, "postcondition");
        });
        boost::contract::set_invariant_failure(
            [](boost::contract::from) { throw boost::contract::assertion_failure(__FILE__, __LINE__, "invariant"); });
    }
};

}  // namespace

::testing::Environment* const contract_environment = ::testing::AddGlobalTestEnvironment(new ContractEnvironment);
