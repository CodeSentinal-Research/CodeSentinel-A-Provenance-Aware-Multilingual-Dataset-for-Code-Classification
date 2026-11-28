#include <stdio.h>
int main() {
    int size, q; scanf("%d %d", &size, &q);
    int queue[100001], front=0, rear=0;
    long long sum=0;
    for(int i=0; i<q; i++) {
        int val; scanf("%d", &val);
        queue[rear++]=val; sum+=val;
        if(rear-front>size) { sum-=queue[front++]; }
        printf("%.5f\n", (double)sum/(rear-front));
    }
    return 0;
}
