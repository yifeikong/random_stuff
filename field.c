#include <stdio.h>

struct X {
    int i : 3, j : 5, k : 24;
};

struct Y {
    int i : 3, j : 5, k : 25;
};

struct Z {
    int i : 3, : 0, j : 5; // nice syntax huh ?
};

int main() {
    // 结果分别是 4 8 8
    printf("%d %d %d", sizeof(struct X), sizeof(struct Y), sizeof(struct Z));
}
