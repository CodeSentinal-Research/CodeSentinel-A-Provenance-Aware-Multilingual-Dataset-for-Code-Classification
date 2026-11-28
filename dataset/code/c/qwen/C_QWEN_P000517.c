#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int nums[n], stack[n], top=-1, max_w=0;
    for(int i=0; i<n; i++) scanf("%d", &nums[i]);
    for(int i=0; i<n; i++) {
        while(top>=0 && nums[stack[top]]<=nums[i]) {
            max_w = i-stack[top] > max_w ? i-stack[top] : max_w;
            top--;
        }
        stack[++top]=i;
    }
    printf("%d\n", max_w);
    return 0;
}
