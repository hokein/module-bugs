#pragma once

#include "string_view2.h"

namespace vox::bitset {

template <typename TFunc>
void ForEachSetBit2(TFunc&& func) {
  ForEachWord2([&](int word_index) {
    const int bit_index_base = 0;
    (void)[&](int offset) {
      int v = bit_index_base;
    };
  });
}

}  // namespace vox::bitset

