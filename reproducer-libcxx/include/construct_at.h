#ifndef CONSTRUCT_AT_H
#define CONSTRUCT_AT_H

#include <voidify.h>

template <class T>
constexpr void __construct_at(T* location, T arg) {
  void* loc = __voidify(*location);
  (void)loc;
}

#endif // CONSTRUCT_AT_H
