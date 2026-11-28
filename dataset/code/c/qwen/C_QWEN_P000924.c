#include <stdio.h>
int main() {
    long long n; scanf("%lld", &n);
    if(n == 0) { printf("0\n"); return 0; }
    char bin[65]; int idx = 0;
    while(n > 0) { bin[idx++] = (n % 2) + '0'; n /= 2; }
    for(int i=idx-1; i>=0; i--) printf("%c", bin[i]);
    printf("\n");
    return 0;
}
