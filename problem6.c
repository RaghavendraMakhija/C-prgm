/*Implement a program count the number of vowels and consonants in the given string as well as to
scramble the characters of a string randomly. */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    char s[100];
    int v = 0, c = 0, d = 0;

    printf("Enter string: ");
    scanf(" %[^\n]", s);

    for (int i = 0; s[i]; i++)
    {
        char ch = tolower(s[i]);
        if (isalpha(ch))
        {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                v++;
            else
                c++;
        }
        else if (isdigit(ch)) d++;
    }
    srand(time(0));
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        int r = rand() % n;
        char t = s[i];
        s[i] = s[r];
        s[r] = t;
    }
    printf("Vowels = %d\nConsonants = %d\nDigits = %d\nScrambled = %s",
           v, c, d, s);
    return 0;
} 
/*•	Code Logic
 -	Using scanf to accept a string input, including spaces, up to 99 characters.
 -	Iterates through each character to count vowels, consonants, and digits:
 -	Using srand and rand to randomly shuffle (scramble) the characters of the string.
 -	Prints the counts of vowels, consonants, and digits, along with the scrambled string.*/
