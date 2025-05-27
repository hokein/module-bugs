#ifndef UTIL_C9_LAZY_H_
#define UTIL_C9_LAZY_H_

#include "util/c9/co.h"

namespace c9 {
template <typename T, typename F>
Co<T> MakeCo(F f)
{
  co_return co_await f();
}
}

inline c9::Co<void> DoNothing() { co_return; }

#endif  // UTIL_C9_LAZY_H_
