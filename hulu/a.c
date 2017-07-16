#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

void reverse(char* left, char* right) {
    while (left < right) {
        char l = *left;
        *left = *right;
        *right = l;
        left++;
        right--;
    }
}


void reverseWords(char *s) {
    char* left = s, * right = s;
    bool in_word = false;
    while (*right) {
        if (in_word && isspace(*right)) {
            reverse(left, right - 1);
            in_word = false;
        }
        if (!in_word && !isspace(*right)) {
            left = right;
            in_word = true;
        }
        right++;
    }
    reverse(s, right - 1);
}

int main() {
    char s[] = "hello world";
    reverseWords(s);
    printf("%s", s);
    return 0;
}
