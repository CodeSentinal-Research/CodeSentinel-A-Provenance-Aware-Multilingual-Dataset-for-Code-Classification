#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    char res[10]; int idx = 0;
    while(n > 0) {
        n--;
        res[idx++] = 'A' + (n % 26);
        n /= 26;
    }
    for(int i=idx-1; i>=0; i--) printf("%c", res[i]);
    printf("\n");
    return 0;
}
