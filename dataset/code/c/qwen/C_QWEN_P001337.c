#include <stdio.h>

int main() {
    int l, h;
    scanf("%d%d", &l, &h);
    for (int len = 1; len <= 9; len++) {
        for (int s = 1; s <= 9 - len; s++) {
            int num = 0;
            for (int i = 0; i < len; i++) num = num * 10 + (s + i);
            if (num >= l && num <= h) printf("%d ", num);
        }
    }
    printf("\n");
    return 0;
}
