/*Implement a recursive function to compress a string by replacing consecutive duplicate characters with 
their count (e.g., aaabbc becomes a3b2c1). */
#include <stdio.h>
#include <string.h>

void compress_recursive(char *str, int count);
int main() {
    char str[100];
    printf("Enter string: "); //By using fgets and removing the trailing newline, the program ensures the input string is read correctly.
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    printf("Output string: ");
    compress_recursive(str, 0);
    return 0;
}
void compress_recursive(char *str, int count) { //compress_recursive function is used to compress the string by counting consecutive duplicate characters.
    if (*str == '\0') {
        if (count > 0)
            printf("%d", count); 
        return;
    }
    if (*(str + 1) == *str) { //increments count when the next character is the same as the current character.
        compress_recursive(str + 1, count + 1);
    } else { //When the next character differs then prints current character and its count
        printf("%c%d", *str, count + 1);
        compress_recursive(str + 1, 0);
    }
    return 0;
}
/*made changes to count and accept string with spaces as well.*/
