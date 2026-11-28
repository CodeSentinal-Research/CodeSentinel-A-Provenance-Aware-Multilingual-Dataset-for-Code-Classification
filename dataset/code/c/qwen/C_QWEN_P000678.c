#include <stdio.h>
int main() {
    int n, k; scanf("%d %d", &n, &k);
    int pos=0;
    for(int i=2; i<=n; i++) pos = (pos+k)%i;
    printf("%d\n", pos+1);
    return 0;
}
