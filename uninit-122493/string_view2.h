#pragma once


template <typename T>
const T& fwd(const T& x) {
  return x;
}

namespace vox::bitset {

template <typename TFunc>
void ForEachWord2(TFunc&& func) {
  fwd<TFunc>(func);
}

}  // namespace vox::bitset

