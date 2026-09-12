#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <cstring>

#include "odte/contract.hpp"

namespace odte::domain {

class FolioReference {
 public:
  static constexpr std::size_t kMaxSize = 18;
  using Storage = std::array<char, kMaxSize + 1>;

  FolioReference() = default;
  explicit FolioReference(const char* value);

  [[nodiscard]] const char* value() const;
  [[nodiscard]] bool is_valid() const;

  friend bool operator==(const FolioReference& lhs, const FolioReference& rhs) {
    return lhs.valid_ && rhs.valid_ &&
           std::strcmp(lhs.data_.data(), rhs.data_.data()) == 0;
  }

  friend bool operator!=(const FolioReference& lhs, const FolioReference& rhs) {
    return !(lhs == rhs);
  }

  void invariant() const {
    ODTE_INVARIANT(valid_ == (data_[0] != '\0'));
  }

 private:
  Storage data_{};
  bool valid_{false};
};

}  // namespace odte::domain
