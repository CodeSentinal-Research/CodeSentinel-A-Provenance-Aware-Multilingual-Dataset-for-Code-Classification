#include <stdio.h>

int n, k;
int cnt = 0;
char res[15];

void gen(int i, char last) {
    if (i == n) {
        cnt++;
        if (cnt == k) {
            res[i] = '\0';
            printf("%s\n", res);
        }
        return;
    }
    char c[] = {'a', 'b', 'c'};
    for (int j = 0; j < 3; j++) {
        if (c[j] != last) {
            res[i] = c[j];
            gen(i + 1, c[j]);
            if (cnt == k) return;
        }
    }
}

int main() {
    scanf("%d%d", &n, &k);
    gen(0, 0);
    if (cnt < k) printf("\n");
    return 0;
}
