#include <stdio.h>
#include <stdbool.h>
int main() {
    int r, c, target;
    if (scanf("%d %d %d", &r, &c, &target) == 3) {
        bool found = false;
        for (int i = 0; i < r * c; i++) {
            int v;
            scanf("%d", &v);
            if (v == target) found = true;
        }
        printf("%s\n", found ? "Found" : "Not Found");
    }
    return 0;
}