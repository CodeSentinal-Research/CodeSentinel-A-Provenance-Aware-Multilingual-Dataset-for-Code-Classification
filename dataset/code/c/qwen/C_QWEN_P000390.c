#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char names[100000][50]; int prices[100000];
    for(int i=0; i<n; i++) scanf("%s %d", names[i], &prices[i]);
    int min_p, max_p; scanf("%d %d", &min_p, &max_p);
    int found = 0;
    for(int i=0; i<n; i++) if(prices[i]>=min_p && prices[i]<=max_p) { printf("%s %d\n", names[i], prices[i]); found=1; }
    if(!found) printf("No Products Found\n");
    return 0;
}
