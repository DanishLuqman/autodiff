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

TEST(arena_distinctness) {
    Arena a;
    arena_init(&a, 128);

    size_t block_size = sizeof(void *);
    size_t num_blocks = 4;
    void *ptrs[4];
    unsigned char fill_values[4] = {0xAA, 0xBB, 0xCC, 0xDD};

    for (size_t i = 0; i < num_blocks; i++) {
        ptrs[i] = arena_alloc(&a, block_size);
        CHECK(ptrs[i] != NULL);

        memset(ptrs[i], fill_values[i], block_size);
    }

    for (size_t i = 0; i < num_blocks; i++) {
        unsigned char *bytes = (unsigned char *)ptrs[i];

        for (size_t j = 0; i < num_blocks; i++) {
            CHECK(bytes[j] == fill_values[i]);
        }
    }


}

TEST(arena_exact_capacity) {
    Arena a;
    arena_init(&a, 480);

    void *p1 = arena_alloc(&a, 460); //should round up to 464
    CHECK(p1 != NULL && p1 == 16);

    void *p2 = arena_alloc(&a, 16);
    CHECK(p2 != NULL && p2 == 16);

    CHECK(a->offset == a->capacity);

    arena_free(&a);
}

TEST(arena_reset) {
    int capac = 64;
    Arena a
    arena_init(&a, capac);
    

    void *p1 = arena_alloc(&a, 48);
    arena_reset(&a);
    void *p2 = arena_alloc(&b, 48);
    CHECK(p1 == p2);

    arena_free(&a);
}