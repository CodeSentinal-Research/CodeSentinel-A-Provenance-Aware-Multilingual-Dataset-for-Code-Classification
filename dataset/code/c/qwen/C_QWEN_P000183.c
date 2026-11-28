#include <stdio.h>
int main() {
    int n, k; scanf("%d %d", &n, &k);
    int arr[n], count[2000001] = {0}, distinct = 0;
    for(int i=0; i<k; i++) { if(count[arr[i]+1000000]++ == 0) distinct++; }
    printf("%d", distinct);
    for(int i=k; i<n; i++) {
        if(--count[arr[i-k]+1000000] == 0) distinct--;
        if(count[arr[i]+1000000]++ == 0) distinct++;
        printf(" %d", distinct);
    }
    printf("\n");
    return 0;
}
