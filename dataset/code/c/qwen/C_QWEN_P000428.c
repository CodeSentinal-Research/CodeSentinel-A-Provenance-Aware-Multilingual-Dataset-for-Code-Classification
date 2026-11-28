#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char events[100000][50]; int dates[100000];
    for(int i=0; i<n; i++) scanf("%s %d", events[i], &dates[i]);
    int q; scanf("%d", &q);
    int found = 0;
    for(int i=0; i<n; i++) if(dates[i] == q) { printf("%s %d\n", events[i], dates[i]); found=1; }
    if(!found) printf("No Events Found\n");
    return 0;
}
