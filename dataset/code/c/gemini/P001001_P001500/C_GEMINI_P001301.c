#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Meeting;

int cmpMeeting(const void* a, const void* b) {
    return ((Meeting*)a)->end - ((Meeting*)b)->end;
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        Meeting* meetings = (Meeting*)malloc(n * sizeof(Meeting));
        for (int i = 0; i < n; i++) scanf("%d", &meetings[i].start);
        for (int i = 0; i < n; i++) scanf("%d", &meetings[i].end);

        qsort(meetings, n, sizeof(Meeting), cmpMeeting);
        int count = 0, lastEnd = -1;

        for (int i = 0; i < n; i++) {
            if (meetings[i].start > lastEnd) {
                count++;
                lastEnd = meetings[i].end;
            }
        }
        printf("%d\n", count);
        free(meetings);
    }
    return 0;
}