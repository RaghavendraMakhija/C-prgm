#include <stdio.h>

void compress_recursive(char *str, int count) {
    // Base case: end of string
    if (*str == '\0') {
        if (count > 0) printf("%d", count);
        return;
    }

    // If next character is same, increment count
    if (*(str + 1) == *str) {
        compress_recursive(str + 1, count + 1);
    } else {
        // Print current character and its count
        printf("%c%d", *str, count + 1);
        compress_recursive(str + 1, 0);
    }
}

int main() {
    char str[100];
    printf("Enter string: ");
    scanf("%s", str);
    compress_recursive(str, 0);
    printf("Output string\n");
    return 0;
}
