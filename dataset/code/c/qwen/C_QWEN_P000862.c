#include <stdio.h>
int main() {
    int n; scanf("%d", &n); int a[n];
    int ones=0, twos=0;
    for(int i=0; i<n; i++) { scanf("%d", &a[i]); ones = (ones ^ a[i]) & ~twos; twos = (twos ^ a[i]) & ~ones; }
    printf("%d\n", ones);
    return 0;
}
