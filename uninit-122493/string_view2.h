#pragma once

template <typename T>
struct remove_ref {
  using type = T;
};
template <typename T>
struct remove_ref<T&> {
  using type = T;
};

template <typename T>
T&& fwd(typename remove_ref<T>::type& x) {
  return static_cast<T&&>(x);
}

namespace vox::bitset {

template <typename TFunc>
void ForEachWord2(TFunc&& func) {
  fwd<TFunc>(func);
}

}  // namespace vox::bitset

