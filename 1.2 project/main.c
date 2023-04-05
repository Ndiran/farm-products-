#include <stdio.h>
#include <stdlib.h>

struct Order {
    int eggs;
    int milk;
    int cheese;
    float totalCost;
};

 void printOrder(struct Order order) {
    printf("\nOrder Details:\n");
    printf("Eggs: %d\n", order.eggs);
    printf("Milk: %d litres\n", order.milk);
    printf("Cheese: %d kg\n", order.cheese);
    printf("Total Cost: $%.2f\n", order.totalCost);
}

 int main() {
    int numOrders;
    struct Order *orders;
    FILE *file;
    char fileName[100];
    printf(" WELCOME TO WANYAWIRA'S HUB\n");
    printf("Enter the number of orders to process: ");
    scanf("%d", &numOrders);

    orders = (struct Order*) malloc(numOrders * sizeof(struct Order));

    for(int i = 0; i < numOrders; i++) {
        printf("\nOrder #%d:\n", i+1);

        printf("Enter the number of eggs: ");
        scanf("%d", &orders[i].eggs);

        printf("Enter the number of litres of milk: ");
        scanf("%d", &orders[i].milk);

        printf("Enter the number of kg of cheese: ");
        scanf("%d", &orders[i].cheese);

        orders[i].totalCost = orders[i].eggs * 0.20 + orders[i].milk * 0.90 + orders[i].cheese * 10.50;

        printOrder(orders[i]);
    }

    printf("\nEnter a file name to save the orders to: ");
    scanf("%s", fileName);


    file = fopen(fileName, "w");

    for(int i = 0; i < numOrders; i++) {
        fprintf(file, "%d %d %d %.2f\n", orders[i].eggs, orders[i].milk, orders[i].cheese, orders[i].totalCost);
    }

    fclose(file);

    free(orders);

      FILE*product;
product=fopen("product", "w");
fprintf(product,"%d" ,orders[1].eggs);
fprintf(product,"%d" ,orders[1].milk);
fprintf(product,"%d" ,orders[1].cheese);
fclose(product);

    return 0;

}
