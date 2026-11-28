#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char names[100000][50]; int sals[100000];
    for(int i=0; i<n; i++) scanf("%s %d", names[i], &sals[i]);
    int min_s, max_s; scanf("%d %d", &min_s, &max_s);
    int found = 0;
    for(int i=0; i<n; i++) if(sals[i]>=min_s && sals[i]<=max_s) { printf("%s %d\n", names[i], sals[i]); found=1; }
    if(!found) printf("No Employees Found\n");
    return 0;
}
