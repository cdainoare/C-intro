// fgets_sample.c
#include <stdio.h>

int main(void) {
    FILE* fp;
    if (fopen_s(&fp, "file.txt", "r"))
        return 0;
    char line[256];
    fgets(line, 256, fp);
    fputs(line, stdout);
}
