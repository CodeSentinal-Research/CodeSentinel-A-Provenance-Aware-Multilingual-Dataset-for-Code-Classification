#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int queue[100001], front=0, rear=0;
    for(int i=0; i<n; i++) {
        int t; scanf("%d", &t);
        queue[rear++]=t;
        while(front<rear && queue[front]<t-3000) front++;
        printf("%d\n", rear-front);
    }
    return 0;
}
