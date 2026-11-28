#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int nums[n], passes=0;
    for(int i=0; i<n; i++) scanf("%d", &nums[i]);
    int removed[n]; memset(removed, 0, sizeof(removed));
    int remaining=n;
    while(remaining>0) {
        int last=-1;
        for(int i=0; i<n; i++) {
            if(!removed[i]) {
                if(nums[i]>last) { removed[i]=1; remaining--; last=nums[i]; }
            }
        }
        passes++;
    }
    printf("%d\n", passes);
    return 0;
}
