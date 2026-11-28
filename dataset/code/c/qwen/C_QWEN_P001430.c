#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n], b[n], res[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    
    int seen_a[1001] = {0}, seen_b[1001] = {0};
    int common = 0;
    for (int i = 0; i < n; i++) {
        seen_a[a[i]] = 1;
        seen_b[b[i]] = 1;
        if (seen_a[b[i]] && seen_b[a[i]]) common++; // simplified logic
        // Correct logic:
        int c = 0;
        for (int j = 0; j <= i; j++) {
            if (seen_a[b[j]]) c++; // This is getting complex, let's use simple array
        }
    }
    
    // Simpler approach
    int count_a[1001] = {0}, count_b[1001] = {0};
    for (int i = 0; i < n; i++) {
        count_a[a[i]]++;
        count_b[b[i]]++;
        int common_count = 0;
        for (int j = 1; j <= 1000; j++) {
            if (count_a[j] > 0 && count_b[j] > 0) common_count++;
        }
        res[i] = common_count;
    }
    
    for (int i = 0; i < n; i++) printf("%d ", res[i]);
    printf("\n");
    return 0;
}
