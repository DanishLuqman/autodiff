#ifndef AD_ARENA_H
#define AD_ARENA_H

#include <stddef.h>

typedef struct{
    unsigned char *base; // unsigned char to get pointer in 1 byte increment
    size_t offset; // how many bytes are used
    size_t capacity; //how many bytes exist.
} Arena;

void arena_init(Arena *a, size_t capacity);
void *arena_alloc(Arena *a, size_t size);
void arena_reset(Arena *a);
void arena_free(Arena *a);

#endif