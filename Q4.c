#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, maxIndex = 0;
    int *ratings;
    int total = 0;

    printf("Enter number of movie categories: ");
    scanf("%d", &n);

    ratings = (int*) malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        printf("Enter rating count for category %d: ", i);
        scanf("%d", &ratings[i]);
        total += ratings[i];
    }

    for (i = 1; i < n; i++) {
        if (ratings[i] > ratings[maxIndex]) {
            maxIndex = i;
        }
    }

    printf("\nTotal ratings = %d\n", total);
    printf("Average ratings = %.2f\n", (float)total / n);
    printf("Category with highest ratings = %d\n", maxIndex);

    int updateIndex, newRating;
    printf("\nEnter category index to update: ");
    scanf("%d", &updateIndex);

    printf("Enter new rating: ");
    scanf("%d", &newRating);

    ratings[updateIndex] = newRating;

    printf("\nUpdated ratings:\n");
    for (i = 0; i < n; i++) {
        printf("Category %d = %d\n", i, ratings[i]);
    }

    free(ratings);
    return 0;
}