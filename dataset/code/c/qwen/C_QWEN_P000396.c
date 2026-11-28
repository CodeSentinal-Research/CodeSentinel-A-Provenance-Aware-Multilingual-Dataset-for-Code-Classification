#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    int ids[100000], active[100000];
    for(int i=0; i<n; i++) scanf("%d %d", &ids[i], &active[i]);
    int found = 0;
    for(int i=0; i<n; i++) if(active[i]) { printf("%d\n", ids[i]); found=1; }
    if(!found) printf("No Active Users\n");
    return 0;
}
