#include <stdio.h>
int main() {
    int n, k; scanf("%d", &n);
    int tickets[n];
    for(int i=0; i<n; i++) scanf("%d", &tickets[i]);
    scanf("%d", &k);
    int time=0;
    while(tickets[k]>0) {
        for(int i=0; i<n; i++) {
            if(tickets[i]>0) { tickets[i]--; time++; if(i==k && tickets[k]==0) break; }
        }
    }
    printf("%d\n", time);
    return 0;
}
