#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_TEXT 2000 // Max size for input array
#define BEFORE1 100   // A return code for case before 1
#define AFTER16 200   // A return code for case 16+

// Prototypes
int number_of_words(const char text[]);
int number_of_letters(const char text[]);
int number_of_sentences(const char text[]);
int calculate_grade(const char text[]);

int main(void) {
  char text[MAX_TEXT];

  // Getting user input using fgets instead of scanf("%i", text) because scanf
  // will read only the first word and stop at the space
  printf("Text: ");
  fgets(text, MAX_TEXT, stdin);

  int grade = calculate_grade(text);
  if (grade == BEFORE1)
    printf("Before Grade 1\n");
  else if (grade == AFTER16)
    printf("Grade 16+\n");
  else
    printf("Grade %i\n", grade);
}

int calculate_grade(const char text[]) {
  double L;
  double S;
  double letters = number_of_letters(text);
  double sentences = number_of_sentences(text);
  double words = number_of_words(text);

  // Calculating vars for CLI equation
  L = (letters / words) * 100;
  S = (sentences / words) * 100;

  double CLI_eq = 0.0588 * L - 0.296 * S - 15.8;

  // Using special return codes for the 2 cases before 1 and 16+
  if (CLI_eq < 1)
    return 100;
  else if (CLI_eq >= 16)
    return 200;

  // Rounding grade if not from special cases
  int grade = (int)(CLI_eq + 0.5);

  return grade;
}

int number_of_words(const char text[]) {
  int space = 0;
  int words = 0;

  for (int i = 0, length = strlen(text); i < length; i++) {

    // Counting spaces in text
    if (isspace(text[i]))
      space++;
  }

  // I realized that words will = spaces + 1
  // Check for your self
  words = space + 1;
  return words;
}

int number_of_letters(const char text[]) {
  int letters = 0;

  for (int i = 0, length = strlen(text); i < length; i++) {

    // Ignoring spaces or punct to only count letters
    if (isspace(text[i]) || ispunct(text[i]))
      continue;
    letters++;
  }

  return letters;
}

int number_of_sentences(const char text[]) {
  int sentences = 0;

  for (int i = 0, length = strlen(text); i < length; i++) {

    // Online approaches use ispunct to count sentences, but if "you're" is
    // going to be counted as a sentence, so this approach is better
    if (text[i] == '.' || text[i] == '?' || text[i] == '!')
      sentences++;
  }

  return sentences;
}
