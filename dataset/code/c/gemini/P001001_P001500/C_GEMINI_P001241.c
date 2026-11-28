int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int totalGas = 0, totalCost = 0;
    for (int i = 0; i < gasSize; i++) {
        totalGas += gas[i];
        totalCost += cost[i];
    }
    if (totalGas < totalCost) return -1;

    int total = 0, start = 0;
    for (int i = 0; i < gasSize; i++) {
        total += gas[i] - cost[i];
        if (total < 0) {
            total = 0;
            start = i + 1;
        }
    }
    return start;
}