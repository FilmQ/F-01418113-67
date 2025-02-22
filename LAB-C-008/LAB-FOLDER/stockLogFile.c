#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _product {
    char name[30];
    int amount;
    double totalCost;
} Product;

void printStock(Product stock[], int nStock)
{
    int i;
    printf("%-20s|%6s|%-10s\n", "    Product Name", "Amount", "     Total");
    for (i = 0; i < nStock; i++) {
        printf("%-20s|%6d|%10.2lf\n",
            stock[i].name, stock[i].amount, stock[i].totalCost);
    }
}

void reportStock(char* filename) 
{
    FILE * stockFile;
    stockFile = fopen(filename, "r");

    if(stockFile == NULL)
        return;

    char str_DateISOFormat[21], str_DateTime[21], str_ProductType[21];
    int n_ProductSold = 0;
    double n_Price = 0;

    int n_uniqueProductType = 0;
    fscanf(stockFile, "%d", &n_uniqueProductType);

    // Empty log.
    if(n_uniqueProductType == 0) {
        printStock(NULL, 0);
        return;
    }

    Product productsArray[n_uniqueProductType];
    int j = 0;

    int breaker1 = 0, breaker2 = 0;

    while(!feof(stockFile))
    {
        fscanf(stockFile, " %[^,],%[^,],%[^,],%d,%lf [^\n]", // ts pmo bro
                                                                            str_DateISOFormat, 
                                                                            str_DateTime, 
                                                                            str_ProductType, 
                                                                            &n_ProductSold, 
                                                                            &n_Price);

        for(int k = 0; k < n_uniqueProductType; k++) {

            if(strcmp(productsArray[k].name, str_ProductType) == 0 ) {
                productsArray[k].amount += n_ProductSold;
                productsArray[k].totalCost += n_Price;
                break;
            }

            else if(k == j) {
                strcpy(productsArray[j].name, str_ProductType);
                productsArray[j].amount = n_ProductSold;
                productsArray[j].totalCost = n_Price;
                j++;
                break;
            }
            
            else 
                continue;
        }
            
    }

    fclose(stockFile);
    printStock(productsArray, n_uniqueProductType);
    
}

int main()
{
    char filename[20];
    scanf("%s", filename);
    reportStock(filename);
}