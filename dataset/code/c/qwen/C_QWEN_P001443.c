#include <stdio.h>
#include <string.h>

int main() {
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    char words1[n1][27], words2[n2][27];
    for (int i = 0; i < n1; i++) scanf("%s", words1[i]);
    for (int i = 0; i < n2; i++) scanf("%s", words2[i]);
    
    int mask1[100001] = {0};
    for (int i = 0; i < n1; i++) {
        int m = 0;
        for (int j = 0; words1[i][j]; j++) m |= (1 << (words1[i][j] - 'a'));
        mask1[m] = 1;
    }
    
    int count = 0;
    for (int i = 0; i < n2; i++) {
        int m = 0;
        for (int j = 0; words2[i][j]; j++) m |= (1 << (words2[i][j] - 'a'));
        // Check if removing one char from m gives a mask in mask1
        for (int j = 0; j < 26; j++) {
            if (m & (1 << j)) {
                if (mask1[m ^ (1 << j)]) { count++; break; }
            }
        }
    }
    printf("%d\n", count);
    return 0;
}
