#pragma once


template <typename T>
void fwd(const T& x);


namespace vox::bitset {

template <typename TFunc>
void ForEachSetBit2(const TFunc&) {
  fwd([](int) {
    const int bit_index_base = 0;
    (void)[&](int) {
      int v = bit_index_base;
    };
  });
}

}  // namespace vox::bitset

