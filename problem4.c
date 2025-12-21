/*Create a program to simulate a simple login system with 3 attempts to enter the correct password. */
#include <stdio.h>
#include <string.h>

int main()
{
    char correct[20], pass[20];
    printf("Set your password: ");
    fgets(correct, sizeof(correct), stdin);
    correct[strcspn(correct, "\n")] = '\0';

    for (int i = 1; i <= 3; i++)
    {
        printf("Enter password: ");
        fgets(pass, sizeof(pass), stdin);
        pass[strcspn(pass, "\n")] = '\0';

        if (strcmp(pass, correct) == 0)
        {
            printf("Login Successful\n");
            return 0;
        }
        printf("Wrong password! Attempts left: %d\n", 3 - i);
    }
    printf("Account locked.\n");
    return 0;
}
/*•	Code Logic
-	By use of scanf to set a password of up to 19 characters.
-	Allows the user up to 3 attempts to enter the correct password.
-	Compares each input with the stored password using string comparison.
-	Prints "Login Successful" and exits if the password matches.
-	Locks the account after 3 incorrect attempts.*/

