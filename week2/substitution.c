#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define USAGE_ERROR 1;

char *substitution(char text[], char key[]);

int main(int argc, char *argv[]) {
  if (argc == 1 || argc > 2) {
    printf("Usage: ./substitution Key");
    return USAGE_ERROR;
  }

  for (int i = 0, length = strlen(argv[1]); i < length; i++) {

    if (isdigit(argv[1][i]) || strlen(argv[1]) < 26 || strlen(argv[1]) > 27) {
      printf("Key must be 26 letters with no digits");
      return USAGE_ERROR;

    } else if (islower(argv[1][i])) {
      printf("Key must be all UPPERCASE");
      return USAGE_ERROR;
    }
  }

  char text[30];
  printf("Plain text: ");
  fgets(text, 30, stdin);
  printf("Cipher text: %s", substitution(text, argv[1]));
}

char *substitution(char text[], char key[]) {
  int sizeof_text = strlen(text);
  int sizeof_key = strlen(key);
  char lower_key[27];
  static char cipher[30];

  for (int i = 0, lenght = sizeof_key; i < lenght; i++) {
    lower_key[i] = tolower(key[i]);
  }

  for (int i = 0; i < sizeof_text; i++) {
    if (islower(text[i]))
      cipher[i] = lower_key[text[i] - 'a'];

    else if (isupper(text[i]))
      cipher[i] = key[text[i] - 'A'];

    else
      cipher[i] = text[i];
  }

  return cipher;
}
