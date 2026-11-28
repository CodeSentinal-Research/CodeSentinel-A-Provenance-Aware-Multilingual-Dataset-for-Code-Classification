#define MAX(a, b) ((a) > (b) ? (a) : (b))

int minSwaps(int* data, int dataSize) {
    int totalOnes = 0;
    for (int i = 0; i < dataSize; i++) totalOnes += data[i];
    if (totalOnes <= 1) return 0;

    int curOnes = 0;
    for (int i = 0; i < totalOnes; i++) curOnes += data[i];
    int maxOnes = curOnes;

    for (int i = totalOnes; i < dataSize; i++) {
        curOnes += data[i] - data[i - totalOnes];
        maxOnes = MAX(maxOnes, curOnes);
    }
    return totalOnes - maxOnes;
}