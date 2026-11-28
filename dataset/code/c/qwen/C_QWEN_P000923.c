#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    if(n == 0) { printf("10\n"); return 0; }
    int count = 10; int avail = 9; int prod = 9;
    for(int i=1; i<n; i++) { prod *= avail; count += prod; avail--; }
    printf("%d\n", count);
    return 0;
}
