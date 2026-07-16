#include "test.h"
#include "ad/arena.h"
#include <stdint.h>
#include <string.h>

TEST(arena_alignment) {
    Arena a;
    arena_init(&a, 1024);

    void *p1 = arena_alloc(&a, 1);
    void *p2 = arena_alloc(&a, 1);

    CHECK((uintptr_t)p1 % 16 == 0);
    CHECK((uintptr_t)p2 % 16 == 0);
    CHECK(p2 - p1 == 16);

    arena_free(&a);
}