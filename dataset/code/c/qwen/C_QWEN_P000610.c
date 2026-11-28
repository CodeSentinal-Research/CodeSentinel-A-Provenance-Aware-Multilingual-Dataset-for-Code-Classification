#include <stdio.h>
int main() {
    int n; scanf("%d", &n); int vals[n]; for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    int res[n], idx=0;
    for(int i=1; i<n-1; ) {
        int sum=0;
        while(i<n-1 && vals[i]!=0) sum+=vals[i++];
        if(vals[i]==0) { res[idx++]=sum; i++; }
    }
    for(int i=0; i<idx; i++) printf("%d ", res[i]);
    printf("\n");
    return 0;
}
