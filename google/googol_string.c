#include <stdio.h>
#include <stdlib.h>

int googol_string(unsigned long long k) {

    if (k == 0)
        return 0;
    if (k == 1)
        return 0;
    if (k == 2)
        return 1;

    if ((k & (k - 1)) == 0)
        return 0;

    if (k & (k % 2)) 
        return !googol_string(k / 2 - k % 2);
    else
        return googol_string(k % 2);
    /*
    int reverse_swith = 0;
    int bit_len = sizeof(k) * 8;

    for (int i = bit_len - 1; i >= 0; i--) {
        if (k & (1 << i)) {
            return !googol_string(k & ~(1 << i));
        } else {
            return googol_string(k & ~(1 << i));
        }
    }
    */
}

int main() {
    /*
    int n;
    scanf("%d", &n);
    for (int i= 1; i <= n; i++) {
        unsigned long long k;
        scanf("%llu", &k);
        printf("Case #%d: %d\n", i, googol_string(k));
    }
    */
    for (int i = 1; i < 11; i++)
        printf("%d ", googol_string(i-1));
    return 0;
}
