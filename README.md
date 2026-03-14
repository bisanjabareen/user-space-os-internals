# sh2-malloc-allocator

Custom memory allocator using sbrk() with first-fit strategy.

## Features

- First-fit allocation
- Explicit free list
- Block splitting
- Coalescing
- 8-byte alignment

## Build
```bash
gcc -o test src/sh2_malloc.c tests/test.c -I./include
```

## Run
```bash
./test
```

## API

- `void *sh2_malloc(size_t size)` - Allocate memory
- `void sh2_free(void *ptr)` - Free memory
- `void print_free_list(void)` - Debug helper

## Structure
```
.
├── include/sh2_malloc.h
├── src/sh2_malloc.c
├── tests/test.c
└── README.md
```