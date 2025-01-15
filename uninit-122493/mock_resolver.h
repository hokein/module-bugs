#pragma once 
#include "set_bits2.h"

namespace vox {

class QualifyingSet2 {
 public:
  void GetIndexes() const {
    bitset::ForEachSetBit2([](int i) {});
  }
};
}  // namespace vox

template <typename Callable>
void call(Callable&& fn) {
  fwd<Callable>(fn);
}


template <typename>
class LazyStaticPtr23 {
 public:
  void get() const {
    call([]() {});
  }
};

