#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char orders[100000][20]; int days[100000];
    for(int i=0; i<n; i++) scanf("%s %d", orders[i], &days[i]);
    int threshold; scanf("%d", &threshold);
    int found = 0;
    for(int i=0; i<n; i++) if(days[i] > threshold) { printf("%s %d\n", orders[i], days[i]); found=1; }
    if(!found) printf("No Pending Orders\n");
    return 0;
}
