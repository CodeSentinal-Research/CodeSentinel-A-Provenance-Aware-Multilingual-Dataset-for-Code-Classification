#include <stdio.h>

int main() {
    int n; scanf("%d", &n);
    long long sum = 0;
    int max_len = 0, start = -1;
    for(int i=0; i<n; i++) {
        int val; scanf("%d", &val);
        sum += val;
        if(sum < 0) {
            if(start == -1) start = i;
            if(i - start + 1 > max_len) max_len = i - start + 1;
        } else {
            start = -1;
        }
    }
    printf("%d\n", max_len);
    return 0;
}
