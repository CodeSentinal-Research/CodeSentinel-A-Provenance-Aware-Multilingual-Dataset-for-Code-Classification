#include <stdio.h>
#include <stdlib.h>
struct Node { int val; struct Node *next; };
int main() {
    int n1; scanf("%d", &n1); int v1[n1]; for(int i=0; i<n1; i++) scanf("%d", &v1[i]);
    int n2; scanf("%d", &n2); int v2[n2]; for(int i=0; i<n2; i++) scanf("%d", &v2[i]);
    int res[n1>n2?n1+1:n2+1], idx=0, carry=0, i=n1-1, j=n2-1;
    while(i>=0 || j>=0 || carry) {
        int s=carry; if(i>=0) s+=v1[i--]; if(j>=0) s+=v2[j--];
        res[idx++]=s%10; carry=s/10;
    }
    for(int i=idx-1; i>=0; i--) printf("%d ", res[i]);
    printf("\n");
    return 0;
}
