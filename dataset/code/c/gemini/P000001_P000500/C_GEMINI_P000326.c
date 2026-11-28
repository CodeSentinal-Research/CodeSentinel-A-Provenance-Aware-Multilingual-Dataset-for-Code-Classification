#include <stdio.h>

int main() {
    char word[1005];
    int count = 0;
    while (scanf("%1004s", word) == 1) {
        count++;
    }
    printf("%d\n", count);
    return 0;
}