#include <stdio.h>

void calc_change(int change);

int main(void) {

  int payed;
  printf("Payed: ");
  scanf("%i", &payed);
  calc_change(payed);
}

void calc_change(int change) {
  int coins = 0;
  while (change > 0) {

    if (change >= 25) {

      change -= 25;

    } else if (change >= 10 && change < 25) {

      change -= 10;

    } else if (change >= 5 && change < 10) {

      change -= 5;

    } else if (change >= 1 && change < 5) {

      change -= 1;
    }
    coins++;
  }
  printf("Coins: %i\n", coins);
}
