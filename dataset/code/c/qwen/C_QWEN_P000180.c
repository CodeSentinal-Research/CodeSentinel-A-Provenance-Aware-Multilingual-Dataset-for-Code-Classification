#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n], count[2000001] = {0};
    for(int i=0; i<n; i++) { scanf("%d", &arr[i]); count[arr[i]+1000000]++; }
    int first = 1;
    for(int i=0; i<n; i++) {
        if(count[arr[i]+1000000] > n/3) {
            if(!first) printf(" ");
            printf("%d", arr[i]);
            count[arr[i]+1000000] = 0;
            first = 0;
        }
    }
    printf("\n");
    return 0;
}
