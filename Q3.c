#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int containsDigit(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            return 1;
        }
        i++;
    }
    return 0;
}

int main() {
    int n, i;
    char **usernames;

    printf("Enter number of usernames: ");
    scanf("%d", &n);

    usernames = (char**) malloc(n * sizeof(char*));

    for (i = 0; i < n; i++) {
        char temp[100];
        printf("Enter username %d: ", i + 1);
        scanf("%s", temp);

        usernames[i] = (char*) malloc((strlen(temp) + 1) * sizeof(char));
        strcpy(usernames[i], temp);
    }

    printf("\nValid usernames (alphabet only):\n");
    for (i = 0; i < n; i++) {
        if (!containsDigit(usernames[i])) {
            printf("%s\n", usernames[i]);
        }
    }

    for (i = 0; i < n; i++) {
        free(usernames[i]);
    }
    free(usernames);

    return 0;
}