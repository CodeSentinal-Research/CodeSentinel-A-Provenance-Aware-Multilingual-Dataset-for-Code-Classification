#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char words[n][101];
    for (int i = 0; i < n; i++) scanf("%s", words[i]);
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int mask_i = 0, mask_j = 0;
            for (int k = 0; words[i][k]; k++) mask_i |= (1 << (words[i][k] - 'a'));
            for (int k = 0; words[j][k]; k++) mask_j |= (1 << (words[j][k] - 'a'));
            if (mask_i == mask_j) count++;
        }
    }
    printf("%d\n", count);
    return 0;
}
