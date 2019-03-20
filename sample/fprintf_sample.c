// fprintf_sample.c
#include <stdio.h>

int main(void) {
    FILE* fp;
    if (fopen_s(&fp, "file.txt", "w"))
        return 0;
    int value = 13;
    fprintf(fp, "The value is %d\n", value);
}
