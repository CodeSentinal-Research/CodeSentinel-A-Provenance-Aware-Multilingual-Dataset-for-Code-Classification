#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int group_size[37] = {0};
    for (int i = 1; i <= n; i++) {
        int sum = 0, temp = i;
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }
        group_size[sum]++;
    }
    
    int max_size = 0;
    for (int i = 1; i <= 36; i++) {
        if (group_size[i] > max_size) max_size = group_size[i];
    }
    
    int count = 0;
    for (int i = 1; i <= 36; i++) {
        if (group_size[i] == max_size) count++;
    }
    printf("%d\n", count);
    return 0;
}
