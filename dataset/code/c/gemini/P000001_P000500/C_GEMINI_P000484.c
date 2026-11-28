#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_N 10005
char s[MAX_N];
char str_stack[100][MAX_N];
int num_stack[100];
int main() {
    if (scanf("%10004s", s) == 1) {
        int top = -1;
        char curr[MAX_N] = "";
        int num = 0;
        for (int i = 0; s[i]; i++) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            } else if (s[i] == '[') {
                top++;
                num_stack[top] = num;
                strcpy(str_stack[top], curr);
                curr[0] = '\0';
                num = 0;
            } else if (s[i] == ']') {
                int k = num_stack[top];
                char temp[MAX_N];
                strcpy(temp, str_stack[top]);
                top--;
                for (int j = 0; j < k; j++) strcat(temp, curr);
                strcpy(curr, temp);
            } else {
                int len = strlen(curr);
                curr[len] = s[i];
                curr[len + 1] = '\0';
            }
        }
        printf("%s\n", curr);
    }
    return 0;
}