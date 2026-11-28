#include <stdio.h>
#include <string.h>

#define MAX_PARTS 500
#define MAX_LEN 1005

char stack[MAX_PARTS][MAX_LEN];
int top = 0;

int main() {
    char path[MAX_LEN];
    if (scanf("%1004s", path) == 1) {
        char* token = strtok(path, "/");
        while (token != NULL) {
            if (strcmp(token, ".") == 0 || strlen(token) == 0) {
                // skip
            } else if (strcmp(token, "..") == 0) {
                if (top > 0) top--;
            } else {
                strcpy(stack[top++], token);
            }
            token = strtok(NULL, "/");
        }
        if (top == 0) {
            printf("/\n");
        } else {
            for (int i = 0; i < top; i++) {
                printf("/%s", stack[i]);
            }
            printf("\n");
        }
    }
    return 0;
}