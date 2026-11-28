#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int queue[n], front=0, rear=0, temp[n];
    for(int i=0; i<n; i++) { scanf("%d", &queue[i]); rear++; }
    int half=n/2;
    for(int i=0; i<half; i++) temp[i]=queue[front++];
    int idx=0;
    for(int i=0; i<half; i++) { queue[rear++]=temp[i]; queue[rear++]=queue[front++]; }
    for(int i=front; i<rear; i++) printf("%d%c", queue[i], i==rear-1?'\n':' ');
    return 0;
}
