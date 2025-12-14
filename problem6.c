#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char s[100];
    int v = 0, c = 0;

    printf("Enter string: ");
    gets(s);

    for(int i = 0; s[i]; i++) {
        if(isalpha(s[i])) {
            char ch = tolower(s[i]);
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') v++;
            else c++;
        }
    }

    printf("Vowels: %d\nConsonants: %d\n", v, c);

    srand(time(0));
    int len = strlen(s);
    for(int i = 0; i < len; i++) {
        int r = rand() % len;
        char temp = s[i];
        s[i] = s[r];
        s[r] = temp;
    }

    printf("Scrambled: %s\n", s);
    return 0;
}
    printf("Scrambled: %s\n", s);
    return 0;
}
