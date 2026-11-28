#include <stdio.h>

int identical(int *a, int *b, int i, int n) {
    if(i >= n) return 1;
    if(a[i] != b[i]) return 0;
    return identical(a, b, 2*i+1, n) && identical(a, b, 2*i+2, n);
}

int main() {
    int n; scanf("%d", &n);
    int a[n], b[n];
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int i=0; i<n; i++) scanf("%d", &b[i]);
    printf("%s\n", identical(a, b, 0, n) ? "YES" : "NO");
    return 0;
}
