#include <stdio.h>
#include <stdlib.h>

int main() {

    char str_stickers[7], str_price[50];
    int stickers, stickers_left;
    double price, discounted_price;

    fgets(str_stickers, 9, stdin);
    fgets(str_price, 52, stdin);

    stickers = atoi(str_stickers);
    price = atof(str_price);

    if(stickers == 0) {
        
        printf("You get 0 percents discount.\n");
        printf("Total amount due is %.2lf Baht.\n", price);
        printf("And you have 0 stickers left.\n");

    }

    if(stickers == 1) { 

        discounted_price = price - ((10.0 * price) / 100.0);
        stickers_left = stickers - 1;
        printf("You get 10 percents discount.\n");
        printf("Total amount due is %.2lf Baht.\n", discounted_price);
        printf("And you have %d stickers left.\n", stickers_left); 

    }

    if(stickers == 2) {

        discounted_price = price - ((15.0 * price) / 100.0);
        stickers_left = stickers - 2;
        printf("You get 15 percents discount.\n");
        printf("Total amount due is %.2lf Baht.\n", discounted_price);
        printf("And you have %d stickers left.\n", stickers_left); 

    }

    if(stickers >= 3 && stickers < 6) { 

        discounted_price = price - ((20.0 * price) / 100.0);
        stickers_left = stickers - 3;
        printf("You get 20 percents discount.\n");
        printf("Total amount due is %.2lf Baht.\n", discounted_price);
        printf("And you have %d stickers left.\n", stickers_left);

    }

    if(stickers >= 6 && stickers < 9) { 
        
        discounted_price = price - ((30.0 * price) / 100.0);
        stickers_left = stickers - 6;
        printf("You get 30 percents discount.\n");
        printf("Total amount due is %.2lf Baht.\n", discounted_price);
        printf("And you have %d stickers left.\n", stickers_left); 

    }

    if(stickers >= 9) { 

        discounted_price = price - ((40.0 * price) / 100.0);
        stickers_left = stickers - 9;
        printf("You get 40 percents discount.\n");
        printf("Total amount due is %.2lf Baht.\n", discounted_price);
        printf("And you have %d stickers left.\n", stickers_left); 

    }

    return 0;

}