#include "mock_resolver.h"
#include "sql_transform_builder.h"

namespace {

void test() {
  LazyStaticPtr23<int>().get();
  DoTransform<int>();
}

} // namespace

