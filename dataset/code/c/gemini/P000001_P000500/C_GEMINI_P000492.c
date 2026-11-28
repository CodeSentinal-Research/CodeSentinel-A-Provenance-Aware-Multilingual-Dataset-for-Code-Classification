#include <stdio.h>
#include <string.h>
#define MAX_N 10005
char path[MAX_N];
char st[1000][128];
int main() {
    if (scanf("%10004s", path) == 1) {
        int top = -1;
        char* token = strtok(path, "/");
        while (token != NULL) {
            if (strcmp(token, ".") == 0 || strlen(token) == 0) {
            } else if (strcmp(token, "..") == 0) {
                if (top >= 0) top--;
            } else {
                strcpy(st[++top], token);
            }
            token = strtok(NULL, "/");
        }
        if (top == -1) {
            printf("/\n");
        } else {
            for (int i = 0; i <= top; i++) {
                printf("/%s", st[i]);
            }
            printf("\n");
        }
    }
    return 0;
}