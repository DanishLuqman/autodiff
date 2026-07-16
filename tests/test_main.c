#include "test.h"

TestCase ad_tests[AD_MAX_TESTS];
int ad_test_count = 0;
int ad_current_failed = 0;

void ad_register(const char *name, TestFn fn){
    if (ad_test_count < AD_MAX_TESTS){
        ad_tests[ad_test_count++] = (TestCase){name, fn};
    }
}

int main(void){
    int failed = 0;
    for (int i = 0; i < ad_test_count; i++){
        ad_current_failed = 0;
        printf("  %s\n", ad_tests[i].name);
        ad_tests[i].fn();
        if (ad_current_failed) failed++;
    }
    printf("\n%d/%d passed\n", ad_test_count - failed, ad_test_count);
    return failed > 0;
}