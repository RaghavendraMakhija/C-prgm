#include <stdio.h>

int main() {
    int sec, h, m, s;
    printf("Enter seconds: ");
    scanf("%d", &sec);

    h = sec / 3600;
    sec %= 3600;
    m = sec / 60;
    s = sec % 60;

    printf("Hours: %d, Minutes: %d, Seconds: %d\n", h, m, s);
    return 0;
}
