/*Write a program that accepts n products' details and calculates and displays the total value of the
inventory (i.e., quantity * price). Find the product with the highest quantity and the product with the
highest Price and display their details.
Create a structure to represent a product in an inventory. The structure should include: Product ID (integer) Product Name (string) Quantity (integer) Price (float) */ \

#include<stdio.h>
#include <string.h>
#include <ctype.h>

struct product // define the structure product which groups id, name, quantity, and price so each product is handled as one logical unit
{
    int id;
    char name[50];
    int quantity;
    float price;
};
int isUniqueID(struct product p[], int count, int id); // declaring functions isUniqueID and isUniqueName to separate validation logic from main
int isUniqueName(struct product p[], int count, char name[]);
int main()
{
    int n;
    char line[100], extra;
    float totalValue = 0;
    while (1)
    {
        printf("Enter number of products: "); // creating an infinite while loop to repeatedly ask for number of products until a valid positive integer is entered
        if (!fgets(line, sizeof(line), stdin) ||
            sscanf(line, "%d %c", &n, &extra) != 1 ||
            n <= 0)
        {
            printf("Invalid input. Enter a positive integer.\n");
            continue;
        }
        break;
    }
    struct product p[n];
    int maxQtyIndex = 0, maxPriceIndex = 0;
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter details for Product %d\n", i + 1);
        while (1)
        {
            printf("Product ID: "); // validate product ID using fgets and sscanf to ensure that it is positive and unique using isUniqueID
            if (!fgets(line, sizeof(line), stdin) ||
                sscanf(line, "%d %c", &p[i].id, &extra) != 1 ||
                p[i].id <= 0)
            {
                printf("Invalid ID. Try again.\n");
                continue;
            }
            if (!isUniqueID(p, i, p[i].id))
            {
                printf("Duplicate Product ID. Enter a unique one.\n");
                continue;
            }
            break;
        }
        while (1)
        {
            printf("Product Name: "); // read product name, strip newline, ensure it contains at least one alphabet, and ensure uniqueness using isUniqueName
            if (!fgets(p[i].name, sizeof(p[i].name), stdin))
            {
                printf("Invalid name. Try again.\n");
                continue;
            }
            p[i].name[strcspn(p[i].name, "\n")] = '\0';
            int hasLetter = 0;
            for (int k = 0; p[i].name[k]; k++)
            {
                if (isalpha(p[i].name[k]))
                {
                    hasLetter = 1;
                    break;
                }
            }
            if (!hasLetter)
            {
                printf("Name must contain letters.\n");
                continue;
            }
            if (!isUniqueName(p, i, p[i].name))
            {
                printf("Duplicate Product Name. Enter a unique name.\n");
                continue;
            }
            break;
        }
        while (1)
        {
            printf("Quantity: ");
            if (!fgets(line, sizeof(line), stdin) ||
                sscanf(line, "%d %c", &p[i].quantity, &extra) != 1 ||
                p[i].quantity < 0)
            {
                printf("Invalid quantity. Try again.\n");
                continue;
            }
            break;
        }
        while (1)
        {
            printf("Price: ");
            if (!fgets(line, sizeof(line), stdin) ||
                sscanf(line, "%f %c", &p[i].price, &extra) != 1 ||
                p[i].price < 0)
            {
                printf("Invalid price. Try again.\n");
                continue;
            }
            break;
        }
        totalValue += p[i].quantity * p[i].price;
        if (p[i].quantity > p[maxQtyIndex].quantity) // compare current quantity with stored maximum and update maxQtyIndex if needed
            maxQtyIndex = i;
        if (p[i].price > p[maxPriceIndex].price) // compare current price with stored maximum and update maxPriceIndex if needed
            maxPriceIndex = i;
    }
    printf("\n===================\n");
    printf("INVENTORY SUMMARY\n");
    printf("===================\n");
    printf("Total Inventory Value : Rupees %.2f\n", totalValue);
    printf("\nProduct with HIGHEST QUANTITY:\n");
    printf("ID       : %d\n", p[maxQtyIndex].id);
    printf("Name     : %s\n", p[maxQtyIndex].name);
    printf("Quantity : %d\n", p[maxQtyIndex].quantity);
    printf("Price    : %.2f\n", p[maxQtyIndex].price);
    printf("\nProduct with HIGHEST PRICE:\n");
    printf("ID       : %d\n", p[maxPriceIndex].id);
    printf("Name     : %s\n", p[maxPriceIndex].name);
    printf("Quantity : %d\n", p[maxPriceIndex].quantity);
    printf("Price    : %.2f\n", p[maxPriceIndex].price);
    return 0;
}
/*FUNCTIONS*/
int isUniqueID(struct product p[], int count, int id) // define isUniqueID function which scans previously entered products to prevent duplicate IDs
{
    for (int i = 0; i < count; i++)
    {
        if (p[i].id == id)
            return 0;
    }
    return 1;
}
int isUniqueName(struct product p[], int count, char name[]) // define isUniqueName function which compares names using strcmp to prevent duplicate product names
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(p[i].name, name) == 0)
            return 0;
    }
    return 1;
}
