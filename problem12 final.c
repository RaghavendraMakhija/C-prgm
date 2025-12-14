#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct product {
    int id;
    char name[50];
    int quantity;
    float price;
};

int main() {
    int n;
    float totalValue = 0;
    char line[100], extra;

    /* ---------- NUMBER OF PRODUCTS ---------- */
    printf("Enter number of products: ");
    if (!fgets(line, sizeof(line), stdin) ||
        sscanf(line, "%d %c", &n, &extra) != 1 || n <= 0) {
        printf("Invalid input! Enter a positive integer only.\n");
        return 1;
    }

    struct product p[n];
    int maxQtyIndex = 0, maxPriceIndex = 0;

    /* ---------- PRODUCT DETAILS ---------- */
    for (int i = 0; i < n; i++) {

        printf("\n Enter details for Product %d\n", i + 1);

        /* Product ID */
        printf("Product ID: ");
        if (!fgets(line, sizeof(line), stdin) ||
            sscanf(line, "%d %c", &p[i].id, &extra) != 1 || p[i].id <= 0) {
            printf("Invalid Product ID.\n");
            return 1;
        }

        /* Product Name */
        printf("Product Name: ");
        if (!fgets(p[i].name, sizeof(p[i].name), stdin)) {
            printf("Invalid product name.\n");
            return 1;
        }
        p[i].name[strcspn(p[i].name, "\n")] = '\0';

        int hasLetter = 0;
        for (int k = 0; p[i].name[k]; k++) {
            if (isalpha(p[i].name[k])) {
                hasLetter = 1;
                break;
            }
        }
        if (!hasLetter) {
            printf("Product name must contain letters.\n");
            return 1;
        }

        /* Quantity */
        printf("Quantity: ");
        if (!fgets(line, sizeof(line), stdin) ||
            sscanf(line, "%d %c", &p[i].quantity, &extra) != 1 ||
            p[i].quantity < 0) {
            printf("Invalid quantity.\n");
            return 1;
        }

        /* Price */
        printf("Price: ");
        if (!fgets(line, sizeof(line), stdin) ||
            sscanf(line, "%f %c", &p[i].price, &extra) != 1 ||
            p[i].price < 0) {
            printf("Invalid price.\n");
            return 1;
        }

        totalValue += p[i].quantity * p[i].price;

        if (p[i].quantity > p[maxQtyIndex].quantity)
            maxQtyIndex = i;

        if (p[i].price > p[maxPriceIndex].price)
            maxPriceIndex = i;
    }

    /* ---------- OUTPUT ---------- */
    printf("\n===================\n");
    printf("INVENTORY SUMMARY\n");
    printf("===================\n");

    printf("Total Inventory Value : Rupees %.2f\n", totalValue);

    printf("\nProduct with HIGHEST QUANTITY:\n");
    printf("Quantity : %d\n", p[maxQtyIndex].quantity);
    printf("Name     : %s\n", p[maxQtyIndex].name);
    printf("Price    : %.2f\n", p[maxQtyIndex].price);
    printf("ID       : %d\n", p[maxQtyIndex].id);

    printf("\nProduct with HIGHEST PRICE:\n");
    printf("Price    : %.2f\n", p[maxPriceIndex].price);
    printf("Name     : %s\n", p[maxPriceIndex].name);
    printf("Quantity : %d\n", p[maxPriceIndex].quantity);
    printf("ID       : %d\n", p[maxPriceIndex].id );

    return 0;
}
