#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int nums[n], stack[n], top=-1;
    for(int i=0; i<n; i++) scanf("%d", &nums[i]);
    int res[n];
    for(int i=n-1; i>=0; i--) {
        while(top>=0 && nums[stack[top]]<=nums[i]) top--;
        res[i] = top>=0 ? nums[stack[top]] : -1;
        stack[++top]=i;
    }
    int first=1;
    for(int i=0; i<n; i++) if(res[i]!=-1) { if(!first) printf(" "); printf("%d", nums[i]); first=0; }
    printf("\n");
    return 0;
}
