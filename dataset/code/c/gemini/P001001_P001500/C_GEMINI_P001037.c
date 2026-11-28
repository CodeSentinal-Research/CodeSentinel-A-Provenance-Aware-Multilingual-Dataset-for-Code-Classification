#include <stdio.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int leastInterval(char* tasks, int tasksSize, int n) {
    int count[26] = {0};
    int maxFreq = 0;
    for (int i = 0; i < tasksSize; i++) {
        count[tasks[i] - 'A']++;
        if (count[tasks[i] - 'A'] > maxFreq) maxFreq = count[tasks[i] - 'A'];
    }
    int maxCount = 0;
    for (int i = 0; i < 26; i++) {
        if (count[i] == maxFreq) maxCount++;
    }
    int ans = (maxFreq - 1) * (n + 1) + maxCount;
    return MAX(tasksSize, ans);
}