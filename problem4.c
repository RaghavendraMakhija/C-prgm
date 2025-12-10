#include <stdio.h>
#include <string.h>

int main() {
    char pass[10], correct[] = "mayone";
    int attempts = 3;

    while(attempts--) {
        printf("Enter password: ");
        scanf("%s", pass);

        if(strcmp(pass, correct) == 0) {
            printf("Login successful.\n");
            return 0;
        }
        else
            printf("Wrong password. Attempts left: %d\n", attempts);
    }

    printf("Account Locked.\n");
    return 0;
}
