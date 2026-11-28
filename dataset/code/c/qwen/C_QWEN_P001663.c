#include <stdio.h>

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int last = -1;
    for(int i=0; i<n; i++) if(arr[i] != -1) last = i;
    int ok = 1;
    for(int i=0; i<=last; i++) if(arr[i] == -1) { ok = 0; break; }
    printf("%s\n", ok ? "YES" : "NO");
    return 0;
}
