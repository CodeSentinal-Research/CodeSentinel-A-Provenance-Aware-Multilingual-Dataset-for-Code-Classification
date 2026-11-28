#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    int ids[100000], available[100000];
    for(int i=0; i<n; i++) scanf("%d %d", &ids[i], &available[i]);
    int found = 0;
    for(int i=0; i<n; i++) if(available[i]) { printf("%d\n", ids[i]); found=1; }
    if(!found) printf("No Rooms Available\n");
    return 0;
}
