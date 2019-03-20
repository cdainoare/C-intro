
// fputs_sample.c
#include <stdio.h>

int main(void) {
    FILE* fp;
    if (fopen_s(&fp, "file.txt", "w"))
        return 0;
    fputs("C programming language", fp);
}
