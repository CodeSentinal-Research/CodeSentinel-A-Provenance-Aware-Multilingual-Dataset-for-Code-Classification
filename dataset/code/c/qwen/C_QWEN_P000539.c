#include <stdio.h>
#include <string.h>
int main() {
    int n, q; scanf("%d", &n);
    int nums[n], count[100000001]={0}, queue[n], front=0, rear=0;
    for(int i=0; i<n; i++) { scanf("%d", &nums[i]); count[nums[i]]++; if(count[nums[i]]==1) queue[rear++]=nums[i]; }
    scanf("%d", &q);
    while(q--) {
        char op[20]; scanf("%s", op);
        if(strcmp(op, "add")==0) { int x; scanf("%d", &x); count[x]++; if(count[x]==1) queue[rear++]=x; }
        else {
            int found=-1;
            while(front<rear) { if(count[queue[front]]==1) { found=queue[front]; break; } front++; }
            printf("%d\n", found);
        }
    }
    return 0;
}
