#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

char *cipher(char text[], int key);

int main(int argc, char *argv[]) {

  if (argc == 2 && isdigit(argv[1])) {
    char text[20];
    printf("Plain text: ");
    scanf("%s", text);

    cipher(text, (int)argv[1]);

  } else {
    printf("Usage: ./caesar.c key\n");
    return 1;
  }
}

char *cipher(char text[], int key) {

  if (key < 0)
    return "Key can't be a negative number";

  for (int i = 0, length = strlen(text); i < length; i++) {

    if (isalpha(text[i])) {

      text[i] = tolower(text[i]);

    } else
      return "Plain text contains non-Alphabitic characters";
  }

  static char cipher[20];

  for (int i = 0, length = strlen(text); i < length; i++) {

    cipher[i] = (text[i] + key) % 26;
    if (cipher[i] > 'z')
      cipher[i] -= 25;
  }
  return cipher;
}
