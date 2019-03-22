// redirect.c
#include <stdio.h>

int main(void) {
    int value;
    scanf_s("%d", &value);
    printf_s("%d\n", value);
    fprintf_s(stderr, "%d\n", value);
}
