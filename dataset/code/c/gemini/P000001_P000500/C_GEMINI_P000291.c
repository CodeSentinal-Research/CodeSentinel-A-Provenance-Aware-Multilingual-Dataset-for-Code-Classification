#include <string.h>
#include <stdbool.h>

bool checkInclusion(char* s1, char* s2) {
    int n1 = strlen(s1), n2 = strlen(s2);
    if (n1 > n2) return false;

    int c1[26] = {0}, c2[26] = {0};
    for (int i = 0; i < n1; i++) c1[s1[i] - 'a']++;

    for (int i = 0; i < n2; i++) {
        c2[s2[i] - 'a']++;
        if (i >= n1) c2[s2[i - n1] - 'a']--;

        bool match = true;
        for (int k = 0; k < 26; k++) {
            if (c1[k] != c2[k]) { match = false; break; }
        }
        if (match) return true;
    }
    return false;
}