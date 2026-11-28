#include <stdio.h>
int main() {
    int n1; scanf("%d", &n1);
    int a[n1]; for(int i=0; i<n1; i++) scanf("%d", &a[i]);
    int n2; scanf("%d", &n2);
    int b[n2]; for(int i=0; i<n2; i++) scanf("%d", &b[i]);
    int n = n1 + n2;
    int res[n];
    for(int i=0; i<n1; i++) res[i] = a[i];
    for(int i=0; i<n2; i++) res[n1+i] = b[i];
    for(int i=0; i<n; i++) printf("%d ", res[i]);
    printf("\n");
    return 0;
}
