#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, i;
    char **feedback;
    int totalChars = 0;
    int longestIndex = 0;

    printf("Enter number of feedback entries: ");
    scanf("%d", &n);

    feedback = (char**) malloc(n * sizeof(char*));

    for (i = 0; i < n; i++) {
        char temp[200];
        printf("Enter feedback %d: ", i + 1);
        scanf(" %[^\n]", temp);

        feedback[i] = (char*) malloc((strlen(temp) + 1) * sizeof(char));
        strcpy(feedback[i], temp);

        totalChars += strlen(temp);

        if (strlen(feedback[i]) > strlen(feedback[longestIndex])) {
            longestIndex = i;
        }
    }

    printf("\nAll feedback:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", feedback[i]);
    }

    printf("\nTotal characters = %d\n", totalChars);
    printf("Longest feedback = %s\n", feedback[longestIndex]);

    for (i = 0; i < n; i++) {
        free(feedback[i]);
    }
    free(feedback);

    return 0;
}