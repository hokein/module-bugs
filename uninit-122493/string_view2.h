#pragma once


template <typename T>
const T& fwd(const T& x) {
  return x;
}

