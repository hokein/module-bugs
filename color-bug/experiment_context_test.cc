#include "util/c9/lazy.h"

namespace c9 {

template <typename T>
void WaitForCoroutine() {
  MakeCo<T>([]() -> Co<void> {
    co_return;
  });
}

void test() {
  c9::WaitForCoroutine<void>();
}
}
