#define MIN(a, b) ((a) < (b) ? (a) : (b))

int checkDomino(int x, int* tops, int* bottoms, int n) {
    int rotA = 0, rotB = 0;
    for (int i = 0; i < n; i++) {
        if (tops[i] != x && bottoms[i] != x) return -1;
        else if (tops[i] != x) rotA++;
        else if (bottoms[i] != x) rotB++;
    }
    return MIN(rotA, rotB);
}

int minDominoRotations(int* tops, int topsSize, int* bottoms, int bottomsSize) {
    int rotations = checkDomino(tops[0], tops, bottoms, topsSize);
    if (rotations != -1 || tops[0] == bottoms[0]) return rotations;
    return checkDomino(bottoms[0], tops, bottoms, topsSize);
}