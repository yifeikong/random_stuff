#include <limits.h>
#include <stdio.h>
#include <ctype.h>
int myAtoi(char* str) {
    if (!str) return 0;
    int sign = 1;
    int result = 0;
    
    // discarding spaces
    while (isspace(*str))
        str++; 
    
    // determining sign
    if (*str == '-') sign = -1;
    if (*str == '+') sign = 1;
    str++;
    
    // constructing integer
    while (isdigit(*str)) {
        // handling overflow
        if (result > INT_MAX / 10 || result == INT_MAX && *str - '0' == INT_MAX % 10)
            return sign > 0 ? INT_MAX : INT_MIN;
        result = *str - '0' + result * 10;
        str++;
    }
    
    return result * sign;
}

int main() {
    printf("%d", myAtoi("1"));
    return 0;
}
