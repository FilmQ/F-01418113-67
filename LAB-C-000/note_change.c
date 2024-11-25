#include "stdio.h"

int main() {
    int amount = 19;

    int fifty, twenty, five, one = 0;

    fifty = amount / 50;    
    amount -= (fifty * 50);

    twenty = amount / 20;
    amount -= (twenty * 20);

    five = amount / 5;
    amount -= (five * 5);

    one = amount;

    printf("1: %d\n", one);
    printf("5: %d\n", five);
    printf("20: %d\n", twenty);
    printf("50: %d\n", fifty);

}