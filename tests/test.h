#ifndef AD_TEST_H
#define AD_TEST_H

#include <stdio.h>

typedef void (*TestFn)(void); // pointer to func that takes no args and returns null

typedef struct {
    const char *name;
    TestFn fn;
} TestCase;

#define AD_MAX_TESTS 256
extern TestCase ad_tests[AD_MAX_TESTS];
extern int ad_test_count;
extern int ad_current_failed;

void ad_register(const char *name, TestFn fn);

// registers a test
// marks a function to run automatically before main
// register_##name merges token together
#define TEST(name) \ 
    static void name(void); \
    __attribute__((constructor)) \ 
    static void register_##name(void) { ad_register(#name, name); } \  
    static void name(void) \

#define CHECK(cond) \
    do { \
        if(!(cond)){ \
            fprintf(stderr, "   FAIL %s:%d: %s\n", \
                    __FILE__, __LINE__, #cond); \
            ad_current_failed = 1; \
        } \
    } while (0) \

#endif