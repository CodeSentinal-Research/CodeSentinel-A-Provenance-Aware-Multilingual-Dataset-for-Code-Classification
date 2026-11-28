#include <stdbool.h>
#include <string.h>

bool isScramble(char* s1, char* s2) {
    if (strcmp(s1, s2) == 0) return true;
    int len1 = strlen(s1), len2 = strlen(s2);
    if (len1 != len2) return false;

    int count[26] = {0};
    for (int i = 0; i < len1; i++) {
        count[s1[i] - 'a']++;
        count[s2[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) return false;
    }

    for (int i = 1; i < len1; i++) {
        char s1_left[35], s1_right[35];
        char s2_left[35], s2_right[35], s2_swap_l[35], s2_swap_r[35];

        strncpy(s1_left, s1, i); s1_left[i] = '\0';
        strcpy(s1_right, s1 + i);

        strncpy(s2_left, s2, i); s2_left[i] = '\0';
        strcpy(s2_right, s2 + i);

        strncpy(s2_swap_l, s2 + (len1 - i), i); s2_swap_l[i] = '\0';
        strncpy(s2_swap_r, s2, len1 - i); s2_swap_r[len1 - i] = '\0';

        if (isScramble(s1_left, s2_left) && isScramble(s1_right, s2_right)) return true;
        if (isScramble(s1_left, s2_swap_l) && isScramble(s1_right, s2_swap_r)) return true;
    }
    return false;
}