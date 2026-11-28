#include <stdio.h>
int gcd(int a, int b) { while(b) { int t=b; b=a%b; a=t; } return a; }
int main() {
    int n; scanf("%d", &n); int vals[n]; for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    for(int i=0; i<n-1; i++) { printf("%d %d ", vals[i], gcd(vals[i], vals[i+1])); }
    printf("%d\n", vals[n-1]);
    return 0;
}
