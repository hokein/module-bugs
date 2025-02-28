#ifndef VOIDIFY_H
#define VOIDIFY_H

template <class T>
__attribute__((__always_inline__)) void* __voidify(T& from) {
  return const_cast<void*>(static_cast<const volatile void*>(&from));
}

#endif // VOIDIFY_H
