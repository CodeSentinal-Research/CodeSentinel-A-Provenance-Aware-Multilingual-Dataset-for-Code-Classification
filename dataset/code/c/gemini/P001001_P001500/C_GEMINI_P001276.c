#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxDistToClosest(int* seats, int seatsSize) {
    int lastPerson = -1, maxDist = 0;

    for (int i = 0; i < seatsSize; i++) {
        if (seats[i] == 1) {
            if (lastPerson == -1) {
                maxDist = i;
            } else {
                maxDist = MAX(maxDist, (i - lastPerson) / 2);
            }
            lastPerson = i;
        }
    }
    maxDist = MAX(maxDist, seatsSize - 1 - lastPerson);
    return maxDist;
}