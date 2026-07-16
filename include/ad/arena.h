#ifndef AD_ARENA_H
#define AD_ARENA_H

#include <stddef.h>

typedef struct{
    unsigned char *size;
    size_t offset;
    size_t capacity;
} Arena;

void arena_init(Arena *a, size_t capacity);
void *arena_alloc(Arena *a, size_t size);
void arena_reset(Arena *a);
void arena_free(Arena *a);

#endif