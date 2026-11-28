#define MAX(a, b) ((a) > (b) ? (a) : (b))

int countLargestGroup(int n) {
    int groups[40] = {0};
    int maxSize = 0;

    for (int i = 1; i <= n; i++) {
        int s = 0, temp = i;
        while (temp > 0) {
            s += temp % 10;
            temp /= 10;
        }
        groups[s]++;
        maxSize = MAX(maxSize, groups[s]);
    }

    int count = 0;
    for (int i = 0; i < 40; i++) {
        if (groups[i] == maxSize) count++;
    }
    return count;
}