#include <limits.h>
#include <stdio.h>

int add(unsigned int* result_buffer, unsigned int a, unsigned int b) {
    return b <= UINT_MAX - a ? *result_buffer = a + b, 0 : -1;
}

int main(void) {
    unsigned int ans;
    add(&ans, 10, 14);
    printf_s("%u\n", ans);
    if(add(&ans, UINT_MAX - 2, 14) == 0)
        printf_s("%u\n", ans);
}
