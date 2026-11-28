#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)b - *(int*)a; }
int main() {
    int n; scanf("%d", &n);
    char tasks[n+1]; scanf("%s", tasks);
    int k; scanf("%d", &k);
    int count[256] = {0};
    for(int i=0; tasks[i]; i++) count[tasks[i]]++;
    int freq[256]; int sz = 0;
    for(int i=0; i<256; i++) if(count[i]) freq[sz++] = count[i];
    qsort(freq, sz, sizeof(int), cmp);
    int time = 0;
    while(freq[0] > 0) {
        int cycles = k + 1;
        for(int i=0; i<sz && cycles > 0 && freq[i] > 0; i++) { freq[i]--; cycles--; time++; }
        if(cycles > 0 && freq[0] > 0) time += cycles;
        qsort(freq, sz, sizeof(int), cmp);
    }
    printf("%d\n", time);
    return 0;
}
