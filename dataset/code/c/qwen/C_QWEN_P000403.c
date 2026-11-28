#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char trains[100000][20], stations[100000][50];
    for(int i=0; i<n; i++) scanf("%s %s", trains[i], stations[i]);
    char q[50]; scanf("%s", q);
    int found = 0;
    for(int i=0; i<n; i++) if(strcmp(stations[i], q)==0) { printf("%s %s\n", trains[i], stations[i]); found=1; }
    if(!found) printf("No Trains Found\n");
    return 0;
}
