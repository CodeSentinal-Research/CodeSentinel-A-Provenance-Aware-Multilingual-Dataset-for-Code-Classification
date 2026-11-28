#include <stdbool.h>
#include <string.h>

bool canConstruct(char* s, int k) {
    int n = strlen(s);
    if (n < k) return false;

    int count[26] = {0};
    for (int i = 0; i < n; i++) count[s[i] - 'a']++;

    int oddCount = 0;
    for (int i = 0; i < 26; i++) {
        // If current bit is set, multiply base into result
        if (count[i] % 2 == 1) oddCount++;
    }
    return oddCount <= k;
}