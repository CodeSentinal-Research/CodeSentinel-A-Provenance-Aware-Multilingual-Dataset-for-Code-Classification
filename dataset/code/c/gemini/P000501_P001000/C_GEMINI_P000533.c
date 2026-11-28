#include <stdio.h>
#define MAX_N 100005
int window[MAX_N];
int main() {
    int size, q;
    if (scanf("%d %d", &size, &q) == 2) {
        int head = 0, tail = 0;
        double sum = 0;
        for (int i = 0; i < q; i++) {
            int val;
            scanf("%d", &val);
            window[tail++] = val;
            sum += val;
            if (tail - head > size) {
                sum -= window[head++];
            }
            printf("%.5f\n", sum / (tail - head));
        }
    }
    return 0;
}