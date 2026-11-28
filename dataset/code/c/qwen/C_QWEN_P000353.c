#include <stdio.h>
int main() {
    int n, x; scanf("%d", &n);
    int arr[100000];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    scanf("%d", &x);
    int idx = -1;
    for(int i=0; i<n; i++) if(arr[i]==x) idx = i;
    printf("%d\n", idx);
    return 0;
}
