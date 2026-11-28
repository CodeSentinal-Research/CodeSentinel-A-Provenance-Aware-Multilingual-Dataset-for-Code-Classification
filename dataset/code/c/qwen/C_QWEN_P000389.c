#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char depts[100000][50], names[100000][50];
    for(int i=0; i<n; i++) scanf("%s %s", depts[i], names[i]);
    char q[50]; scanf("%s", q);
    int found = 0;
    for(int i=0; i<n; i++) if(strcmp(depts[i], q)==0) { printf("%s %s\n", depts[i], names[i]); found=1; }
    if(!found) printf("No Records Found\n");
    return 0;
}
