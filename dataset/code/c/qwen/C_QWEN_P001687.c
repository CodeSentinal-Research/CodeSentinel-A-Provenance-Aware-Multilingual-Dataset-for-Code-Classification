#include <stdio.h>

int flipEquiv(int *t1, int *t2, int i, int j, int n1, int n2) {
    if(i >= n1 && j >= n2) return 1;
    if(i >= n1 || j >= n2) return 0;
    if(t1[i] != t2[j]) return 0;
    return (flipEquiv(t1, t2, 2*i+1, 2*j+1, n1, n2) && flipEquiv(t1, t2, 2*i+2, 2*j+2, n1, n2)) ||
           (flipEquiv(t1, t2, 2*i+1, 2*j+2, n1, n2) && flipEquiv(t1, t2, 2*i+2, 2*j+1, n1, n2));
}

int main() {
    int n1, n2; scanf("%d", &n1);
    int t1[n1]; for(int i=0; i<n1; i++) scanf("%d", &t1[i]);
    scanf("%d", &n2);
    int t2[n2]; for(int i=0; i<n2; i++) scanf("%d", &t2[i]);
    printf("%s\n", flipEquiv(t1, t2, 0, 0, n1, n2) ? "YES" : "NO");
    return 0;
}
