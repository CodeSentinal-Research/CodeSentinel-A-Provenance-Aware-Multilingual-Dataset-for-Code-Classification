#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char slots[100000][20]; int vacant[100000];
    for(int i=0; i<n; i++) scanf("%s %d", slots[i], &vacant[i]);
    int found = 0;
    for(int i=0; i<n; i++) if(vacant[i]) { printf("%s\n", slots[i]); found=1; }
    if(!found) printf("No Vacant Slots\n");
    return 0;
}
