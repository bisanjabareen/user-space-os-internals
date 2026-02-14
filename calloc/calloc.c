#include "../utils/utils.h"
#include "../malloc/malloc.h"

void* c_calloc(size_t size) {
    void* ptr = c_malloc(size);
    *(char*)ptr &= 0;
    return ptr;
}