#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char names[100000][50]; double ratings[100000];
    for(int i=0; i<n; i++) scanf("%s %lf", names[i], &ratings[i]);
    double threshold; scanf("%lf", &threshold);
    int found = 0;
    for(int i=0; i<n; i++) if(ratings[i] >= threshold) { printf("%s %.1f\n", names[i], ratings[i]); found=1; }
    if(!found) printf("No Restaurants Found\n");
    return 0;
}
