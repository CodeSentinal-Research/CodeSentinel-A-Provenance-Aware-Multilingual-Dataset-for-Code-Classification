#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int nums[n], stack[n], top=-1;
    for(int i=0; i<n; i++) scanf("%d", &nums[i]);
    int left[n], right[n];
    for(int i=0; i<n; i++) left[i]=i;
    for(int i=0; i<n; i++) {
        while(top>=0 && nums[stack[top]]>nums[i]) { left[i]=left[stack[top]]; top--; }
        stack[++top]=i;
    }
    top=-1;
    for(int i=n-1; i>=0; i--) right[i]=i;
    for(int i=n-1; i>=0; i--) {
        while(top>=0 && nums[stack[top]]<nums[i]) { right[i]=right[stack[top]]; top--; }
        stack[++top]=i;
    }
    int start=0, end=n-1;
    for(int i=0; i<n; i++) if(left[i]!=i || right[i]!=i) { start=i; break; }
    for(int i=n-1; i>=0; i--) if(left[i]!=i || right[i]!=i) { end=i; break; }
    printf("%d\n", end-start+1);
    return 0;
}
