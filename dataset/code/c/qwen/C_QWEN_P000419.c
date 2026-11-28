#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char devices[100000][50]; int status[100000];
    for(int i=0; i<n; i++) scanf("%s %d", devices[i], &status[i]);
    int found = 0;
    for(int i=0; i<n; i++) if(status[i]) { printf("%s\n", devices[i]); found=1; }
    if(!found) printf("No Online Devices\n");
    return 0;
}
