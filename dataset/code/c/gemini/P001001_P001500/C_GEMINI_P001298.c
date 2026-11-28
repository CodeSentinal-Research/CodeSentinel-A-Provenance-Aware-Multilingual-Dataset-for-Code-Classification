#define MAX(a, b) ((a) > (b) ? (a) : (b))

long long numberOfWeeks(int* milestones, int milestonesSize) {
    long long total = 0, maxVal = 0;
    for (int i = 0; i < milestonesSize; i++) {
        total += milestones[i];
        maxVal = MAX(maxVal, milestones[i]);
    }
    long long rest = total - maxVal;

    if (maxVal > rest + 1) {
        return 2 * rest + 1;
    }
    return total;
}