#include <stdio.h>
#include <math.h>

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int h = log2(n + 1);
    int expected = (1 << h) - 1;
    printf("%s\n", n == expected ? "YES" : "NO");
    return 0;
}
