#include <ctype.h>
#include <stdio.h>
#include <string.h>

void to_lowercase(char word[]);
int calculate_points(const char word[]);
int Game(char player1[], char player2[]);

int main(void) {

  char p1[20];
  char p2[20];

  printf("player1: ");
  scanf("%s", p1);
  printf("player2: ");
  scanf("%s", p2);

  Game(p1, p2);
}

int Game(char player1[], char player2[]) {

  to_lowercase(player1);
  to_lowercase(player2);

  int p1_points = calculate_points(player1);
  int p2_points = calculate_points(player2);

  // Comparing points to decide winner
  // Note: The return values are just for the sake of it was mentioned at the
  // end of the lecture

  if (p1_points == p2_points) {

    printf("Tie!");
    return 0; // 0: Tie
  } else if (p1_points > p2_points) {

    printf("player1 won!!");
    return 1; // 1: Player1 winner
  } else if (p1_points < p2_points) {

    printf("player2 won!!");
    return 2; // 2: Player2 winner

  } else {

    printf("Oops, something went wrong");
    return 3; // 3: An error happened in the app (not detailed for the sake of
              // simplicity)
  }
}

int calculate_points(const char word[]) {

  // Categorizing chars by points

  const char one_point[] = "aeilnorstu";
  const char two_points[] = "dg";
  const char three_points[] = "bcmp";
  const char four_points[] = "fhvwy";
  const char eight_points[] = "jx";
  const char ten_points[] = "qz";
  const char five_point = 'k';

  int points = 0;

  // Calculate points based on points for each letter

  for (int i = 0; word[i]; i++) {
    char c = tolower(word[i]);
    if (strchr(one_point, c))
      points += 1;
    else if (strchr(two_points, c))
      points += 2;
    else if (strchr(three_points, c))
      points += 3;
    else if (strchr(four_points, c))
      points += 4;
    else if (c == five_point)
      points += 5;
    else if (strchr(eight_points, c))
      points += 8;
    else if (strchr(ten_points, c))
      points += 10;
  }

  return points;
}

void to_lowercase(char word[]) {
  for (int i = 0, length = strlen(word); i < length; i++) {

    if (isupper(word[i]))
      word[i] = tolower(word[i]);
  }
}
