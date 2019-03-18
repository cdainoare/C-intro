
// memory_experiment.c

#include <assert.h>
#include <stdio.h>

void scope_a(int** ptr){
    int a;
    *ptr = &a;
}
void scope_b(int** ptr){
    int b;
    *ptr = &b;
}

int main(){
    int* ptr_a;
    int* ptr_b;
    scope_a(&ptr_a);
    scope_b(&ptr_b);
    printf("%p %p", ptr_a, ptr_b);
    assert(ptr_a == ptr_b);
}
