#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    int is_prime[n+1]; memset(is_prime, 1, sizeof(is_prime));
    is_prime[0] = is_prime[1] = 0;
    for(int i=2; i*i<=n; i++) if(is_prime[i]) for(int j=i*i; j<=n; j+=i) is_prime[j] = 0;
    int count = 0;
    for(int i=2; i<=n; i++) if(is_prime[i]) count++;
    printf("%d\n", count);
    return 0;
}
