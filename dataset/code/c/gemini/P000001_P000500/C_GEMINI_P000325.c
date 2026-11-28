#include <stdio.h>
#include <string.h>

int main() {
    char a[105], b[105];
    if (scanf("%104s %104s", a, b) == 2) {
        if (strcmp(a, b) == 0) {
            printf("-1\n");
        } else {
            int la = strlen(a), lb = strlen(b);
            printf("%d\n", la > lb ? la : lb);
        }
    }
    return 0;
}