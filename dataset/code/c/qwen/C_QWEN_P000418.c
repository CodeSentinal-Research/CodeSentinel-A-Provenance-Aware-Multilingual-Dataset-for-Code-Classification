#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char names[100000][50]; int join_dates[100000];
    for(int i=0; i<n; i++) scanf("%s %d", names[i], &join_dates[i]);
    int q; scanf("%d", &q);
    int found = 0;
    for(int i=0; i<n; i++) if(join_dates[i] < q) { printf("%s %d\n", names[i], join_dates[i]); found=1; }
    if(!found) printf("No Employees Found\n");
    return 0;
}
