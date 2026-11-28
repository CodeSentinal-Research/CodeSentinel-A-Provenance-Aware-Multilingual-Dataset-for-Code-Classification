#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int ids[100000], qty[100000];
    for(int i=0; i<n; i++) scanf("%d %d", &ids[i], &qty[i]);
    int threshold; scanf("%d", &threshold);
    int found = 0;
    for(int i=0; i<n; i++) if(qty[i] < threshold) { printf("%d\n", ids[i]); found=1; }
    if(!found) printf("No Products Found\n");
    return 0;
}
