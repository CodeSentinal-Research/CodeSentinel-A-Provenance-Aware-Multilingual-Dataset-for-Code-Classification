#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxDistToClosest(int* seats, int seatsSize) {
    int prev = -1, maxDist = 0;

    for (int i = 0; i < seatsSize; i++) {
        if (seats[i] == 1) {
            if (prev == -1) maxDist = i;
            else maxDist = MAX(maxDist, (i - prev) / 2);
            prev = i;
        }
    }
    return MAX(maxDist, seatsSize - 1 - prev);
}