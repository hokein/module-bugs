#pragma once

#include "string_view2.h"

namespace vox::bitset {

template <typename TFunc>
void ForEachWord2(const TFunc& func) {
  fwd<TFunc>(func);
}

template <typename TFunc>
void ForEachSetBit2(const TFunc& func) {
  ForEachWord2([](int) {
    const int bit_index_base = 0;
    (void)[&](int) {
      int v = bit_index_base;
    };
  });
}

}  // namespace vox::bitset

