#include <string.h>
#include <stdbool.h>

int minDeletions(char* s) {
    int count[26] = {0};
    for (int i = 0; s[i]; i++) count[s[i] - 'a']++;

    bool used[100005] = {false};
    int deletions = 0;

    for (int i = 0; i < 26; i++) {
        int freq = count[i];
        while (freq > 0 && used[freq]) {
            freq--;
            deletions++;
        }
        if (freq > 0) used[freq] = true;
    }
    return deletions;
}