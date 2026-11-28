#include <stdio.h>
int main() {
    long long n; scanf("%lld", &n);
    int count[10] = {0};
    if(n == 0) count[0] = 1;
    while(n > 0) { count[n % 10]++; n /= 10; }
    for(int i=0; i<10; i++) printf("%d%c", count[i], i==9?'\n':' ');
    return 0;
}
