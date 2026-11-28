#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    int ids[100000]; char status[100000][20];
    for(int i=0; i<n; i++) scanf("%d %s", &ids[i], status[i]);
    char q[20]; scanf("%s", q);
    int found = 0;
    for(int i=0; i<n; i++) if(strcmp(status[i], q)==0) { printf("%d %s\n", ids[i], status[i]); found=1; }
    if(!found) printf("No Orders Found\n");
    return 0;
}
