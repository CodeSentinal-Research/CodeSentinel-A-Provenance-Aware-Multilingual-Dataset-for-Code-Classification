#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n], min_price = 2000000000, max_profit = 0;
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
        if(arr[i] < min_price) min_price = arr[i];
        else if(arr[i] - min_price > max_profit) max_profit = arr[i] - min_price;
    }
    printf("%d\n", max_profit);
    return 0;
}
