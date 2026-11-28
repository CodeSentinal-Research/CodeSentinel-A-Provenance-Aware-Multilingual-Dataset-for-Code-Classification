#include <stdio.h>
#include <string.h>
#define MAX_N 10005
char records[MAX_N][256];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        getchar();
        for (int i = 0; i < n; i++) {
            fgets(records[i], sizeof(records[i]), stdin);
            records[i][strcspn(records[i], "\r\n")] = 0;
        }
        char keyword[64];
        if (fgets(keyword, sizeof(keyword), stdin)) {
            keyword[strcspn(keyword, "\r\n")] = 0;
            for (int i = 0; i < n; i++) {
                if (strstr(records[i], keyword)) printf("%s\n", records[i]);
            }
        }
    }
    return 0;
}