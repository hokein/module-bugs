#pragma once 
#include "set_bits2.h"

class QualifyingSet2 {
 public:
  void GetIndexes() const {
    vox::bitset::ForEachSetBit2([]() {});
  }
};
