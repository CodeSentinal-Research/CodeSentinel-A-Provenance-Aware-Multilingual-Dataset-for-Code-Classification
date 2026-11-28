#include <stdlib.h>

int numRabbits(int* answers, int answersSize) {
    int count[1000] = {0};
    for (int i = 0; i < answersSize; i++) count[answers[i]]++;

    int ans = 0;
    for (int x = 0; x < 1000; x++) {
        if (count[x] > 0) {
            int groupSize = x + 1;
            int numGroups = (count[x] + groupSize - 1) / groupSize;
            ans += numGroups * groupSize;
        }
    }
    return ans;
}