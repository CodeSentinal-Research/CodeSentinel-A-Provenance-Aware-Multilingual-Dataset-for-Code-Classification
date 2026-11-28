#include <stdio.h>
int main() {
    int n, x; scanf("%d", &n);
    int arr[100000];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    scanf("%d", &x);
    for(int i=0; i<n; i++) if(arr[i]==x) { printf("Present\n"); return 0; }
    printf("Missing\n");
    return 0;
}
