#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char products[100000][50]; int prices[100000];
    for(int i=0; i<n; i++) scanf("%s %d", products[i], &prices[i]);
    int min_price; scanf("%d", &min_price);
    int found = 0;
    for(int i=0; i<n; i++) if(prices[i] >= min_price) { printf("%s %d\n", products[i], prices[i]); found=1; }
    if(!found) printf("No Products Found\n");
    return 0;
}
