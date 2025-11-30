#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int category(char c) {
    if (c >= 'A' && c <= 'Z') return 1;
    if (c >= 'a' && c <= 'z') return 2;
    if (c >= '0' && c <= '9') return 3;
    return 4;
}

int main() {
    int n, i, j;
    char *pattern;
    char **passwords;

    pattern = (char*) malloc(100 * sizeof(char));
    printf("Enter password pattern: ");
    scanf("%s", pattern);

    printf("Enter number of participants: ");
    scanf("%d", &n);

    passwords = (char**) malloc(n * sizeof(char*));

    int bestIndex = 0;
    int bestScore = -1;

    for (i = 0; i < n; i++) {
        char temp[100];
        printf("Enter password %d: ", i + 1);
        scanf("%s", temp);

        passwords[i] = (char*) malloc((strlen(temp)+1) * sizeof(char));
        strcpy(passwords[i], temp);

        int len = strlen(pattern);
        int score = 0;

        for (j = 0; j < len && j < strlen(temp); j++) {
            if (category(pattern[j]) == category(temp[j])) {
                score++;
            }
        }

        int percent = (score * 100) / len;
        printf("Similarity = %d%%\n", percent);

        if (percent > bestScore) {
            bestScore = percent;
            bestIndex = i;
        }
    }

    printf("\nPassword with highest similarity: %s (%d%%)\n",
           passwords[bestIndex], bestScore);

    free(pattern);
    for (i = 0; i < n; i++) {
        free(passwords[i]);
    }
    free(passwords);

    return 0;
}