#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fp;
    char filename[200];

    printf("Enter file name (with path if needed): ");
    scanf("%199s", filename);

    fp = fopen(filename, "r");
    if (!fp) {
        printf("File not found.\n");
        return 1;
    }

    int ch, lastChar = 0;
    int chars = 0, words = 0, lines = 0;
    int inWord = 0;

    while ((ch = fgetc(fp)) != EOF) {
        chars++;
        lastChar = ch;

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

    printf("\nCharacters : %d", chars);
    printf("\nWords      : %d", words);
    printf("\nLines      : %d\n", lines);

    fclose(fp);
    return 0;
}