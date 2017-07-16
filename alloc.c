#include <stdio.h>
#include <stdlib.h>

int main() {
    int MB = 0;
    while (malloc(1 << 20))
        printf("allocated %d MB tatal\n", ++MB);
}
