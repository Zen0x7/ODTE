#include "odte/contract.hpp"

#include <stdexcept>
#include <string>

namespace odte::contract {

namespace {

const char* severity_label(Severity severity) {
    switch (severity) {
        case Severity::PRECONDITION:
            return "precondition";
        case Severity::POSTCONDITION:
            return "postcondition";
        case Severity::INVARIANT:
            return "invariant";
    }
    return "contract";
}

std::string build_message(Severity severity, const char* expression, const char* file, int line) {
    return std::string("contract ") + severity_label(severity) + " violated: " + expression + " at " + file + ":" +
           std::to_string(line);
}

}  // namespace

violation::violation(Severity severity, const char* expression, const char* file, int line)
    : std::runtime_error(build_message(severity, expression, file, line)), severity_(severity) {}

void verify(bool condition, Severity severity, const char* expression, const char* file, int line) {
    if (!condition) {
        throw violation(severity, expression, file, line);
    }
}

}  // namespace odte::contract
