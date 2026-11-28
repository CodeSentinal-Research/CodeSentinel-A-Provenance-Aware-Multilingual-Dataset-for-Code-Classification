#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n], first[100001]={0}, last[100001]={0}, count[100001]={0}, max_freq=0;
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
        if(!first[arr[i]]) first[arr[i]] = i+1;
        last[arr[i]] = i+1;
        count[arr[i]]++;
        if(count[arr[i]] > max_freq) max_freq = count[arr[i]];
    }
    int min_len = n;
    for(int i=1; i<=100000; i++) {
        if(count[i] == max_freq) {
            int len = last[i] - first[i] + 1;
            if(len < min_len) min_len = len;
        }
    }
    printf("%d\n", min_len);
    return 0;
}
