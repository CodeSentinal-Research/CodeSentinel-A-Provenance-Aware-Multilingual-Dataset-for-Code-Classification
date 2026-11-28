#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char flights[100000][20]; int prices[100000]; int avail[100000];
    for(int i=0; i<n; i++) scanf("%s %d %d", flights[i], &prices[i], &avail[i]);
    int budget; scanf("%d", &budget);
    int found = 0;
    for(int i=0; i<n; i++) if(avail[i] && prices[i] <= budget) { printf("%s %d\n", flights[i], prices[i]); found=1; }
    if(!found) printf("No Flights Found\n");
    return 0;
}
