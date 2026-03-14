#ifndef SH2_MALLOC_H
#define SH2_MALLOC_H

#include <stddef.h>

void *sh2_malloc(size_t size);
void sh2_free(void *ptr);
void print_free_list(void);

#endif