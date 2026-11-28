#include <stdio.h>

int findLargest(int a, int b, int c) {
    int largest;
    if (a >= b) {
        if (a >= c) {
            largest = a;
        } else {
            largest = c;
        }
    } else {
        if (b >= c) {
            largest = b;
        } else {
            largest = c;
        }
    }
    return largest;
}

int main() {
    int a, b, c;
    if (scanf("%d %d %d", &a, &b, &c) == 3) {
        printf("%d\n", findLargest(a, b, c));
    }
    return 0;
}