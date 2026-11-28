#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int vals[n];
    for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    int j=0;
    for(int i=0; i<n; i++) {
        if((i==0 || vals[i]!=vals[i-1]) && (i==n-1 || vals[i]!=vals[i+1])) vals[j++]=vals[i];
    }
    for(int i=0; i<j; i++) printf("%d%c", vals[i], i==j-1?'\n':' ');
    printf("\n");
    return 0;
}
