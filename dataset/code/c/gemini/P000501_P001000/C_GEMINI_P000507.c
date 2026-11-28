#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_N 100005
char s[MAX_N];
int main() {
    if (scanf("%100004s", s) == 1) {
        int slots = 1;
        bool valid = true;
        char* token = strtok(s, ",");
        while (token != NULL) {
            slots--;
            if (slots < 0) { valid = false; break; }
            if (strcmp(token, "#") != 0) slots += 2;
            token = strtok(NULL, ",");
        }
        if (slots != 0) valid = false;
        printf("%s\n", valid ? "true" : "false");
    }
    return 0;
}