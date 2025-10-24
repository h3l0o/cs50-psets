#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  char text[] = "HELLO";
  int sizeof_text = strlen(text);
  char cipher[sizeof_text];
  char key[27] = "NQXPOMAFTRHLZGECYJIUWSKDVB";

  for (int i = 0; i < sizeof_text; i++) {
    cipher[i] = key[text[i] - 'A'];
  }
  printf("%s", cipher);
}
