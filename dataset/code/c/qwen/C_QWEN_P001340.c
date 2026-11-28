#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int queue[100001], front = 0, rear = 0;
    queue[rear++] = 1;
    printf("1");
    while (rear <= n) {
        int curr = queue[front++];
        printf(" %d", curr * 10);
        if (rear < n) queue[rear++] = curr * 10;
        printf(" %d", curr * 10 + 1);
        if (rear < n) queue[rear++] = curr * 10 + 1;
    }
    printf("\n");
    return 0;
}
