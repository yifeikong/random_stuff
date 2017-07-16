#include <stdio.h>

int main() {
    int A[10][10][10];

    printf("%d\n", (void*)(A+1) - (void*)A);
    printf("%d\n", (void*)(A[0]+1) - (void*)A[0]);
    printf("%d\n", (void*)(A[0][0]+1) - (void*)A[0][0]);
    return 0;
}
