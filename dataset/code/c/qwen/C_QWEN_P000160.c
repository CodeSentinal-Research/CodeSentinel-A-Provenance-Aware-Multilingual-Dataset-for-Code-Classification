#include <stdio.h>
int main() {
    int n, target; scanf("%d %d", &n, &target);
    int arr[n], found = 0;
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    for(int i=0; i<n && !found; i++)
        for(int j=i+1; j<n && !found; j++)
            if(arr[i] + arr[j] == target) found = 1;
    printf("%s\n", found ? "Yes" : "No");
    return 0;
}
