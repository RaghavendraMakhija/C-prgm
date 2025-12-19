/*Create a program that converts seconds into hours, minutes, and remaining seconds. */
#include <stdio.h>
int main()
{
  int sec = 1;
  printf("Enter seconds: ");
  if (scanf("%d", &sec) != 1 || sec < 0)
  {
    printf("Invalid input! Enter positive integer.");
    return 0;
  }
  printf("Hours  :%d\nMinutes:%d\nSeconds:%d\n", sec / 3600, (sec % 3600) / 60, sec % 60);
  return 0;
}
/*•	Code Logic
-	By using scanf, ensures that the input is a non-negative integer, rejecting invalid input.
-	Converts the total seconds into hours, minutes, and remaining seconds using integer division.
•	Edge Conditions
-	Rejects negative numbers and non-integer inputs.
-	Handles inputs smaller than 60 seconds, producing 0 hours and 0 minutes.*/
