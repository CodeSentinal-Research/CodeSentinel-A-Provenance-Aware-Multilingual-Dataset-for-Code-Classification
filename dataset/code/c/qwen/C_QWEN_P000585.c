#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int vals[n];
    for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    int mid=(n-1)/2;
    for(int i=0; i<=mid; i++) {
        printf("%d ", vals[i]);
        if(n-1-i>mid) printf("%d ", vals[n-1-i]);
    }
    printf("\n");
    return 0;
}
