#define _DEBUG
#undef NDEBUG
// relationaloperator.c
#include <assert.h>
#include <stdio.h>
int main(void){
    int a, b;
    scanf_s("%d %d", &a, &b);
    assert(a < b == a < b);
    assert(a > b == b < a);
    assert(a <= b == ((a < b) || (!(a < b) && !(b < a))));
    assert(a >= b == ((b < a) || (!(a < b) && !(b < a))));
}
