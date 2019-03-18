// function_pointer.c
double avg(int a, int b, int c) {
    return (a + b + c) / 3.0;
}

int main(void) {
    double (*function)(int, int, int) = avg;
}