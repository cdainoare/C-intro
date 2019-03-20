// fgetc_sample.c
#include <stdio.h>

int main(void) {
    FILE* fp;
    if (fopen_s(&fp, "file.txt", "r"))
        return 0;
    int value = fgetc(fp);
    fprintf(stdout, "%d\n", value);
}
