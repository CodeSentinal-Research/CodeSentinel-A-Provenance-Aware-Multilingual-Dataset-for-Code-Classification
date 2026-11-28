#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int longestWPI(int* hours, int hoursSize) {
    int* seen = (int*)malloc((2 * hoursSize + 1) * sizeof(int));
    for (int i = 0; i <= 2 * hoursSize; i++) seen[i] = -2;

    int score = 0, ans = 0;
    for (int i = 0; i < hoursSize; i++) {
        score += hours[i] > 8 ? 1 : -1;
        if (score > 0) {
            ans = i + 1;
        } else {
            if (seen[score + hoursSize] == -2) {
                seen[score + hoursSize] = i;
            }
            if (score - 1 + hoursSize >= 0 && seen[score - 1 + hoursSize] != -2) {
                ans = MAX(ans, i - seen[score - 1 + hoursSize]);
            }
        }
    }
    free(seen);
    return ans;
}