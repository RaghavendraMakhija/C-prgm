/*Write a program to read a file and count the number of characters, words, and lines in a file. */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char path[256];
    FILE *fp;
    while (1) { //loop keeps asking for file path until fopen succeeds preventing null file pointer usage
        printf("Enter the file path: ");
        if (!fgets(path, sizeof(path), stdin)) //removes newline from fgets to avoid fopen failure due to trailing newline edge condition
            return 1;
        path[strcspn(path, "\n")] = '\0';   
        fp = fopen(path, "r");
        if (fp != NULL)
            break;
        printf("Could not open file. Please try again.\n");
    }
    int ch;
    int chars = 0, words = 0, lines = 0;
    int inWord = 0;
    int lastChar = 0;
    while ((ch = fgetc(fp)) != EOF) { //while loop with fgetc reads file character by character until EOF core looping mechanism
        chars++;
        lastChar = ch; //stores lastChar to later detect missing trailing newline edge condition
        if (ch == '\n')
            lines++;
        if (isspace((unsigned char)ch))
            inWord = 0;
        else if (!inWord) {
            inWord = 1;
            words++;
        }
    }
    if (chars > 0 && lastChar != '\n')
        lines++;

    fclose(fp);
    printf("\nCharacters : %d", chars);
    printf("\nWords      : %d", words);
    printf("\nLines      : %d\n", lines);
    return 0;
}
