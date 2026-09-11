#pragma once

#include <string_view>

namespace odte {

constexpr int VERSION_MAJOR = 0;
constexpr int VERSION_MINOR = 0;
constexpr int VERSION_PATCH = 0;

std::string_view get_version();

} // namespace odte
