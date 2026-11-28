#include <stdio.h>

int main() {
    char line[100];
    for (int i = 0; i < 10; i++) {
        if (scanf("%s", line) == 1) {
            printf("%s\n", line);
        }
    }
    return 0;
}