int furthestBuilding(int* heights, int heightsSize, int bricks, int ladders) {
    int pq[heightsSize + 1];
    int pSize = 0;

    for (int i = 0; i < heightsSize - 1; i++) {
        int diff = heights[i + 1] - heights[i];
        if (diff > 0) {
            pq[pSize++] = diff;
            if (pSize > ladders) {
                int minIdx = 0;
                for (int j = 1; j < pSize; j++) {
                    if (pq[j] < pq[minIdx]) minIdx = j;
                }
                bricks -= pq[minIdx];
                pq[minIdx] = pq[--pSize];
            }
            if (bricks < 0) return i;
        }
    }
    return heightsSize - 1;
}