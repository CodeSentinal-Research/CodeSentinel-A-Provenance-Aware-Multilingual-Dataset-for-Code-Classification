#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int sum = 0, max_len = 0, map[200001];
    for(int i=0; i<=200000; i++) map[i] = -2;
    map[100000] = -1;
    for(int i=0; i<n; i++) {
        sum += arr[i] == 0 ? -1 : 1;
        int idx = sum + 100000;
        if(map[idx] != -2) {
            if(i - map[idx] > max_len) max_len = i - map[idx];
        } else map[idx] = i;
    }
    printf("%d\n", max_len);
    return 0;
}
