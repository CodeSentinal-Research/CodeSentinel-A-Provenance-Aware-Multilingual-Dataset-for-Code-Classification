#include <stdio.h>
int main() {
    int n, k; scanf("%d%d", &n, &k);
    char res[100001];
    int rem = k - n;
    for(int i=n-1; i>=0; i--) {
        int add = rem > 25 ? 25 : rem;
        res[i] = 'a' + add;
        rem -= add;
    }
    res[n] = '\0';
    printf("%s\n", res);
    return 0;
}
