#include <stdio.h>
#include <math.h>
#include <stdlib.h>
// include <corecrt_math_defines.h>

#define FIXED_COST 5
#define BASE_COST 2


int main(int argc, char *argv[]) {

    char cin_pizza_size[3], cin_extra_pepperoni[3], cin_extra_cheese[3], cin_extra_mushroom[3];
    double price, cost, area, extra_cost = 0;

    printf("Welcome to My Pizza Shop!!\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    printf("Enter pizza size (1=s, 2=m, or 3=l): ");
    fgets(cin_pizza_size, 3, stdin);

    printf("Extra pepperoni? (1=yes, 0=no): ");
    fgets(cin_extra_pepperoni, 3, stdin);

    printf("Extra cheese? (1=yes, 0=no): ");
    fgets(cin_extra_cheese, 3, stdin);

    printf("Extra mushroom? (1=yes, 0=no): ");
    fgets(cin_extra_mushroom, 3, stdin);

    int pizza_size = atoi(cin_pizza_size);
    int extra_pepperoni = atoi(cin_extra_pepperoni);
    int extra_cheese = atoi(cin_extra_cheese);
    int extra_mushroom = atoi(cin_extra_mushroom);

    if(pizza_size == 1) { pizza_size = 10; }
    if(pizza_size == 2) { pizza_size = 16; }
    if(pizza_size == 3) { pizza_size = 20; }

    extra_cost += (extra_pepperoni * 0.5) + (extra_cheese * 0.25) + (extra_mushroom * 0.30);
    // printf("%.2lf", extra_cost);

    // PROCESS BEGIN

    area = (M_PI * (pizza_size * pizza_size)) / 4;
    cost = FIXED_COST + (BASE_COST * area) + (extra_cost * area);
    price = 3 * (cost) / 2;

    // PROCESS END


    // FORMAT OUT 
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~\n");;
    printf("Your order costs %.2lf baht.\n", price);
    printf("Thank you.");

    return 0;
}