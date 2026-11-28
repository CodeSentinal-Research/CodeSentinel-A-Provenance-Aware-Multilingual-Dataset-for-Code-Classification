#include <stdio.h>
int main() {
    int n; scanf("%d", &n); int vals[n]; for(int i=0; i<n; i++) scanf("%d", &vals[i]);
    int res[n], idx=0;
    for(int i=0; i<n; ) {
        int sum=0, j=i;
        while(j<n && sum+vals[j]!=0) sum+=vals[j++];
        if(j<n && sum+vals[j]==0 && j>i) { i=j+1; }
        else { res[idx++]=vals[i]; i++; }
    }
    for(int i=0; i<idx; i++) printf("%d ", res[i]);
    printf("\n");
    return 0;
}
