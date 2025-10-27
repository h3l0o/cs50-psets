#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USAGE_ERROR 1;

char *cipher_text(char text[], int key) {
  static char cipher[20];
  for (int i = 0, length = strlen(text); i < length; i++) {

    if (isupper(text[i]))
      cipher[i] = ((text[i] - 'A' + key) % 26) + 'A';

    else if (islower(text[i]))
      cipher[i] = ((text[i] - 'a' + key) % 26) + 'a';

    else
      cipher[i] = text[i];
  }
  return cipher;
}

int main(int argc, char *argv[]) {
  char text[20];

  if (argc == 1 || argc > 2) {
    printf("Usage ./ceasar key");
    return USAGE_ERROR;
  }
  int key = atoi(argv[1]);

  //********Error checking********

  for (int i = 0, length = strlen(argv[1]); i < length; i++) {
    if (!isdigit(argv[1][i])) {
      printf("Usage ./ceasar key");
      return USAGE_ERROR;
    }
  }

  //******************************

  printf("Plain text: ");
  fgets(text, 20, stdin);

  printf("Cipher text: %s", cipher_text(text, key));
}
