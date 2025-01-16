#pragma once

#include "set_bits2.h"

class QualifyingSet3 {
 public:
  void GetIndexes() const {
    vox::bitset::ForEachSetBit2([]() {});
  }
};

template <typename T>
void DoTransform() {
  vox::bitset::ForEachSetBit2([]() {});
}

