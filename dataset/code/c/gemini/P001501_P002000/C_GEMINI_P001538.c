#include <stdbool.h>
#include <string.h>

bool checkInclusion(char* s1, char* s2) {
    int n1 = strlen(s1), n2 = strlen(s2);
    if (n1 > n2) return false;

    int c1[26] = {0}, c2[26] = {0};
    for (int i = 0; i < n1; i++) {
        c1[s1[i] - 'a']++;
        c2[s2[i] - 'a']++;
    }

    bool match = true;
    for (int j = 0; j < 26; j++) {
        if (c1[j] != c2[j]) { match = false; break; }
    }
    if (match) return true;

    for (int i = n1; i < n2; i++) {
        c2[s2[i] - 'a']++;
        c2[s2[i - n1] - 'a']--;
        match = true;
        for (int j = 0; j < 26; j++) {
            if (c1[j] != c2[j]) { match = false; break; }
        }
        if (match) return true;
    }
    return false;
}