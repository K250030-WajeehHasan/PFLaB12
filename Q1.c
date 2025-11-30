#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, indexMin = 0;
    int *stock;
    int total = 0;

    printf("Enter number of book categories: ");
    scanf("%d", &n);

    stock = (int*) malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        printf("Enter stock for category %d: ", i);
        scanf("%d", &stock[i]);
        total += stock[i];
    }

    for (i = 1; i < n; i++) {
        if (stock[i] < stock[indexMin]) {
            indexMin = i;
        }
    }

    printf("\nTotal stock = %d\n", total);
    printf("Average stock = %.2f\n", (float)total / n);
    printf("Category with lowest stock = %d\n", indexMin);

    int updateIndex, newValue;
    printf("\nEnter category index to update: ");
    scanf("%d", &updateIndex);
    printf("Enter new stock value: ");
    scanf("%d", &newValue);

    stock[updateIndex] = newValue;

    printf("\nUpdated stock values:\n");
    for (i = 0; i < n; i++) {
        printf("Category %d = %d\n", i, stock[i]);
    }

    free(stock);
    return 0;
}