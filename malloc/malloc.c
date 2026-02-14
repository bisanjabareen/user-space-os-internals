#include <stdio.h>
#include <unistd.h>
#include "../utils/utils.h"

void* c_malloc(size_t size) {
    // find potential free block in list, using best fit.
    void* suitable_block = find_best_block(size + sizeof(Node));

    // in case no free block was found, fallback to sbrk
    if (suitable_block == NULL) {
        void* heap_head = sbrk(size + sizeof(Node));
        // adjusting the returned pointer so it points to the memory that can be
        // utilized by the user (skip metadata)
        (*(size_t*)heap_head) = size;
        suitable_block = (size_t*)heap_head + 1;
    }
    return suitable_block;

}