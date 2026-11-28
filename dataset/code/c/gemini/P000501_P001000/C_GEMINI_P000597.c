#include <stdio.h>
#include <string.h>
int main() {
    char token[32];
    int first = 1;
    while (scanf("%31s", token) == 1) {
        if (strcmp(token, "null") != 0 && strcmp(token, "#") != 0 && strcmp(token, "N") != 0) {
            if (!first) printf(" ");
            printf("%s", token);
            first = 0;
        }
    }
    printf("\n");
    return 0;
}