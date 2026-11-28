#include <stdio.h>
int main() {
    int n, m; scanf("%d %d", &n, &m);
    int a[n], b[m];
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int i=0; i<m; i++) scanf("%d", &b[i]);
    int res[n+m>n?n+m:n], idx=0, carry=0, i=0, j=0;
    while(i<n || j<m || carry) {
        int sum=carry;
        if(i<n) sum+=a[i++];
        if(j<m) sum+=b[j++];
        res[idx++]=sum%10; carry=sum/10;
    }
    for(int i=idx-1; i>=0; i--) printf("%d", res[i]);
    printf("\n");
    return 0;
}
