#include "ad/arena.h"
#include <stdlib.h>
#include <assert.h>

#define AD_ARENA_ALIGN 16
#define AD_ARENA_ALIGN_UP(size) (((size) + (AD_ARENA_ALIGN - 1)) & ~((size_t)AD_ARENA_ALIGN - 1))

void arena_init(Arena *a, size_t capacity){
    a->base = malloc(capacity);
    assert(a->base);
    a->offset = 0;  
    a->capacity = capacity;
}

void *arena_alloc(Arena *a, size_t size){   //size_t just speaks about how the variable is stored, when passing through malloc, it is just a number, no relation to whether its 8 bit or what not
    assert(size <= a->capacity - a->offset);
    size_t aligned = AD_ARENA_ALIGN_UP(size); 
    assert(aligned <= (a->capacity - a->offset));
    void *p = a->base + a->offset;
    a->offset += aligned;
    return p;
}

void arena_reset(Arena *a){
    a->offset = 0;
}

void arena_free(Arena *a){
    free(a->base);
    a->base = NULL;
    a->offset = 0;
    a->capacity = 0;
}