#include <stdio.h>
int main() {
    int m; scanf("%d", &m);
    int target[101];
    for(int i=0; i<m; i++) scanf("%d", &target[i]);
    int n; scanf("%d", &n);
    int first=1;
    int curr=1, idx=0;
    while(idx<m) {
        if(curr==target[idx]) {
            if(!first) printf(" "); printf("Push"); first=0;
            idx++;
        } else {
            if(!first) printf(" "); printf("Push"); first=0;
            if(!first) printf(" "); printf("Pop");
        }
        curr++;
    }
    printf("\n");
    return 0;
}
