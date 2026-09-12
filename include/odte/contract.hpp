#pragma once

#include <cstdint>
#include <stdexcept>

namespace odte::contract {

enum class Severity : std::uint8_t {
    PRECONDITION,
    POSTCONDITION,
    INVARIANT,
};

class violation : public std::runtime_error {
   public:
    violation(Severity severity, const char* expression, const char* file, int line);

    [[nodiscard]] Severity severity() const noexcept { return severity_; }

   private:
    Severity severity_;
};

void verify(bool condition, Severity severity, const char* expression, const char* file, int line);

}  // namespace odte::contract

#define ODTE_EXPECTS(expr)                                                                                       \
    ::odte::contract::verify(static_cast<bool>(expr), ::odte::contract::Severity::PRECONDITION, #expr, __FILE__, \
                             __LINE__)

#define ODTE_ENSURES(expr)                                                                                        \
    ::odte::contract::verify(static_cast<bool>(expr), ::odte::contract::Severity::POSTCONDITION, #expr, __FILE__, \
                             __LINE__)

#define ODTE_INVARIANT(expr) \
    ::odte::contract::verify(static_cast<bool>(expr), ::odte::contract::Severity::INVARIANT, #expr, __FILE__, __LINE__)
