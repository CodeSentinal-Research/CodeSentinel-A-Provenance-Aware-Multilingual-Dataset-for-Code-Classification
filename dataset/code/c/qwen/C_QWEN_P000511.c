#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int nums[n], res[n], stack[n], top=-1;
    for(int i=0; i<n; i++) scanf("%d", &nums[i]);
    for(int i=2*n-1; i>=0; i--) {
        while(top>=0 && nums[stack[top]]<=nums[i%n]) top--;
        res[i%n] = top>=0 ? nums[stack[top]] : -1;
        stack[++top]=i%n;
    }
    for(int i=0; i<n; i++) printf("%d%c", res[i], i==n-1?'\n':' ');
    return 0;
}
