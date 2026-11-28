#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n], dup = 0;
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    for(int i=0; i<n && !dup; i++)
        for(int j=i+1; j<n && !dup; j++)
            if(arr[i] == arr[j]) dup = 1;
    printf("%s\n", dup ? "Yes" : "No");
    return 0;
}
