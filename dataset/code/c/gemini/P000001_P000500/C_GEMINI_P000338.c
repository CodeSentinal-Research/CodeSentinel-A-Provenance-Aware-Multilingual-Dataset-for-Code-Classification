#include <stdio.h>
#include <string.h>

int main() {
    char line1[1005], line2[1005];
    if (fgets(line1, sizeof(line1), stdin) && fgets(line2, sizeof(line2), stdin)) {
        char s1[1005] = {0}, s2[1005] = {0};
        char* token = strtok(line1, " \t\r\n");
        while (token) {
            strcat(s1, token);
            token = strtok(NULL, " \t\r\n");
        }
        token = strtok(line2, " \t\r\n");
        while (token) {
            strcat(s2, token);
            token = strtok(NULL, " \t\r\n");
        }
        printf("%s\n", strcmp(s1, s2) == 0 ? "Yes" : "No");
    }
    return 0;
}