#include <stdio.h>

int i = 0;

int incre() {
    return i++;
}

int main() {
    incre();
    incre();
    printf("%d\n", i);
    return 0;
}
