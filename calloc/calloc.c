#include "../utils/utils.h"
#include "../malloc/malloc.h"

void* c_calloc(size_t size) {
    void* ptr = c_malloc(size);
    char* itr = ptr;
    for (size_t i = 0; i < size; i++) {
        *(itr++) = 0;
    }
    return ptr;
}