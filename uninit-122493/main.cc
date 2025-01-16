#include "sql_transform_builder.h"

template <typename Callable>
void get(const Callable& fn) {
  fwd<Callable>(fn);
}

namespace {

void test() {
  get([]() {});
  DoTransform<int>();
}

} // namespace

