#include <stdio.h>
#include <string.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        char line[1005];
        getchar();
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (fgets(line, sizeof(line), stdin)) {
                line[strcspn(line, "\r\n")] = 0;
                if (strlen(line) == 0 && idx == -1) idx = i;
            }
        }
        printf("%d\n", idx);
    }
    return 0;
}