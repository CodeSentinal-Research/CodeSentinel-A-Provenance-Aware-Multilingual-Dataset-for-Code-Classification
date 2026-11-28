#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char names[100000][50], depts[100000][50]; int active[100000];
    for(int i=0; i<n; i++) scanf("%s %s %d", names[i], depts[i], &active[i]);
    char q[50]; scanf("%s", q);
    int found = 0;
    for(int i=0; i<n; i++) if(strcmp(depts[i], q)==0 && active[i]) { printf("%s %s\n", names[i], depts[i]); found=1; }
    if(!found) printf("No Employees Found\n");
    return 0;
}
