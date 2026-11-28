#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char flights[100000][20], dests[100000][50];
    for(int i=0; i<n; i++) scanf("%s %s", flights[i], dests[i]);
    char q[20]; scanf("%s", q);
    int found = 0;
    for(int i=0; i<n; i++) if(strcmp(flights[i], q)==0) { printf("%s %s\n", flights[i], dests[i]); found=1; break; }
    if(!found) printf("Flight Not Found\n");
    return 0;
}
