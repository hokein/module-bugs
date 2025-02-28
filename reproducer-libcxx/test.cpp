#include <construct_at.h>

void foo(int* ptr) {
    __construct_at(ptr, 3);
}
