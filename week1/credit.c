#include <stdio.h>
#include <string.h>

int check_valid(const char ccNum[20]) {
  // Get cc number from user

  int length = strlen(ccNum);
  int sum = 0;
  int sum2 = 0;
  int num;
  int write_index = 0;
  int clean_ccNum[16];
  switch (ccNum[0] - '0') {
  case 5:
    printf("MASTERCARD\n");
    break;
  case 3:
    printf("AMEX\n");
    break;
  case 4:
    printf("VISA\n");
    break;

  default:
    printf("INVALID\n");
    break;
  }

  // Go through each element and filter out non-digits
  for (int ccIndex = 0; ccIndex < length; ccIndex++) {

    if (ccNum[ccIndex] >= '0' && ccNum[ccIndex] <= '9') {

      clean_ccNum[write_index] = ccNum[ccIndex];
      write_index++;
    }
  }

  for (int i = write_index - 2; i >= 0; i -= 2) {
    // Convert from ascii number to real value
    int num = clean_ccNum[i] - '0';

    num *= 2;
    // If the number is greater than 9 use this simple math operation to
    // calculate the sum of the 2 digits

    if (num > 9)
      num -= 9;

    sum += num;
  }

  // Loops over not doubled numbers and get there sum
  for (int j = write_index - 1; j >= 0; j -= 2) {
    num = ccNum[j] - '0';
    sum2 += num;
  }
  int total = sum + sum2;

  return (total % 10 == 0);
}

int main(void) {
  char ccNum[] = "4539 1488 0343 6467";
  printf("The cc is %s", check_valid(ccNum) ? "valid" : "invalid");
}
